// Fill out your copyright notice in the Description page of Project Settings.


#include "CP_Knight.h"

// Sets default values
ACP_Knight::ACP_Knight()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACP_Knight::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACP_Knight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACP_Knight::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

