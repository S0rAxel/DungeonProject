// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class DUNGEONPROJECT_API AMainMenu : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	AMainMenu(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadOnly) TSubclassOf<class UMainMenuWidget> MainMenuWidgetClass;
	
	//UPROPERTY(EditAnywhere) ULevelSequence* MenuSequence;
	//UPROPERTY() class ULevelSequencePlayer* SequencePlayer;

public:
	virtual void BeginPlay() override;
	void ShowWidget();

	UFUNCTION(BlueprintImplementableEvent) void PlaySequence();
	UFUNCTION(BlueprintImplementableEvent) void PlaySequenceMainMenuEnd();

};
