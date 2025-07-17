// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RPG_AttributeSetBase.h"
#include "AbilitySystemComponent.h"
#include "RPG_CharacterAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class RPG_API URPG_CharacterAttributeSet : public URPG_AttributeSetBase
{
	GENERATED_BODY()
	
public:
    void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;

    UPROPERTY()
    FPlayAttributeEvent OnHealthChanged;

    UPROPERTY()
    FGameplayAttributeData Health;
    PLAY_ATTRIBUTE_ACCESSORS(URPG_CharacterAttributeSet, Health);
};
