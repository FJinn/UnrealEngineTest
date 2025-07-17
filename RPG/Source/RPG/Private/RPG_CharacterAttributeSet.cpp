// Fill out your copyright notice in the Description page of Project Settings.


#include "RPG_CharacterAttributeSet.h"
#include "GameplayEffectExtension.h"

void URPG_CharacterAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
    if (Data.EvaluatedData.Attribute == GetHealthAttribute())
    {
        OnHealthChanged.Broadcast(Data.EvaluatedData.Magnitude, GetHealth());
    }
}
