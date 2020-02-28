// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TutorialBox.generated.h"

UCLASS()
class DUNGEONPROJECT_API ATutorialBox : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATutorialBox();

	UPROPERTY(VisibleAnywhere) class UBoxComponent* BoxCollider;

	UPROPERTY(VisibleAnywhere) class UWidgetComponent* WidgetComponent;

	UPROPERTY(EditAnywhere) FString Text;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
