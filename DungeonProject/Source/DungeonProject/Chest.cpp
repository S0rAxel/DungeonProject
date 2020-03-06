// Fill out your copyright notice in the Description page of Project Settings.


#include "Chest.h"
#include "Coin.h"
#include "InteractableWidget.h"
#include "DungeonProjectCharacter.h"
#include "Components/BoxComponent.h"
#include "Components/SceneComponent.h"
#include "Components/WidgetComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

AChest::AChest()
{
	PivotPoint = CreateAbstractDefaultSubobject<USceneComponent>(TEXT("PivotPoint"));
	PivotPoint->AttachToComponent(MeshComponent, FAttachmentTransformRules::KeepRelativeTransform);

	MeshChestTop = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ChestTop"));
	MeshChestTop->AttachToComponent(PivotPoint, FAttachmentTransformRules::KeepRelativeTransform);

	SpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("SpawnPoint"));
	SpawnPoint->AttachToComponent(BoxComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

void AChest::Interact(ADungeonProjectCharacter* Character)
{
	if (!IsOpen)
	{
		IsOpen = true;

		Super::Interact(Character);

		Cast<UInteractableWidget>(WidgetComponent->GetUserWidgetObject())->SetVisibility(ESlateVisibility::Hidden);

		FLatentActionInfo actionInfo;
		actionInfo.CallbackTarget = this;
		actionInfo.ExecutionFunction = "SpawnCoins";
		actionInfo.Linkage = 0;
		UKismetSystemLibrary::MoveComponentTo(PivotPoint, PivotPoint->GetRelativeLocation(), FRotator(0.f, 0.f, -70.f), false, true, 0.5f, false, EMoveComponentAction::Move, actionInfo);
	}
}

void AChest::SpawnCoins()
{
	if (CoinBlueprint != nullptr)
	{
		for (size_t i = 0; i < CoinsInChest; i++)
		{
			FActorSpawnParameters spawnParameters;
			ACoin* coinReference = GetWorld()->SpawnActor<ACoin>(CoinBlueprint, SpawnPoint->GetComponentLocation(), UKismetMathLibrary::RandomRotator());
			coinReference->MeshComponent->SetLinearDamping(10.f);
			coinReference->MeshComponent->SetAngularDamping(10.f);

			coinReference->MeshComponent->AddImpulse(MeshComponent->GetRightVector() * FVector(5000.f));
		}
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
			}
		}
	}
}

