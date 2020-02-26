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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (DisplayName = "Mesh")) UStaticMeshComponent* MeshComponent;

	UPROPERTY(VisibleAnywhere, meta = (DisplayName = "BoxCollider")) class UBoxComponent* BoxComponent;

	UPROPERTY(VisibleAnywhere, meta = (DisplayName = "Widget")) class UWidgetComponent* WidgetComponent;

	UPROPERTY(EditAnywhere) FString InteractText;

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
