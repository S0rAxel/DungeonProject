// Fill out your copyright notice in the Description page of Project Settings.


#include "Engine.h"
#include "MainMenuWidget.h"
#include "Components/Button.h"
#include "Components/CanvasPanel.h"
#include "GameFrameWork/PlayerController.h"

void UMainMenuWidget::NativeConstruct() 
{
	Super::NativeConstruct();

	MainCanvas->SetVisibility(ESlateVisibility::Visible);
	LoadGameCanvas->SetVisibility(ESlateVisibility::Hidden);
	OptionsCanvas->SetVisibility(ESlateVisibility::Hidden);

	if (!NewGame_Btn->OnClicked.IsBound())
	{
		NewGame_Btn->OnClicked.AddDynamic(this, &UMainMenuWidget::NewGame);
	}
	if (!LoadGame_Btn->OnClicked.IsBound())
	{
		LoadGame_Btn->OnClicked.AddDynamic(this, &UMainMenuWidget::LoadGame);
	}
	if (!BackLoadGame_Btn->OnClicked.IsBound())
	{
		BackLoadGame_Btn->OnClicked.AddDynamic(this, &UMainMenuWidget::BackLoadGame);
	}
	if (!Continue_Btn->OnClicked.IsBound())
	{
		Continue_Btn->OnClicked.AddDynamic(this, &UMainMenuWidget::Continue);
	}
	if (!Options_Btn->OnClicked.IsBound())
	{
		Options_Btn->OnClicked.AddDynamic(this, &UMainMenuWidget::Options);
	}
	if (!BackOptions_Btn->OnClicked.IsBound())
	{
		BackOptions_Btn->OnClicked.AddDynamic(this, &UMainMenuWidget::BackOptions);
	}
	if (!Quit_Btn->OnClicked.IsBound())
	{
		Quit_Btn->OnClicked.AddDynamic(this, &UMainMenuWidget::Quit);
	}
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
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "Start Game");
	UGameplayStatics::OpenLevel(GetWorld(), FName(TEXT("TutorialMap"))); 

	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "Start Game");
}

void UMainMenuWidget::LoadGame()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "Load Game");
	
	MainCanvas->SetVisibility(ESlateVisibility::Hidden);
	LoadGameCanvas->SetVisibility(ESlateVisibility::Visible);
}

void UMainMenuWidget::BackLoadGame()
{
	LoadGameCanvas->SetVisibility(ESlateVisibility::Hidden);
	MainCanvas->SetVisibility(ESlateVisibility::Visible);
}

void UMainMenuWidget::Continue()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "Continue...");
}

void UMainMenuWidget::Options()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "Options are being shown");

	MainCanvas->SetVisibility(ESlateVisibility::Hidden);
	OptionsCanvas->SetVisibility(ESlateVisibility::Visible);
}

void UMainMenuWidget::BackOptions()
{
	OptionsCanvas->SetVisibility(ESlateVisibility::Hidden);
	MainCanvas->SetVisibility(ESlateVisibility::Visible);
}

void UMainMenuWidget::Quit()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "Quit");

	auto playerController = UGameplayStatics::GetPlayerController(this, 0);

	//playerController->ConsoleCommand("quit");

	UKismetSystemLibrary::QuitGame(GetWorld(), playerController,EQuitPreference::Quit, false);
}

