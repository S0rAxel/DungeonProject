// Fill out your copyright notice in the Description page of Project Settings.


#include "SingleDoor.h"
#include "Engine.h"
#include "InteractableWidget.h"
#include "Components/WidgetComponent.h"
#include "DungeonProjectCharacter.h"

void ASingleDoor::Interact(ADungeonProjectCharacter* Character)
{
	if (IsLocked)
	{
		if (LockDoorCue != nullptr)
		{
			UGameplayStatics::PlaySoundAtLocation(this, LockDoorCue, GetActorLocation());
		}

		InteractText = "DOOR'S LOCKED...";
	}
	else
	{
		if (!IsOpen)
		{
			IsOpen = true;
			
			if (SoundCue != nullptr)
			{
				UGameplayStatics::PlaySoundAtLocation(this, SoundCue, GetActorLocation());
			}

			Cast<UInteractableWidget>(WidgetComponent->GetUserWidgetObject())->SetVisibility(ESlateVisibility::Hidden);

			FLatentActionInfo actionInfo;
			actionInfo.CallbackTarget = this;
			UKismetSystemLibrary::MoveComponentTo(MeshComponent, MeshComponent->GetRelativeLocation(), FRotator(0.f, -100.f, 0.f), false, true, 0.5f, false, EMoveComponentAction::Move, actionInfo);
		}
	}
}