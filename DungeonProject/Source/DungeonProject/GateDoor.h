// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Door.h"
#include "GateDoor.generated.h"

/**
 * 
 */
UCLASS()
class DUNGEONPROJECT_API AGateDoor : public ADoor
{
	GENERATED_BODY()
	
public:
	void OpenGate();

private:
	void Interact(class ADungeonProjectCharacter* Character) override;
	void NotifyActorBeginOverlap(AActor* OtherActor) override;
	void NotifyActorEndOverlap(AActor* OtherActor) override;
};
