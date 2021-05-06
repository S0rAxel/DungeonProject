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

	inline uint8 GetKeyID() const;

protected:
	UPROPERTY(Transient) class UBlackboardData* BlackboardData;
	
private:
	UPROPERTY(Transient) class UBehaviorTreeComponent* BehaviorTreeComponent;
	UPROPERTY(Transient) class UBlackboardComponent* BlackboardComponent;
	uint8 KeyID;
};

inline uint8 AEnemyAIController::GetKeyID() const
{
	return KeyID;
}

