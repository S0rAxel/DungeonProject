// Fill out your copyright notice in the Description page of Project Settings.


#include "Chest.h"
#include "Engine.h"
#include "Coin.h"
#include "InteractableWidget.h"
#include "DungeonProjectCharacter.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Components/SceneComponent.h"
#include "Components/WidgetComponent.h"
#include "Kismet/KismetMathLibrary.h"

AChest::AChest() 
{
	BoxComponent->SetBoxExtent(FVector(200.f, 200.f, 100.f));

	PivotPoint = CreateAbstractDefaultSubobject<USceneComponent>(TEXT("PivotPoint"));
	PivotPoint->AttachToComponent(MeshComponent, FAttachmentTransformRules::KeepRelativeTransform);
	
	MeshChestTop = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ChestTop"));
	MeshChestTop->AttachToComponent(PivotPoint, FAttachmentTransformRules::KeepRelativeTransform);
	
	SpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("SpawnPoint"));
	SpawnPoint->AttachToComponent(BoxComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

void AChest::Interact(ADungeonProjectCharacter* Character)
{
	IsOpen = true;
	Cast<UInteractableWidget>(WidgetComponent->GetUserWidgetObject())->SetVisibility(ESlateVisibility::Hidden);

	for (size_t i = 0; i < CoinsInChest; i++)
	{
		if (CoinBlueprint)
		{
			FActorSpawnParameters spawnParameters;

			ACoin* CoinReference = GetWorld()->SpawnActor<ACoin>(CoinBlueprint, GetTransform(), spawnParameters);
		}
		//GetWorld()->SpawnActor<CoinObject>(SpawnPoint->GetComponentLocation(), UKismetMathLibrary::RandomRotator());
		//Cast<UPrimitiveComponent>(spawnedCoin)->AddForce(SpawnPoint->GetForwardVector() * 2000.f);
	}
}

void AChest::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if (OtherActor != nullptr && Cast<ADungeonProjectCharacter>(OtherActor))
	{
		if (WidgetComponent->GetUserWidgetObject() != nullptr)
		{
			if (IsOpen)
			{
				Cast<UInteractableWidget>(WidgetComponent->GetUserWidgetObject())->SetVisibility(ESlateVisibility::Hidden);
			}
			else
			{
				Cast<UInteractableWidget>(WidgetComponent->GetUserWidgetObject())->SetVisibility(ESlateVisibility::Visible);
				InteractText = "(E) OPEN";
			}
		}
	}
}
