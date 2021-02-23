// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class DUNGEONPROJECT_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) class UCanvasPanel* MainCanvas;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) class UCanvasPanel* OptionsCanvas;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) class UCanvasPanel* LoadGameCanvas;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) class UButton* NewGame_Btn;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) class UButton* LoadGame_Btn;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) class UButton* BackLoadGame_Btn;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) class UButton* Continue_Btn;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) class UButton* Options_Btn;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) class UButton* BackOptions_Btn;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) class UButton* Quit_Btn;

public:
	UFUNCTION() void NewGame();
	UFUNCTION() void LoadGame();
	UFUNCTION() void Continue();
	UFUNCTION() void Options();
	UFUNCTION() void Quit();

	UFUNCTION() void BackOptions();
	UFUNCTION() void BackLoadGame();

private:
	virtual void NativeConstruct() override;

	//virtual bool Initialize() override;
};
