// Fill out your copyright notice in the Description page of Project Settings.

#include "TP_ThirdPerson/ThirdPersonShooterCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputComponent.h"

AThirdPersonShooterCharacter::AThirdPersonShooterCharacter()
{
	GetMovementComponent()->NavAgentProps.bCanCrouch = true;
}

void AThirdPersonShooterCharacter::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = MaxHealth;

	ActorLookingAt = nullptr;
}

void AThirdPersonShooterCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) {
		Super::SetupPlayerInputComponent(PlayerInputComponent);

		//Crouching
		EnhancedInputComponent->BindAction(CrouchAction, ETriggerEvent::Started, this, &AThirdPersonShooterCharacter::ToggleCrouch);

		//Interact
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Started, this, &AThirdPersonShooterCharacter::InteractWithActor);
	}

}

void AThirdPersonShooterCharacter::Damage_Implementation(float value)
{
	if (CurrentHealth <= 0)
		Die();

	CurrentHealth -= value;
}

void AThirdPersonShooterCharacter::Heal_Implementation(float value)
{
	CurrentHealth = (CurrentHealth + value) >= MaxHealth ? MaxHealth : CurrentHealth + value;
}

void AThirdPersonShooterCharacter::Die_Implementation()
{
}

void AThirdPersonShooterCharacter::ToggleCrouch()
{
	CanCrouch() ? Crouch() : UnCrouch();
}

void AThirdPersonShooterCharacter::InteractWithActor()
{
	if (ActorLookingAt)
		ActorLookingAt->Interact();
}