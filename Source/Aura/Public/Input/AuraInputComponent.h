// Copyright Druid Mechanics.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "Input/AuraInputConfig.h"
#include "AuraInputComponent.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UAuraInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()
public:
	template<class UserClass,typename PressFuncType,typename ReleasedFuncType,typename HeldFuncType>
	void BindAbilityActions(const UAuraInputConfig* InputConfig, UserClass* Object,PressFuncType PressedFunc,ReleasedFuncType ReleasedFunc,HeldFuncType HeldFunc);
};

template<class UserClass, typename PressFuncType, typename ReleasedFuncType, typename HeldFuncType>
inline void UAuraInputComponent::BindAbilityActions(const UAuraInputConfig* InputConfig, UserClass* Object, PressFuncType PressedFunc, ReleasedFuncType ReleasedFunc, HeldFuncType HeldFunc)
{
	check(InputConfig);
	for (const FAuraInputAction& Action:InputConfig -> AbilityInputActions) {
		if (Action.InputAction && Aciton.InputTag.IsValid()) {
			if (PressFunc) {
				BindAction(Action.InputAction, ETriggerEvent::Started, Object, PressFunc, Action.InputTag);
			}

			if (ReleasedFunc) {
				BindAction(Action.InputAction, ETriggerEvent::Completed, Object, ReleasedFunc, Action.InputTag);
			}

			if (HeldFunc) {
				BindAction(Action.InputAction, ETriggerEvent::Triggered, Object, HeldFunc, Action.InputTag);
			}


		}
	}

}
