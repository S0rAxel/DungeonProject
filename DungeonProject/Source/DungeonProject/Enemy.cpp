// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "Engine.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemy::Attack()
{
	GEngine->AddOnScreenDebugMessage(1, 5.0f, FColor::White, "Target Acquired beep boop");
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

