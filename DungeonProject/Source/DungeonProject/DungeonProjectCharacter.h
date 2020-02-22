// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DungeonProjectCharacter.generated.h"

UCLASS(config=Game)
class ADungeonProjectCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
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
	void Roll();

	/** Called for forwards/backward input */
	void MoveForward(float Value);
	/** Called for side to side input */
	void MoveRight(float Value);

protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
public:
	void Heal(int amount);
	void Interact();
	void LockOn();
	
	virtual void Tick(float DeltaTime) override;
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

