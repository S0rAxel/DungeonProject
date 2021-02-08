// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DialogueBoxWidget.generated.h"

/**
 * 
 */
UCLASS()
class DUNGEONPROJECT_API UDialogueBoxWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) class UTextBlock* DialogueBox_T;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) class UTextBlock* CharacterName_T;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) class UImage* CharacterPortrait_I;

};
