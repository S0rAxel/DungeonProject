// Fill out your copyright notice in the Description page of Project Settings.


#include "Campfire.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/PointLightComponent.h"
#include "Components/BoxComponent.h"
#include "Components/WidgetComponent.h"
#include "DungeonProjectCharacter.h"

ACampfire::ACampfire() 
{
	BoxComponent->SetBoxExtent(FVector(400.f, 400.f, 150.f));

	MeshComponent->SetRelativeScale3D(FVector(0.75f, 0.75f, 0.5f));
	MeshComponent->SetRelativeLocation(FVector(0.f, 0.f, -150.f));

	WidgetComponent->SetRelativeLocation(FVector(0.f, 0.f, 150.f));

	FireParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("FireParticles"));
	FireParticleSystem->AttachToComponent(BoxComponent, FAttachmentTransformRules::KeepRelativeTransform);
	FireParticleSystem->SetRelativeLocation(FVector(0.f, 0.f, -50.f));

	SFXParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("SFXParticles"));
	SFXParticleSystem->AttachToComponent(BoxComponent, FAttachmentTransformRules::KeepRelativeTransform);
	SFXParticleSystem->SetRelativeLocation(FVector(0.f, 0.f, -50.f));

	PointLightComponent = CreateAbstractDefaultSubobject<UPointLightComponent>(TEXT("PointLight"));
	PointLightComponent->AttachToComponent(BoxComponent, FAttachmentTransformRules::KeepRelativeTransform);
	PointLightComponent->SetRelativeLocation(FVector(0.f, 0.f, 30.f));
}

void ACampfire::Interact(ADungeonProjectCharacter* Character)
{
	Super::Interact(Character);

	if (Character != nullptr)
	{
		Character->Heal(Character->maxHealth);
	}
}
