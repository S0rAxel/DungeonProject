// Fill out your copyright notice in the Description page of Project Settings.


#include "Campfire.h"
#include "DungeonProjectCharacter.h"
#include "Components/StaticMeshComponent.h"
#include "Components/PointLightComponent.h"
#include "Particles/ParticleSystemComponent.h"

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

void ACampfire::Interact(ADungeonProjectCharacter* Character)
{
	Super::Interact(Character);

	if (Character != nullptr)
	{
		Character->Heal(Character->maxHealth);
	}
}
