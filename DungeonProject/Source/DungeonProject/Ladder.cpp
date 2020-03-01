// Fill out your copyright notice in the Description page of Project Settings.


#include "Ladder.h"
#include "Engine.h"
#include "DungeonProjectCharacter.h"
#include "Components/BoxComponent.h"

ALadder::ALadder()
{
	BoxComponent->SetBoxExtent(FVector(200.f, 200.f, 200.f));
}

void ALadder::Interact(ADungeonProjectCharacter* Character)
{
	if (Character != nullptr)
	{
		UGameplayStatics::OpenLevel(GetWorld(), "LevelName");
	}
}
