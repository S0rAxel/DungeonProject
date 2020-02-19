// Fill out your copyright notice in the Description page of Project Settings.


#include "Potion.h"
#include "Engine.h"
#include "DungeonProjectCharacter.h"

void APotion::Interact()
{
	Character = Cast<ADungeonProjectCharacter>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	GEngine->AddOnScreenDebugMessage(1, 5.0f, FColor::Blue, "Interact with Object");

	if (Character != nullptr)
		Character->potionCount++;
	else
		GEngine->AddOnScreenDebugMessage(2, 5.0f, FColor::Red, "Pointer is NULL");

	//Destroy();

}
