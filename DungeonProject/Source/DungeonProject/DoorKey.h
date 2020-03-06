// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "DoorKey.generated.h"

/**
 * 
 */
UCLASS()
class DUNGEONPROJECT_API ADoorKey : public AInteractable
{
	GENERATED_BODY()

public:
    UPROPERTY(EditInstanceOnly, meta = (DisplayPriority = 1)) TArray<class ADoor*> Doors;

protected:
    void Interact(class ADungeonProjectCharacter* Character) override;
    void Tick(float DeltaTime) override;
};
