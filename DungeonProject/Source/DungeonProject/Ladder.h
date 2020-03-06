// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "Ladder.generated.h"

/**
 * 
 */
UCLASS()
class DUNGEONPROJECT_API ALadder : public AInteractable
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditInstanceOnly, meta = (DisplayPriority = 1)) FName LevelToLoad;

protected:
	void Interact(class ADungeonProjectCharacter* Character) override;

};
