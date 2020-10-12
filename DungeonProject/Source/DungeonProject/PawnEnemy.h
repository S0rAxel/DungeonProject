// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "PawnEnemy.generated.h"

/**
 * 
 */
UCLASS()
class DUNGEONPROJECT_API APawnEnemy : public AEnemy
{
	GENERATED_BODY()
	
public:
	APawnEnemy();


public:
	void Attack() override;
};
