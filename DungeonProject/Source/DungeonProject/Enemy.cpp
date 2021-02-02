// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "Engine.h"

AEnemy::AEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	TargetWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("Target Widget Component"));
	TargetWidget->SetVisibility(false);
}

void AEnemy::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemy::Attack()
{
	GEngine->AddOnScreenDebugMessage(1, 5.0f, FColor::White, "Target Acquired beep boop");
}

void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

