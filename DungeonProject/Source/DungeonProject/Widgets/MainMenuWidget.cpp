// Fill out your copyright notice in the Description page of Project Settings.


#include "Engine.h"
#include "MainMenuWidget.h"
#include "Components/Button.h"
#include "Components/CanvasPanel.h"
#include "Components/ComboBoxString.h"
#include "DungeonProject/MainMenu.h"
#include "GameFrameWork/PlayerController.h"

void UMainMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	MainMenu_GM = Cast<AMainMenu>(UGameplayStatics::GetGameMode(GetWorld()));

	MainCanvas->SetVisibility(ESlateVisibility::Visible);
	LoadGameCanvas->SetVisibility(ESlateVisibility::Hidden);
	OptionsCanvas->SetVisibility(ESlateVisibility::Hidden);
	OGameplayCanvas->SetVisibility(ESlateVisibility::Hidden);
	OControlsCanvas->SetVisibility(ESlateVisibility::Hidden);
	OVideoCanvas->SetVisibility(ESlateVisibility::Hidden);
	OAudioCanvas->SetVisibility(ESlateVisibility::Hidden);

	if (!NewGame_Btn->OnClicked.IsBound())
	{
		NewGame_Btn->OnClicked.AddDynamic(this, &UMainMenuWidget::NewGame);
	}
	if (!LoadGame_Btn->OnClicked.IsBound())
	{
		LoadGame_Btn->OnClicked.AddDynamic(this, &UMainMenuWidget::LoadGame);
	}
	
	if (!Continue_Btn->OnClicked.IsBound())
	{
		Continue_Btn->OnClicked.AddDynamic(this, &UMainMenuWidget::Continue);
	}
	if (!Options_Btn->OnClicked.IsBound())
	{
		Options_Btn->OnClicked.AddDynamic(this, &UMainMenuWidget::Options);
	}

	if (!Quit_Btn->OnClicked.IsBound())
	{
		Quit_Btn->OnClicked.AddDynamic(this, &UMainMenuWidget::Quit);
	}

	if (!LoadGameSlot_1_Btn->OnClicked.IsBound())
	{
		LoadGameSlot_1_Btn->OnClicked.AddDynamic(this, &UMainMenuWidget::LoadGameSlot);
	}
	if (!LoadGameSlot_2_Btn->OnClicked.IsBound())
	{
		LoadGameSlot_2_Btn->OnClicked.AddDynamic(this, &UMainMenuWidget::LoadGameSlot);
	}
	if (!LoadGameSlot_3_Btn->OnClicked.IsBound())
	{
		LoadGameSlot_3_Btn->OnClicked.AddDynamic(this, &UMainMenuWidget::LoadGameSlot);
	}

#pragma region Options
	
	if (!OGameplay_Btn->OnClicked.IsBound())
	{
		OGameplay_Btn->OnClicked.AddDynamic(this, &UMainMenuWidget::OGameplay);
	}
	if (!OControls_Btn->OnClicked.IsBound())
	{
		OControls_Btn->OnClicked.AddDynamic(this, &UMainMenuWidget::OControls);
	}
	if (!OVideo_Btn->OnClicked.IsBound())
	{
		OVideo_Btn->OnClicked.AddDynamic(this, &UMainMenuWidget::OVideo);
	}
	if (!OAudio_Btn->OnClicked.IsBound())
	{
		OAudio_Btn->OnClicked.AddDynamic(this, &UMainMenuWidget::OAudio);
	}

#pragma endregion

#pragma region Back Buttons
	
	if (!BackLoadGame_Btn->OnClicked.IsBound())
	{
		BackLoadGame_Btn->OnClicked.AddDynamic(this, &UMainMenuWidget::BackLoadGame);
	}
	if (!BackOptions_Btn->OnClicked.IsBound())
	{
		BackOptions_Btn->OnClicked.AddDynamic(this, &UMainMenuWidget::BackOptions);
	}
	if (!BackOGameplay_Btn->OnClicked.IsBound())
	{
		BackOGameplay_Btn->OnClicked.AddDynamic(this, &UMainMenuWidget::BackOGameplay);
	}
	if (!BackOControls_Btn->OnClicked.IsBound())
	{
		BackOControls_Btn->OnClicked.AddDynamic(this, &UMainMenuWidget::BackOControls);
	}
	if (!BackOVideo_Btn->OnClicked.IsBound())
	{
		BackOVideo_Btn->OnClicked.AddDynamic(this, &UMainMenuWidget::BackOVideo);
	}
	if (!BackOAudio_Btn->OnClicked.IsBound())
	{
		BackOAudio_Btn->OnClicked.AddDynamic(this, &UMainMenuWidget::BackOAudio);
	}

