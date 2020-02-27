// Fill out your copyright notice in the Description page of Project Settings.


#include "Potion.h"
#include "Engine.h"
#include "DungeonProjectCharacter.h"

void APotion::Interact(ADungeonProjectCharacter* Character)
{
	Super::Interact(Character);

	if (Character != nullptr)
	{
		Character->potionCount++;
		Destroy();
	}
}

void APotion::Tick(float DeltaTime) 
{
	Super::Tick(DeltaTime);

	MeshComponent->AddLocalRotation(FRotator(0.f, DeltaTime * 100.f, 0.f));
	float hoverValue = FMath::Clamp(FMath::Sin(UGameplayStatics::GetRealTimeSeconds(GetWorld()) * 5.f), -1.f, 1.f);
	MeshComponent->AddRelativeLocation(FVector(0.f, 0.f, hoverValue));
}
