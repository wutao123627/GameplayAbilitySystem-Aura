// Copyright Druid Mechanics.


#include "AbilitySystem/Data/CharacterClassInfo.h"
#include "GameplayEffect.h"
#include "Abilities/GameplayAbility.h"


FCharacterClassDefaultInfo UCharacterClassInfo::GetClassDefaultInfo(ECharacterClass CharacterClass)
{
	return CharacterClassInformation.FindChecked(CharacterClass);
}
