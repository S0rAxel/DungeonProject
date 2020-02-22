// Fill out your copyright notice in the Description page of Project Settings.


#include "Potion.h"
#include "Engine.h"
#include "DungeonProjectCharacter.h"

void APotion::Interact(ADungeonProjectCharacter* Character)
{
	if (Character != nullptr)
	{
		Character->potionCount++;
		Destroy();
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(0, 5.0f, FColor::Red, "Pointer is NULL");
	}
	
}
