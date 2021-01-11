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
	UPROPERTY(VisibleAnywhere) UStaticMeshComponent* SwordMesh;

	UPROPERTY(VisibleAnywhere) class UBoxComponent* SwordCollision;

	UPROPERTY(EditDefaultsOnly) class UAnimMontage* RollMontage;

	UPROPERTY(EditDefaultsOnly) class UAnimMontage* DeathMontage;
	
	UPROPERTY(EditAnywhere) TSubclassOf<class UCharacterWidget> CharacterHUD;

	UPROPERTY(BlueprintReadOnly) int health = 6;
	UPROPERTY(BlueprintReadOnly) int maxHealth = 6;
	UPROPERTY(BlueprintReadOnly) int goldCount = 0;
	UPROPERTY(BlueprintReadOnly) int potionCount = 0;
	UPROPERTY(BlueprintReadOnly) int humanity = 0;

	FVector characterPosition = { 0, 0, 0 };

	UPROPERTY(BlueprintReadWrite) bool IsAttacking = false;
	UPROPERTY(BlueprintReadOnly) bool IsRolling = false;
	UPROPERTY(BlueprintReadOnly) bool IsDeath = false;

private:
	bool IsLockedOn = false;

protected:
	void MoveForward(float Value);
	void MoveRight(float Value);

protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION(BlueprintCallable) void TakeDamage(int damageAmount);
	UFUNCTION(BlueprintCallable) void LightAttack();
	UFUNCTION(BlueprintCallable) void HeavyAttack();

	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

private:
	void Death();
	void Interact();
	void UsePotion();
	void Roll();
	void LockOn();
	//void LightAttack();
	//void HeavyAttack();
};
