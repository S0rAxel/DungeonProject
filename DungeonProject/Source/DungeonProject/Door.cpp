// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"
#include "InteractableWidget.h"
#include "Components/WidgetComponent.h"
#include "DungeonProjectCharacter.h"

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
