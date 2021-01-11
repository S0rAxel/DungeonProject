// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemy.generated.h"

UCLASS()
class DUNGEONPROJECT_API AEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy();

public:
	int HealthPoint;
	int GoldToDrop;
	
private:
	UPROPERTY(EditDefaultsOnly) class UStaticMeshComponent* MeshComponent;
	//UPROPERTY(EditDefaultsOnly) class UBehaviorTree* EnemyBehaviorTree;
	
	UPROPERTY(EditDefaultsOnly) class UAnimMontage* IdleMontage;
	UPROPERTY(EditDefaultsOnly) class UAnimMontage* PatrolMontage;
	UPROPERTY(EditDefaultsOnly) TArray<UAnimMontage*> AttackMontages;
	UPROPERTY(EditDefaultsOnly) class UAnimMontage* DeathMontage;
	class UMaterialInstance* MaterialInstance;

	bool IsIdle = true;
	bool IsPatrolling = false;
	bool IsAttacking = false;
	bool IsDead = false;
	float MovementSpeed = 100;
	float DamageValue;
	
protected:
	virtual void BeginPlay() override;
	virtual void Attack();
	
public:	
	virtual void Tick(float DeltaTime) override;
};