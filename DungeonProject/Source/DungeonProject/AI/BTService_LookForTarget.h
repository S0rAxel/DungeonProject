// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTService_LookForTarget.generated.h"

/**
 * 
 */
UCLASS()
class DUNGEONPROJECT_API UBTService_LookForTarget : public UBTService
{
	GENERATED_BODY()

public:
	UBTService_LookForTarget();
	
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
