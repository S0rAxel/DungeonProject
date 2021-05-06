// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BlackboardData.h"
#include "Enemy.h"
#include "Engine.h"

AEnemyAIController::AEnemyAIController()
{
	//BlackboardData = NewObject<UBlackboardData>();
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackBoardComponent"));
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
	KeyID = 0;
}

void AEnemyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	AEnemy* Enemy = Cast<AEnemy>(InPawn);

	if (Enemy && Enemy->Behavior)
	{
		BlackboardComponent->InitializeBlackboard(*Enemy->Behavior->BlackboardAsset);

		KeyID = BlackboardComponent->GetKeyID("Target");
		BehaviorTreeComponent->StartTree(*Enemy->Behavior);
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, "BTSERVICE EXISTS");
	}
}
