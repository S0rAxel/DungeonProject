 // Fill out your copyright notice in the Description page of Project Settings.


#include "Lever.h"
#include "Engine.h"
#include "Door.h"
#include "GateDoor.h"
#include "InteractableWidget.h"
#include "DungeonProjectCharacter.h"
#include "Components/BoxComponent.h"
#include "Components/WidgetComponent.h"
#include "Components/StaticMeshComponent.h"

ALever::ALever()
{
	BoxComponent->SetBoxExtent(FVector(100.f, 100.f, 100.f));

	LeverMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeverMesh"));
	LeverMesh->AttachToComponent(MeshComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

void ALever::Interact(ADungeonProjectCharacter* Character)
{
	if (!IsPulled)
	{
		IsPulled = true;

		Super::Interact(Character);

		Cast<UInteractableWidget>(WidgetComponent->GetUserWidgetObject())->SetVisibility(ESlateVisibility::Hidden);


		FLatentActionInfo actionInfo;
		actionInfo.CallbackTarget = this;
		UKismetSystemLibrary::MoveComponentTo(LeverMesh, LeverMesh->GetRelativeLocation(), FRotator(0.f, 0.f, 60.f), false, true, 0.5f, false, EMoveComponentAction::Move, actionInfo);

		if (Cast<AGateDoor>(Door))
		{
			Cast<AGateDoor>(Door)->OpenGate();
		}
		else if (Cast<ADoor>(Door))
		{
			Cast<ADoor>(Door)->IsLocked = false;
		}
	}
}

void ALever::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if (OtherActor != nullptr && Cast<ADungeonProjectCharacter>(OtherActor))
	{
		if (WidgetComponent->GetUserWidgetObject() != nullptr)
		{
			if (IsPulled)
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
