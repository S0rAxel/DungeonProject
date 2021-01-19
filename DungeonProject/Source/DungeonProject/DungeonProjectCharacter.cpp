// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "DungeonProjectCharacter.h"
#include "Engine.h"
#include "Interactable.h"
#include "CharacterWidget.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Components/InputComponent.h"
#include "Components/WidgetComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"

//////////////////////////////////////////////////////////////////////////
// ADungeonProjectCharacter

ADungeonProjectCharacter::ADungeonProjectCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	SwordMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SwordMesh"));
	SwordMesh->AttachToComponent(Mesh, FAttachmentTransformRules::KeepRelativeTransform, "RightHand");

	SwordCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("SwordCollision"));
	SwordCollision->AttachToComponent(SwordMesh, FAttachmentTransformRules::KeepRelativeTransform);

	/* Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character)
	 are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++) */
}

void ADungeonProjectCharacter::BeginPlay()
{
	Super::BeginPlay();

#pragma region HUD
	auto widget = CreateWidget<UCharacterWidget>(UGameplayStatics::GetPlayerController(this, 0), CharacterHUD);
	widget->Character = this;
	widget->AddToViewport();
#pragma endregion
}

void ADungeonProjectCharacter::Interact()
{
	FVector spherePosition = GetActorLocation();
	float sphereRadius = 84.f;
	TArray<TEnumAsByte<EObjectTypeQuery>> query;
	TArray<AActor*> actorToIgnore;
	TArray<AActor*> outActors;
	UKismetSystemLibrary::SphereOverlapActors(this, spherePosition, sphereRadius, query, AInteractable::StaticClass(), actorToIgnore, outActors);

	for (auto actor : outActors)
	{
		auto interactable = Cast<AInteractable>(actor);
		if (interactable != nullptr)
		{
			interactable->Interact(this);
		}
	}
}

void ADungeonProjectCharacter::TakeDamage(int damageAmount)
{
	health -= damageAmount;

	if (health <= 0)
	{
		Death();
	}
}

void ADungeonProjectCharacter::Death()
{
	IsDeath = true;
	IsLockedOn = false;
	GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Red, "YOU ARE DEAD");
	GetCharacterMovement()->DisableMovement();

	if (DeathMontage != nullptr)
	{
		DeathMontage->bEnableAutoBlendOut = false;
		PlayAnimMontage(DeathMontage);
	}

	UGameplayStatics::GetPlayerController(this, 0)->bShowMouseCursor = true;
}

void ADungeonProjectCharacter::LockOn()
{

}

void ADungeonProjectCharacter::UsePotion()
{
	if (potionCount > 0)
	{
		if (health < maxHealth)
		{
			health += 2;
			potionCount--;
			if (health > maxHealth)
			{
				health = maxHealth;
			}
		}
	}
}

void ADungeonProjectCharacter::LightAttack()
{
}

void ADungeonProjectCharacter::HeavyAttack()
{
}

void ADungeonProjectCharacter::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if (Cast<AKillZVolume>(OtherActor))
	{
		Death();
	}
}

void ADungeonProjectCharacter::Tick(float DeltaTime)
{

}

#pragma region Input & Movement

void ADungeonProjectCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Roll", IE_Pressed, this, &ADungeonProjectCharacter::Roll);
	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &ADungeonProjectCharacter::Interact);
	PlayerInputComponent->BindAction("LockOn", IE_Pressed, this, &ADungeonProjectCharacter::Interact);
	PlayerInputComponent->BindAction("UsePotion", IE_Pressed, this, &ADungeonProjectCharacter::UsePotion);
	PlayerInputComponent->BindAction("LightAttack", IE_Pressed, this, &ADungeonProjectCharacter::LightAttack);
	PlayerInputComponent->BindAction("HeavyAttack", IE_Pressed, this, &ADungeonProjectCharacter::HeavyAttack);

	PlayerInputComponent->BindAxis("MoveForward", this, &ADungeonProjectCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ADungeonProjectCharacter::MoveRight);
}

void ADungeonProjectCharacter::Roll()
{
	if (!IsRolling)
	{
		if (UKismetMathLibrary::Dot_VectorVector(GetActorForwardVector(), GetVelocity()) != 0.f)
		{
			IsRolling = true;
			if (!Mesh->GetAnimInstance()->Montage_IsPlaying(RollMontage))
			{
				PlayAnimMontage(RollMontage);
				IsRolling = false;
			}
			else
			{
				IsRolling = false;
			}
		}
	}
}

void ADungeonProjectCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void ADungeonProjectCharacter::MoveRight(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

#pragma endregion
