// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Coin.generated.h"

UCLASS()
class DUNGEONPROJECT_API ACoin : public AActor
{
	GENERATED_BODY()
	
public:	
	ACoin();

	UPROPERTY(VisibleAnywhere) UStaticMeshComponent* MeshComponent;

	UPROPERTY(VisibleAnywhere) class USphereComponent* SphereComponent;

	UPROPERTY(EditAnywhere) class USoundCue* SoundCue;

protected:
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
};
