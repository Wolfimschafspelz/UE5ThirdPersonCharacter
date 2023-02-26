// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "InputActionValue.h"
#include "Damagable.h"
#include "Interactable.h"
#include "ThirdPersonShooterCharacter.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTGAME_API AThirdPersonShooterCharacter : public ATP_ThirdPersonCharacter, public IDamagable
{
	GENERATED_BODY()

	/** Crouch Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* CrouchAction;

	/** Interact Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* InteractAction;

public:
	AThirdPersonShooterCharacter();

protected:
	void ToggleCrouch();

protected:
	UPROPERTY(EditAnywhere, Category = "Health")
	float MaxHealth;
	float CurrentHealth;

	IInteractable* ActorLookingAt;

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void BeginPlay();

public:
	void Damage_Implementation(float value);
	void Heal_Implementation(float value);
	void Die_Implementation();

	void InteractWithActor();
};
