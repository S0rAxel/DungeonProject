// Fill out your copyright notice in the Description page of Project Settings.


#include "GateDoor.h"
#include "Engine.h"
#include "Components/StaticMeshComponent.h"

void AGateDoor::OpenGate() 
{
	UGameplayStatics::PlaySoundAtLocation(this, SoundCue, GetActorLocation());

	FLatentActionInfo actionInfo;
	actionInfo.CallbackTarget = this;
	UKismetSystemLibrary::MoveComponentTo(MeshComponent, FVector(0.f, 0.f, 270.f), MeshComponent->GetRelativeRotation(), true, true, 3.f, false, EMoveComponentAction::Move, actionInfo);
}

void AGateDoor::Interact(ADungeonProjectCharacter* Character) { }

void AGateDoor::NotifyActorBeginOverlap(AActor* OtherActor) { }

void AGateDoor::NotifyActorEndOverlap(AActor* OtherActor) { }
