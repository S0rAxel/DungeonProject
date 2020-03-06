// Fill out your copyright notice in the Description page of Project Settings.


#include "Ladder.h"
#include "Kismet/GameplayStatics.h"
#include "DungeonProjectCharacter.h"

void ALadder::Interact(ADungeonProjectCharacter* Character)
{
	if (Character != nullptr)
	{
		if (LevelToLoad != "")
		{
			UGameplayStatics::OpenLevel(this, LevelToLoad);
		}
	}
}
