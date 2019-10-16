// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "C_Knight.generated.h"

UCLASS()
class UNNAMEDDUNGEON_API AC_Knight : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AC_Knight();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float amount);
	void MoveRight(float amount);

	//class UFloatingPawnMovement* floatingPawnMovement;

	class UFloatingPawnMovement* FloatingCharacterMovement;

	UPROPERTY(EditAnywhere, Category = "Components")
		UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* SpringArm;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
