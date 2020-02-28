// Fill out your copyright notice in the Description page of Project Settings.


#include "TutorialBox.h"
#include "Components/BoxComponent.h"
#include "Components/WidgetComponent.h"

// Sets default values
ATutorialBox::ATutorialBox()
{
	PrimaryActorTick.bCanEverTick = true;

	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	RootComponent = BoxCollider;

	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("WidgetComponent"));
	WidgetComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	WidgetComponent->AttachToComponent(BoxCollider, FAttachmentTransformRules::KeepRelativeTransform);
}
// Called every frame
void ATutorialBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

