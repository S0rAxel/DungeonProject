// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"
#include "InteractableWidget.h"
#include "Components/StaticMeshComponent.h"
#include "Components/WidgetComponent.h"
#include "Components/BoxComponent.h"
#include "DungeonProjectCharacter.h"

ADoor::ADoor() 
{
	BoxComponent->SetBoxExtent(FVector(200.f, 200.f, 100.f));

	MeshComponent->SetRelativeLocation(FVector(-90.f, 0.f, -100.f));

	WidgetComponent->SetRelativeLocation(FVector(0.f, 100.f, 250.f));
}

void ADoor::Interact(ADungeonProjectCharacter* Character)
{
	if (IsLocked)
	{
		InteractText = "DOOR'S LOCKED...";
	}
	else
	{
		if (!IsOpen)
		{
			IsOpen = true;
			InteractText = "";
		}
	}
}

void ADoor::NotifyActorBeginOverlap(AActor* OtherActor)
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
