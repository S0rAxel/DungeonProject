// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "Door.generated.h"

/**
 * 
 */
UCLASS()
class DUNGEONPROJECT_API ADoor : public AInteractable
{
	GENERATED_BODY()

public:

    UPROPERTY(EditDefaultsOnly) class USoundCue* LockDoorCue;

    bool IsLocked = true;
    
protected:
    bool IsOpen = false;

protected:
    void NotifyActorBeginOverlap(AActor* OtherActor) override;

};
