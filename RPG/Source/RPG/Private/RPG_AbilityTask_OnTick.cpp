// Fill out your copyright notice in the Description page of Project Settings.


#include "RPG_AbilityTask_OnTick.h"

URPG_AbilityTask_OnTick::URPG_AbilityTask_OnTick(const FObjectInitializer& ObjectInitializer)
{
	bTickingTask = true;
}

URPG_AbilityTask_OnTick* URPG_AbilityTask_OnTick::AbilityTaskOnTick(UGameplayAbility* OwningAbility, FName TaskInstanceName)
{
	URPG_AbilityTask_OnTick* MyObj = NewAbilityTask<URPG_AbilityTask_OnTick>(OwningAbility);
	return MyObj;
}

void URPG_AbilityTask_OnTick::Activate()
{
	Super::Activate();
}

void URPG_AbilityTask_OnTick::TickTask(float DeltaTime)
{
	Super::TickTask(DeltaTime);
	if (ShouldBroadcastAbilityTaskDelegates())
	{
		OnTick.Broadcast(DeltaTime);
	}
}
