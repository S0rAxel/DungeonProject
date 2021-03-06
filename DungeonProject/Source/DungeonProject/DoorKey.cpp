// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorKey.h"
#include "Door.h"
#include "Engine.h"
#include "Components/StaticMeshComponent.h"

void ADoorKey::Interact(ADungeonProjectCharacter* Character)
{
	Super::Interact(Character);

	if (Character != nullptr)
	{
		if (Doors.Num() > 0)
		{
			for (size_t i = 0; i < Doors.Num(); i++)
			{
				if (Doors[i] != nullptr)
				{
					Doors[i]->IsLocked = false;
				}
			}
		}

		Destroy();
	}
}

void ADoorKey::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MeshComponent->AddLocalRotation(FRotator(0.f, DeltaTime * 200.f, 0.f));
	float hoverValue = FMath::Clamp(FMath::Sin(UGameplayStatics::GetRealTimeSeconds(GetWorld()) * 5.f), -1.f, 1.f);
	MeshComponent->AddRelativeLocation(FVector(0.f, 0.f, hoverValue));
}
