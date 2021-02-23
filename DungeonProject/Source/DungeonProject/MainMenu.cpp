// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"
#include "Engine.h"
#include "UObject/ConstructorHelpers.h"
#include "Widgets/MainMenuWidget.h"

AMainMenu::AMainMenu(const FObjectInitializer& ObjectInitializer)
{
	//static ConstructorHelpers::FClassFinder<UMainMenuWidget> MainMenuWidget(TEXT("/Game/ThirdPersonCPP/Blueprints/Widgets/WBP_MainMenu"));

	/*if (!ensure(MainMenuWidget.Class != nullptr)) return;

	MainMenuWidgetClass = MainMenuWidget.Class;*/
}

void AMainMenu::BeginPlay()
{
	ShowWidget();
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
