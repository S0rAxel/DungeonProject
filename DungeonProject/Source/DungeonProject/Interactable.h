// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.generated.h"

UCLASS()
class DUNGEONPROJECT_API AInteractable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractable();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly) UStaticMeshComponent* MeshComponent;

	UPROPERTY(VisibleAnywhere) class UBoxComponent* BoxComponent;

	UPROPERTY(VisibleAnywhere) class UWidgetComponent* WidgetComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly) FString InteractText;

protected:
	class ADungeonProjectCharacter* Character;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Interact();
	virtual void Tick(float DeltaTime) override;
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;
};
