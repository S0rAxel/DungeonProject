// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SlateWrapperTypes.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (DisplayPriority = 1))  FString Text;

	UPROPERTY(EditInstanceOnly) ESlateVisibility WidgetVisibility;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
