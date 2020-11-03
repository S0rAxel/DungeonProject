// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/ILabel.h"
#include "Interactable.generated.h"

UCLASS()
class DUNGEONPROJECT_API AInteractable : public AActor, public IILabel
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractable();

	UPROPERTY(VisibleAnywhere) UStaticMeshComponent* MeshComponent;

	UPROPERTY(VisibleAnywhere) class UBoxComponent* BoxComponent;

	UPROPERTY(VisibleAnywhere) class UWidgetComponent* WidgetComponent;

	UPROPERTY(EditDefaultsOnly) class USoundCue* SoundCue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (DisplayPriority = 1)) FString InteractText;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Interact(class ADungeonProjectCharacter* Character);
	virtual void Tick(float DeltaTime) override;
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;
};
