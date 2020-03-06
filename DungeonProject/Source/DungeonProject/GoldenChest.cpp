// Fill out your copyright notice in the Description page of Project Settings.


#include "GoldenChest.h"
#include "DoorKey.h"
#include "InteractableWidget.h"
#include "DungeonProjectCharacter.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/SceneComponent.h"
#include "Components/WidgetComponent.h"
#include "Components/StaticMeshComponent.h"

AGoldenChest::AGoldenChest()
{
	PivotPoint = CreateAbstractDefaultSubobject<USceneComponent>(TEXT("PivotPoint"));
	PivotPoint->AttachToComponent(MeshComponent, FAttachmentTransformRules::KeepRelativeTransform);

	MeshChestTop = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ChestTop"));
	MeshChestTop->AttachToComponent(PivotPoint, FAttachmentTransformRules::KeepRelativeTransform);
}

void AGoldenChest::Interact(ADungeonProjectCharacter* Character)
{
	if (!IsOpen)
	{
		IsOpen = true;

		Super::Interact(Character);

		Cast<UInteractableWidget>(WidgetComponent->GetUserWidgetObject())->SetVisibility(ESlateVisibility::Hidden);

		FLatentActionInfo actionInfo;
		actionInfo.CallbackTarget = this;
		actionInfo.ExecutionFunction = "SpawnObject";
		actionInfo.Linkage = 0;
		UKismetSystemLibrary::MoveComponentTo(PivotPoint, PivotPoint->GetRelativeLocation(), FRotator(0.f, 0.f, -70.f), false, true, 0.5f, false, EMoveComponentAction::Move, actionInfo);
	}
}

void AGoldenChest::SpawnObject()
{
	if (InteractableBlueprint != nullptr)
	{
		FActorSpawnParameters spawnParameters;
		auto objectReference = GetWorld()->SpawnActor<AInteractable>(InteractableBlueprint, GetTransform(), spawnParameters);

		if (Cast<ADoorKey>(objectReference))
		{
			if (Doors.Num() > 0)
			{
				Cast<ADoorKey>(objectReference)->Doors = this->Doors;
			}
		}
	}
}

void AGoldenChest::NotifyActorBeginOverlap(AActor* OtherActor)
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
