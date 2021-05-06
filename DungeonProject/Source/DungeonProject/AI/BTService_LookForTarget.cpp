// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_LookForTarget.h"
#include "../Enemy.h"
#include "../EnemyAIController.h"
#include "../DungeonProjectCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "Engine/Engine.h"

UBTService_LookForTarget::UBTService_LookForTarget()
{
	bCreateNodeInstance = true;
}

void UBTService_LookForTarget::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	AEnemyAIController* EnemyController = Cast<AEnemyAIController>(OwnerComp.GetAIOwner());
	if (EnemyController)
	{
		ADungeonProjectCharacter* Enemy = Cast<ADungeonProjectCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

		if (Enemy)
		{
			OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(EnemyController->GetKeyID(), Enemy);
			GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Red, "FOUND TARGET");
		}
	}
}
