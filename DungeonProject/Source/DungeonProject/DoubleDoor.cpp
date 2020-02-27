// Fill out your copyright notice in the Description page of Project Settings.


#include "DoubleDoor.h"
#include "Engine.h"
#include "InteractableWidget.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Components/WidgetComponent.h"

ADoubleDoor::ADoubleDoor()
{
	BoxComponent->SetBoxExtent(FVector(200.f, 200.f, 100.f));

	MeshComponent->SetRelativeLocation(FVector(180.f, 0.f, -100.f));
	MeshComponent->SetRelativeRotation(FRotator(0.f, 180.f, 0.f));
	
	WidgetComponent->SetRelativeLocation(FVector(0.f, 100.f, 250.f));

	SecondDoor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SecondMesh"));
	SecondDoor->AttachToComponent(BoxComponent, FAttachmentTransformRules::KeepRelativeTransform);
	SecondDoor->SetRelativeLocation(FVector(-180.f, 0.f, -100.f));
}

void ADoubleDoor::Interact(ADungeonProjectCharacter* Character)
{
	if (IsLocked)
	{
		if (LockDoorCue != nullptr)
		{
			UGameplayStatics::PlaySoundAtLocation(this, LockDoorCue, GetActorLocation());
		}

		InteractText = "DOORS ARE LOCKED...";
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
			actionInfo.CallbackTarget = MeshComponent;
			UKismetSystemLibrary::MoveComponentTo(MeshComponent, MeshComponent->GetRelativeLocation(), FRotator(0.f, 290.f, 0.f), false, true, 0.5f, false, EMoveComponentAction::Move, actionInfo);
			actionInfo.CallbackTarget = SecondDoor;
			UKismetSystemLibrary::MoveComponentTo(SecondDoor, SecondDoor->GetRelativeLocation(), FRotator(0.f, -100.f, 0.f), false, true, 0.5f, false, EMoveComponentAction::Move, actionInfo);
		}
	}
}
