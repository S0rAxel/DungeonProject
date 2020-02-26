// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorKey.h"
#include "Door.h"
#include "Engine.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/WidgetComponent.h"
#include "Kismet/KismetMathLibrary.h"

ADoorKey::ADoorKey() 
{
	BoxComponent->SetBoxExtent(FVector(200.f, 200.f, 100.f));

	MeshComponent->SetRelativeLocation(FVector(0.f, 0.f, -40.f));

	WidgetComponent->SetRelativeLocation(FVector(0.f, 0.f, 150.f));
}

void ADoorKey::Interact(ADungeonProjectCharacter* Character)
{
	if (Character != nullptr)
	{
		if (Door != nullptr)
		{
			Door->IsLocked = false;
			Destroy();
		}
	}
}

void ADoorKey::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MeshComponent->AddLocalRotation(FRotator(0.f, DeltaTime * 200.f, 0.f));
	float hoverValue = FMath::Clamp(FMath::Sin(UGameplayStatics::GetRealTimeSeconds(GetWorld()) * 5.f), -1.f, 1.f);
	MeshComponent->AddRelativeLocation(FVector(0.f, 0.f, hoverValue));
}
