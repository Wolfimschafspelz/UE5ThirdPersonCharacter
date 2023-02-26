// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Damagable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UDamagable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class FIRSTGAME_API IDamagable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Health")
	void Damage(float value);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Health")
	void Heal(float value);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Health")
	void Die();
};
