// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EasySettingsSubsystemDeveloperSettings.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EasySettingsLib.generated.h"

/**
 * @class UEasySettingsLib
 * @brief A library class providing utility functions for the Easy Settings plugin.
 *
 * This class provides static methods for accessing settings-related classes
 * and developer settings in the Easy Settings plugin.
 */
UCLASS(Blueprintable, BlueprintType)
class EASYSETTINGS_API UEasySettingsLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	/**
	 * @brief Retrieves the class of the settings setter.
	 * 
	 * Returns the class type of the settings setter defined in the developer settings.
	 * 
	 * @return A TSubclassOf representing the class type of UEasySettingsSetter.
	 */
	UFUNCTION(BlueprintCallable, Category="UEasySettingsLib")
	static TSubclassOf<UEasySettingsSetter> GetSettingsSetterClass();

	/**
	 * @brief Retrieves the developer settings for the Easy Settings subsystem.
	 * 
	 * This function returns the developer settings object that contains configurations for the Easy Settings subsystem.
	 * 
	 * @return A pointer to a const UEasySettingsSubsystemDeveloperSettings instance.
	 */
	UFUNCTION(BlueprintCallable, Category="UEasySettingsLib")
	static const UEasySettingsSubsystemDeveloperSettings* GetDeveloperSettings();
};
