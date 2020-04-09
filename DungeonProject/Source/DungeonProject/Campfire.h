// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "Engine/TargetPoint.h"
#include "Campfire.generated.h"

/**
 * 
 */
UCLASS()
class DUNGEONPROJECT_API ACampfire : public AInteractable
{
	GENERATED_BODY()

public:
	ACampfire();

	UPROPERTY(VisibleAnywhere) class UParticleSystemComponent* FireParticleSystem;

	UPROPERTY(VisibleAnywhere) class UParticleSystemComponent* SFXParticleSystem;

	UPROPERTY(VisibleAnywhere) class UPointLightComponent* PointLightComponent;

	UPROPERTY(VisibleAnywhere) TArray<ATargetPoint*> EnemySpawnPoints;

protected:
	virtual void BeginPlay() override;
	void Interact(class ADungeonProjectCharacter* Character) override;
};
