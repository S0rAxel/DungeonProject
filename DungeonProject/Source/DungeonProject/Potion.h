// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "Potion.generated.h"

/**
 * 
 */
UCLASS()
class DUNGEONPROJECT_API APotion : public AInteractable
{
	GENERATED_BODY()
	
protected:
	void Interact(class ADungeonProjectCharacter* Character) override;
};
