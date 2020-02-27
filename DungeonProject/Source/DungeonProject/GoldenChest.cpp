// Fill out your copyright notice in the Description page of Project Settings.


#include "GoldenChest.h"
#include "Engine.h"
#include "InteractableWidget.h"
#include "DungeonProjectCharacter.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Components/SceneComponent.h"
#include "Components/WidgetComponent.h"

AGoldenChest::AGoldenChest()
{
	BoxComponent->SetBoxExtent(FVector(200.f, 200.f, 100.f));

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
		GetWorld()->SpawnActor<AInteractable>(InteractableBlueprint, GetTransform(), spawnParameters);
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
				InteractText = "(E) OPEN";
			}
		}
	}
}
