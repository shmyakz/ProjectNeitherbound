// Copyright fenryux


#include "GameplayAbilitySystem/NBAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "Net/UnrealNetwork.h"

UNBAttributeSet::UNBAttributeSet()
{
	InitHealth(100.f);
	InitMaxHealth(150.f);

	InitMana(100.f);
	InitMaxMana(100.f);
}

void UNBAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	//~ Begin Resource Attributes
	DOREPLIFETIME_CONDITION_NOTIFY(UNBAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UNBAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UNBAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UNBAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
	//~ End Resource Attributes
}

void UNBAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UNBAttributeSet, Health, OldHealth);
}

void UNBAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UNBAttributeSet, MaxHealth, OldMaxHealth);
}

void UNBAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UNBAttributeSet, MaxHealth, OldMana);
}

void UNBAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UNBAttributeSet, MaxHealth, OldMaxMana);
}
