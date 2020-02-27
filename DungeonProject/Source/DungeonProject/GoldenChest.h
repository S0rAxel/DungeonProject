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

	UPROPERTY(EditAnywhere) TSubclassOf<class AInteractable> InteractableBlueprint;

private:
	bool IsOpen;

protected:
	void Interact(class ADungeonProjectCharacter* Character) override;
	void NotifyActorBeginOverlap(AActor* OtherActor) override;

	UFUNCTION(BlueprintCallable) void SpawnObject();
};
