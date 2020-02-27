// Fill out your copyright notice in the Description page of Project Settings.


#include "Coin.h"
#include "Engine.h"
#include "DungeonProjectCharacter.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Sound/SoundCue.h"
// Sets default values
ACoin::ACoin()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = MeshComponent;

	MeshComponent->SetRelativeScale3D(FVector(0.7f));
	MeshComponent->SetSimulatePhysics(true);
	MeshComponent->SetMassOverrideInKg(NAME_None, 1.f);

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollider"));
	SphereComponent->AttachToComponent(MeshComponent, FAttachmentTransformRules::KeepRelativeTransform);
	SphereComponent->SetSphereRadius(60.f);
}

// Called when the game starts or when spawned
void ACoin::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACoin::NotifyActorBeginOverlap(AActor* OtherActor)
{
	auto character = Cast<ADungeonProjectCharacter>(OtherActor);
	if (character != nullptr)
	{
		character->goldCount++;

		if (SoundCue != nullptr)
		{
			UGameplayStatics::PlaySoundAtLocation(this, SoundCue, GetActorLocation());
		}

		Destroy();
	}
}

// Called every frame
void ACoin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

