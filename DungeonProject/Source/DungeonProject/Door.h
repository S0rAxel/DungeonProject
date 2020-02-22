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
    ADoor();

    bool IsLocked = true;
    
private:
    bool IsOpen = false;

protected:
    void Interact(class ADungeonProjectCharacter* Character) override;
    void NotifyActorBeginOverlap(AActor* OtherActor) override;

};
