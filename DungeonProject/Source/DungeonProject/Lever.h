// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "Lever.generated.h"

/**
 * 
 */
UCLASS()
class DUNGEONPROJECT_API ALever : public AInteractable
{
	GENERATED_BODY()
	
public:
	ALever();

	UPROPERTY(VisibleAnywhere) class UStaticMeshComponent* LeverMesh;

	UPROPERTY(EditAnywhere, meta = (DisplayPriority = 1)) class ADoor* Door;

private:
	bool IsPulled;

protected:
	void Interact(class ADungeonProjectCharacter* Character) override;
	void NotifyActorBeginOverlap(AActor* OtherActor) override;
};
