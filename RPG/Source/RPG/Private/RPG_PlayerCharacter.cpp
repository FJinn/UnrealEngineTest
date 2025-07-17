// Fill out your copyright notice in the Description page of Project Settings.


#include "RPG_PlayerCharacter.h"
#include "AbilitySystemComponent.h"

// Sets default values
ARPG_PlayerCharacter::ARPG_PlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));

	CharacterAttributeSet = CreateDefaultSubobject<URPG_CharacterAttributeSet>(TEXT("CharacterAttributeSet"));
}

// Called when the game starts or when spawned
void ARPG_PlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
	}

	if (CharacterAttributeSet)
	{
		CharacterAttributeSet->OnHealthChanged.AddDynamic(this, &ARPG_PlayerCharacter::HandleHealthChanged);
	}
	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
		AbilitySystemComponent->SetNumericAttributeBase(URPG_CharacterAttributeSet::GetHealthAttribute(), InitialHealth);
	}
}

// Called every frame
void ARPG_PlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARPG_PlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UAbilitySystemComponent* ARPG_PlayerCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ARPG_PlayerCharacter::HandleHealthChanged(float Magnitude, float NewHealth)
{
	if (NewHealth <= 0)
	{
		Destroy();
	}
}