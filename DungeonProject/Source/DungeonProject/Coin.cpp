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
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = MeshComponent;

	MeshComponent->SetRelativeScale3D(FVector(0.7f));
	MeshComponent->SetSimulatePhysics(true);
	MeshComponent->SetMassOverrideInKg(NAME_None, 1.f);

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollider"));
	SphereComponent->AttachToComponent(MeshComponent, FAttachmentTransformRules::KeepRelativeTransform);
	SphereComponent->SetSphereRadius(60.f);
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
