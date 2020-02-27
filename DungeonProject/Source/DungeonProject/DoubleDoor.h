// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Door.h"
#include "DoubleDoor.generated.h"

/**
 * 
 */
UCLASS()
class DUNGEONPROJECT_API ADoubleDoor : public ADoor
{
	GENERATED_BODY()
	
public:
	ADoubleDoor();

	UPROPERTY(VisibleAnywhere) class UStaticMeshComponent* SecondDoor;

protected:
	void Interact(class ADungeonProjectCharacter* Character) override;
	
};
