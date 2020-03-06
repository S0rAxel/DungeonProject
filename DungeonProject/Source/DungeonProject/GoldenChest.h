// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "GoldenChest.generated.h"

/**
 *
 */
UCLASS()
class DUNGEONPROJECT_API AGoldenChest : public AInteractable
{
	GENERATED_BODY()

public:
	AGoldenChest();

	UPROPERTY(VisibleAnywhere) class UStaticMeshComponent* MeshChestTop;

	UPROPERTY(VisibleAnywhere) class USceneComponent* PivotPoint;

	UPROPERTY(EditInstanceOnly, meta = (DisplayPriority = 1)) TSubclassOf<class AInteractable> InteractableBlueprint;

    UPROPERTY(EditInstanceOnly, meta = (DisplayPriority = 1)) TArray<class ADoor*> Doors;
	
private:
	bool IsOpen = false;

protected:
	void Interact(class ADungeonProjectCharacter* Character) override;
	void NotifyActorBeginOverlap(AActor* OtherActor) override;

	UFUNCTION(BlueprintCallable) void SpawnObject();
};