#pragma endregion

}

/*bool UMainMenuWidget::Initialize() 
{
	Super::Initialize();

	NewGame_Btn->OnClicked.AddDynamic(this, &UMainMenuWidget::StartGame);
	Quit_Btn->OnClicked.AddDynamic(this, &UMainMenuWidget::Quit);

	return true;
}*/

void UMainMenuWidget::NewGame() 
{
	MainMenu_GM->PlaySequenceMainMenuEnd();
}

void UMainMenuWidget::NewGameEndSequence()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName(TEXT("TutorialMap"))); 

	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	if (PlayerController != nullptr)
	{
		FInputModeGameOnly InputModeData;
		//InputModeData.SetHideCursorDuringCapture(true); 
		//InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);

		PlayerController->SetInputMode(InputModeData);
		PlayerController->bShowMouseCursor = false;
	}
}

void UMainMenuWidget::LoadGame()
{
	MainCanvas->SetVisibility(ESlateVisibility::Hidden);
	LoadGameCanvas->SetVisibility(ESlateVisibility::Visible);
}

void UMainMenuWidget::LoadGameSlot()
{

}

void UMainMenuWidget::LoadGameSlot(int index)
{

}


void UMainMenuWidget::Continue()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "Continue...");
}

void UMainMenuWidget::Options()
{
	MainCanvas->SetVisibility(ESlateVisibility::Hidden);
	OptionsCanvas->SetVisibility(ESlateVisibility::Visible);
}

#pragma region Option Functions

void UMainMenuWidget::OGameplay()
{
	OMainCanvas->SetVisibility(ESlateVisibility::Hidden);
	OGameplayCanvas->SetVisibility(ESlateVisibility::Visible);
}

void UMainMenuWidget::OControls()
{
	OMainCanvas->SetVisibility(ESlateVisibility::Hidden);
	OControlsCanvas->SetVisibility(ESlateVisibility::Visible);
}

void UMainMenuWidget::OVideo()
{
	OMainCanvas->SetVisibility(ESlateVisibility::Hidden);
	OVideoCanvas->SetVisibility(ESlateVisibility::Visible);
}

void UMainMenuWidget::OAudio()
{
	OMainCanvas->SetVisibility(ESlateVisibility::Hidden);
	OAudioCanvas->SetVisibility(ESlateVisibility::Visible);
}

#pragma endregion

#pragma region Back Option Functions

void UMainMenuWidget::BackLoadGame()
{
	LoadGameCanvas->SetVisibility(ESlateVisibility::Hidden);
	MainCanvas->SetVisibility(ESlateVisibility::Visible);
}

void UMainMenuWidget::BackOptions()
{
	OptionsCanvas->SetVisibility(ESlateVisibility::Hidden);
	MainCanvas->SetVisibility(ESlateVisibility::Visible);
}

void UMainMenuWidget::BackOGameplay()
{
	OGameplayCanvas->SetVisibility(ESlateVisibility::Hidden);
	OMainCanvas->SetVisibility(ESlateVisibility::Visible);
}

void UMainMenuWidget::BackOControls()
{
	OControlsCanvas ->SetVisibility(ESlateVisibility::Hidden);
	OMainCanvas->SetVisibility(ESlateVisibility::Visible);
}

void UMainMenuWidget::BackOVideo()
{
	OVideoCanvas->SetVisibility(ESlateVisibility::Hidden);
	OMainCanvas->SetVisibility(ESlateVisibility::Visible);
}

void UMainMenuWidget::BackOAudio()
{
	OAudioCanvas->SetVisibility(ESlateVisibility::Hidden);
	OMainCanvas->SetVisibility(ESlateVisibility::Visible);
}

#pragma endregion

void UMainMenuWidget::Quit()
{
	auto playerController = UGameplayStatics::GetPlayerController(this, 0);

	//playerController->ConsoleCommand("quit");

	UKismetSystemLibrary::QuitGame(GetWorld(), playerController,EQuitPreference::Quit, false);
}
