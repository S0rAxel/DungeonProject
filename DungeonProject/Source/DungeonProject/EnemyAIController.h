// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BlackboardData.h"
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

protected:
	UPROPERTY(Transient) class UBlackboardData* BlackboardData;
	uint8 KeyID;
	
private:
	UPROPERTY(Transient) class UBehaviorTreeComponent* BehaviorTreeComponent;
	UPROPERTY(Transient) class UBlackboardComponent* BlackboardComponent;
};
