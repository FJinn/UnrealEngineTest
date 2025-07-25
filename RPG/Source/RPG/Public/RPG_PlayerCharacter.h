// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "RPG_CharacterAttributeSet.h"
#include "RPG_PlayerCharacter.generated.h"

UCLASS()
class RPG_API ARPG_PlayerCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARPG_PlayerCharacter();

	UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<URPG_CharacterAttributeSet> CharacterAttributeSet;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere)
	float InitialHealth = 100.0f;

	UFUNCTION()
	void HandleHealthChanged(float Magnitude, float NewHealth);
};
