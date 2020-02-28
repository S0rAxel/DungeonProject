// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "Chest.generated.h"

/**
 *
 */
UCLASS()
class DUNGEONPROJECT_API AChest : public AInteractable
{
	GENERATED_BODY()

public:
	AChest();

	UPROPERTY(VisibleAnywhere) class UStaticMeshComponent* MeshChestTop;

	UPROPERTY(VisibleAnywhere) class USceneComponent* PivotPoint;

	UPROPERTY(VisibleAnywhere) class USceneComponent* SpawnPoint;

	UPROPERTY(EditDefaultsOnly) TSubclassOf<class ACoin> CoinBlueprint;

	UPROPERTY(EditAnywhere, meta = (ClampMin = 2), meta = (ClampMax = 100), meta = (DisplayPriority = 1)) int16 CoinsInChest;

private:
	bool IsOpen;

protected:
	void Interact(class ADungeonProjectCharacter* Character) override;
	void NotifyActorBeginOverlap(AActor* OtherActor) override;

	UFUNCTION(BlueprintCallable) void SpawnCoins();
};
