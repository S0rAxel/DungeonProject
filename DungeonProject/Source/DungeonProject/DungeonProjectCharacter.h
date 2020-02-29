// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DungeonProjectCharacter.generated.h"

UCLASS(config=Game)
class ADungeonProjectCharacter : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

public:
	ADungeonProjectCharacter();

public:
	float health = 1.0f;
	float maxHealth = 1.0f;
	UPROPERTY(BlueprintReadOnly) int humanity = 0;
	UPROPERTY(BlueprintReadOnly) int goldCount = 0;
	UPROPERTY(BlueprintReadOnly) int potionCount = 0;

	FVector characterPosition = { 0, 0, 0 };

protected:
	void MoveForward(float Value);
	void MoveRight(float Value);

protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	void Heal(int healAmount);
	
	UFUNCTION(BlueprintCallable) void TakeDamage(int damageAmount);

	virtual void Tick(float DeltaTime) override;
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

private:
	void Death();
	void Interact();
	void UsePotion();
	void Roll();
	void LockOn();
	void LightAttack();
	void HeavyAttack();
};

