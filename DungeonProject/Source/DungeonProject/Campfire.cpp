// Fill out your copyright notice in the Description page of Project Settings.


#include "Campfire.h"
#include "DungeonProjectCharacter.h"
#include "Components/StaticMeshComponent.h"
#include "Components/PointLightComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Engine.h"

ACampfire::ACampfire()
{
	FireParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("FireParticles"));
	FireParticleSystem->AttachToComponent(MeshComponent, FAttachmentTransformRules::KeepRelativeTransform);
	FireParticleSystem->SetRelativeLocation(FVector(0.f, 0.f, 100.f));

	SFXParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("SFXParticles"));
	SFXParticleSystem->AttachToComponent(MeshComponent, FAttachmentTransformRules::KeepRelativeTransform);
	SFXParticleSystem->SetRelativeLocation(FVector(0.f, 0.f, 100.f));

	PointLightComponent = CreateAbstractDefaultSubobject<UPointLightComponent>(TEXT("PointLight"));
	PointLightComponent->AttachToComponent(MeshComponent, FAttachmentTransformRules::KeepRelativeTransform);
	PointLightComponent->SetRelativeLocation(FVector(0.f, 0.f, 350.f));

}

void ACampfire::BeginPlay()
{
	Super::BeginPlay();

	if (FireParticleSystem != nullptr)
	{
		FireParticleSystem->SetActive(false);
		FireParticleSystem->SetEmitterEnable(TEXT("GreenParticleEmitter"), true);
	}
	if (SFXParticleSystem != nullptr)
	{
		SFXParticleSystem->SetActive(false);
	}
}

void ACampfire::Interact(ADungeonProjectCharacter* Character)
{
	Super::Interact(Character);

	//Heal
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::White, FString::FromInt(Character->health));
	if (Character != nullptr)
	{
		Character->health = Character->maxHealth;
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::White, FString::FromInt(Character->health));
	}

	//Play heal particle effect
	if (SFXParticleSystem != nullptr && FireParticleSystem != nullptr)
	{
		if (FireParticleSystem->IsActive())
		{
			SFXParticleSystem->SetActive(true);
		}
		else
		{
			FireParticleSystem->SetActive(true);
		}
	}


	//Destroy existing enemies and spawn new ones
	if (!EnemySpawnPoints.Contains(nullptr))
	{

	}
}
