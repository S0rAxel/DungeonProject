// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenu.h"
#include "Engine.h"
#include "UObject/ConstructorHelpers.h"
#include "Widgets/MainMenuWidget.h"
//#include "LevelSequence/Public/LevelSequence.h"
//#include "LevelSequence/Public/LevelSequencePlayer.h"
//#include "LevelSequence/Public/LevelSequenceActor.h"

AMainMenu::AMainMenu(const FObjectInitializer& ObjectInitializer)
{
	/*static ConstructorHelpers::FClassFinder<ULevelSequence> LevelSequence(TEXT("E:/Projects/UnrealProjects/DungeonProject/DungeonProject/Content/Cinematics/MainMenu.uasset"));
	if (!ensure(LevelSequence.Class != nullptr)) return;

	MenuSequence = LevelSequence.Class.GetDefaultObject();
	static ConstructorHelpers::FClassFinder<UMainMenuWidget> MainMenuWidget(TEXT("/Game/ThirdPersonCPP/Blueprints/Widgets/WBP_MainMenu"));

	if (!ensure(MainMenuWidget.Class != nullptr)) return;

	MainMenuWidgetClass = MainMenuWidget.Class;*/
}

void AMainMenu::BeginPlay()
{
	ShowWidget();
	PlaySequence();
}

void AMainMenu::ShowWidget()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "Begin PLay showing widget");

	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	if (PlayerController != nullptr)
	{
		UMainMenuWidget* MainMenu = CreateWidget<UMainMenuWidget>(PlayerController, MainMenuWidgetClass);

		if (MainMenu != nullptr) 
		{
			MainMenu->AddToViewport();

			FInputModeUIOnly InputModeData;
			InputModeData.SetWidgetToFocus(MainMenu->TakeWidget());
			InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

			PlayerController->SetInputMode(InputModeData);
			PlayerController->bShowMouseCursor = true;
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "MainMenu is null");
		}
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "Player Controller is null");
	}
}

/*void AMainMenu::PlaySequence()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "In Sequence Function");

	//auto levelSequence = MainMenuSequence.GetDefaultObject();
	auto levelSequence = MenuSequence;

	FMovieSceneSequencePlaybackSettings playbackSettings;
	ALevelSequenceActor* sequenceActor; 

	playbackSettings.bAutoPlay = true;
	playbackSettings.LoopCount.Value = -1;

	if (levelSequence != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "LevelSequence Is not null");
		SequencePlayer->CreateLevelSequencePlayer(GetWorld(), levelSequence, playbackSettings, sequenceActor);

		//sequenceActor->PlaybackSettings.bAutoPlay = true;
		//sequenceActor->PlaybackSettings.LoopCount.Value = -1;
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "LevelSequence in nullptr");
	}
}*/
