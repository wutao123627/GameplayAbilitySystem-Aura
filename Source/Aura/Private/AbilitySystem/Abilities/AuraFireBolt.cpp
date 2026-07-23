// Copyright Druid Mechanics.


#include "AbilitySystem/Abilities/AuraFireBolt.h"
#include "AuraGameplayTags.h"

FString UAuraFireBolt::GetDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);
	if (Level == 1) {
		return FString::Printf(
			
			TEXT(
				//Title
				"<Title>FIRE BOLT</>\n\n"

				//Details
				"<Small>Level: </><Level>%d</>\n"
				//ManaCost
				"<Small>ManaCost: </><ManaCost>%.1f</>\n"
				//cooldown
				"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"

				"<Default>Launched a bolt of fire, " 
				"exploding on impact and dealing: </>"
				
				//Damage
				"<Damage>%d</>"
				"<Default> fire damage with a chance to burn</>"
				),
			//Value
			Level,
			ManaCost,
			Cooldown,
			ScaledDamage);
	}
	else {
		return FString::Printf(
			
			TEXT(
				//Title
				"<Title>FIRE BOLT</>\n\n"

				//Details
				"<Small>Level: </><Level>%d</>\n"
				//ManaCost
				"<Small>ManaCost: </><ManaCost>%.1f</>\n"
				//cooldown
				"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"

				//Number of FireBolts
				"<Default>Launched %d bolts of fire, " 
				"exploding on impact and dealing: </>"
				
				//Damage
				"<Damage>%d</>"
				"<Default> fire damage with a chance to burn</>"
				),
			//Value
			Level,
			ManaCost,
			Cooldown,
			FMath::Min(Level, NumProjectiles),
			ScaledDamage);
	}
	return FString();
}

FString UAuraFireBolt::GetNextLevelDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);
	return FString::Printf(
		TEXT(
			//Title
			"<Title>NEXT LEVEL: </>\n\n"

			//Details
			"<Small>Level: </><Level>%d</>\n"
			//ManaCost
			"<Small>ManaCost: </><ManaCost>%.1f</>\n"
			//cooldown
			"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"

			//Number of FireBolts
			"<Default>Launched %d bolts of fire, "
			"exploding on impact and dealing: </>"

			//Damage
			"<Damage>%d</>"
			"<Default> fire damage with a chance to burn</>"
		),
		//Value
		Level,
		ManaCost,
		Cooldown,
		FMath::Min(Level, NumProjectiles),
		ScaledDamage);
}
