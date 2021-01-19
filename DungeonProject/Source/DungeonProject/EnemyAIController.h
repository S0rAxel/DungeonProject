// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

/**
 *
 */
UCLASS()
class DUNGEONPROJECT_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()

public:
	AEnemyAIController();
	virtual void OnPossess(APawn* InPawn) override;
	
private:
	UPROPERTY(Transient) class UBlackBoardComponent* BlackBoard;
	UPROPERTY(Transient) class UBehaviorTreeComponent* BehaviorTreeComponent;

};
