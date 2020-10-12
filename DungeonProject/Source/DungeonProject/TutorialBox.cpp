// Fill out your copyright notice in the Description page of Project Settings.


#include "TutorialBox.h"
#include "Engine.h"
#include "TutorialWidget.h"
#include "DungeonProjectCharacter.h"
#include "Components/BoxComponent.h"
#include "Components/WidgetComponent.h"
#include "Kismet/KismetMathLibrary.h"


// Sets default values
ATutorialBox::ATutorialBox()
{
	PrimaryActorTick.bCanEverTick = true;

	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	RootComponent = BoxCollider;

	BoxCollider->SetBoxExtent(FVector(300.f, 300.f, 300.f));

	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("WidgetComponent"));
	WidgetComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	WidgetComponent->AttachToComponent(BoxCollider, FAttachmentTransformRules::KeepRelativeTransform);
}

void ATutorialBox::BeginPlay()
{
	Super::BeginPlay();

	auto widget = Cast<UTutorialWidget>(WidgetComponent->GetUserWidgetObject());
	if (widget != nullptr)
	{
		widget->TutorialBox = this;
		widget->SetVisibility(WidgetVisibility);
	}
}

void ATutorialBox::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if (OtherActor != nullptr && Cast<ADungeonProjectCharacter>(OtherActor))
	{
		if (WidgetComponent->GetUserWidgetObject() != nullptr)
		{
			Cast<UTutorialWidget>(WidgetComponent->GetUserWidgetObject())->SetVisibility(ESlateVisibility::Visible);
		}
	}
}

void ATutorialBox::NotifyActorEndOverlap(AActor* OtherActor)
{
	if (OtherActor != nullptr && Cast<ADungeonProjectCharacter>(OtherActor))
	{
		if (WidgetComponent->GetUserWidgetObject() != nullptr)
		{
			Cast<UTutorialWidget>(WidgetComponent->GetUserWidgetObject())->SetVisibility(ESlateVisibility::Hidden);
		}
	}
}

// Called every frame
void ATutorialBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto camera = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0);

	
	
	if (camera != nullptr)
	{
		FRotator desiredRotation = UKismetMathLibrary::FindLookAtRotation(WidgetComponent->GetComponentLocation(), camera->GetCameraLocation());
		desiredRotation.Yaw = UKismetMathLibrary::Clamp(desiredRotation.Yaw, 50, 130);
		WidgetComponent->SetWorldRotation(desiredRotation);
	}
}

