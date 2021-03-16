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
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) class UCanvasPanel* OMainCanvas;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) class UCanvasPanel* LoadGameCanvas;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) class UCanvasPanel* OGameplayCanvas;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) class UCanvasPanel* OControlsCanvas;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) class UCanvasPanel* OVideoCanvas;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) class UCanvasPanel* OAudioCanvas;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) class UButton* NewGame_Btn;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) class UButton* LoadGame_Btn;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) class UButton* Continue_Btn;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) class UButton* Options_Btn;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) class UButton* Quit_Btn;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) class UButton* LoadGameSlot_1_Btn;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) class UButton* LoadGameSlot_2_Btn;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) class UButton* LoadGameSlot_3_Btn;

#pragma region Options button

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) class UButton* OGameplay_Btn;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) class UButton* OControls_Btn;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) class UButton* OVideo_Btn;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) class UButton* OAudio_Btn;

#pragma endregion

#pragma region Back Buttons

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) class UButton* BackLoadGame_Btn;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) class UButton* BackOptions_Btn;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) class UButton* BackOGameplay_Btn;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) class UButton* BackOControls_Btn;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) class UButton* BackOVideo_Btn;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) class UButton* BackOAudio_Btn;

#pragma endregion

public:
	UFUNCTION() void NewGame();
	UFUNCTION() void LoadGame();
	UFUNCTION() void LoadGameSlot();
	UFUNCTION() void Continue();
	UFUNCTION() void Options();
	UFUNCTION() void Quit();

#pragma region Options Functions

	UFUNCTION() void OGameplay();
	UFUNCTION() void OControls();
	UFUNCTION() void OVideo();
	UFUNCTION() void OAudio();

#pragma endregion

#pragma region Back Button Funtions

	UFUNCTION() void BackLoadGame();
	UFUNCTION() void BackOptions();
	UFUNCTION() void BackOGameplay();
	UFUNCTION() void BackOControls();
	UFUNCTION() void BackOVideo();
	UFUNCTION() void BackOAudio();

#pragma endregion

private:
	void LoadGameSlot(int index);
	virtual void NativeConstruct() override;


	//virtual bool Initialize() override;
};
