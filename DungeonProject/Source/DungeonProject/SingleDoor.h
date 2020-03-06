// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Door.h"
#include "SingleDoor.generated.h"

/**
 * 
 */
UCLASS()
class DUNGEONPROJECT_API ASingleDoor : public ADoor
{
	GENERATED_BODY()

protected:
    void Interact(class ADungeonProjectCharacter* Character) override;
};
