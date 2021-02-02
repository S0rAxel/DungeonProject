// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyAIController.h"
#include "Enemy.h"

AEnemyAIController::AEnemyAIController()
{
	BlackboardData = NewObject<UBlackboardData>();
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackBoard"));
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTree"));
}

void AEnemyAIController::OnPossess(APawn* InPawn)
{
	Super::Possess(InPawn);
	AEnemy* Enemy = Cast<AEnemy>(InPawn);

	if (Enemy)
	{
		BlackboardComponent->InitializeBlackboard(*Enemy->Behavior->BlackboardAsset);
	}
}
