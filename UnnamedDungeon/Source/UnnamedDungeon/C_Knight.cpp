// Fill out your copyright notice in the Description page of Project Settings.


#include "C_Knight.h"
#include "Components/InputComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AC_Knight::AC_Knight()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FloatingCharacterMovement = CreateDefaultSubobject<UFloatingPawnMovement>("CharacterMovement");

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");

	SpringArm = CreateDefaultSubobject<USpringArmComponent>("CameraSpringArm");
	SpringArm->SetupAttachment(StaticMesh);
	SpringArm->TargetArmLength = 200.0f;
	SpringArm->SetRelativeLocation(FVector(0.0f, 0.0f, 500.0f));

	SetRootComponent(StaticMesh);
}

// Called when the game starts or when spawned
void AC_Knight::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AC_Knight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AC_Knight::MoveForward(float amount) 
{
	FloatingCharacterMovement->AddInputVector(GetActorForwardVector() * amount);
}

void AC_Knight::MoveRight(float amount) 
{
	FloatingCharacterMovement->AddInputVector(GetActorRightVector() * amount);
}

// Called to bind functionality to input
void AC_Knight::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AC_Knight::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AC_Knight::MoveRight);
}

