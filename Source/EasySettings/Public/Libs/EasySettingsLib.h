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
	
	UFUNCTION(BlueprintCallable, Category="UEasySettingsLib")
	static FString GetContainerSaveName();

	/**
	 * @brief Retrieves the developer settings for the Easy Settings subsystem.
	 * 
	 * This function returns the developer settings object that contains configurations for the Easy Settings subsystem.
	 * 
	 * @return A pointer to a const UEasySettingsSubsystemDeveloperSettings instance.
	 */
	UFUNCTION(BlueprintCallable, Category="UEasySettingsLib")
	static const UEasySettingsSubsystemDeveloperSettings* GetDeveloperSettings();

	/**
	 * @brief Retrieves the configuration path based on whether the editor is active or not.
	 * 
	 * This function returns the project configuration path if the editor is active (i.e., `IsWithEditor()` returns true). 
	 * Otherwise, it returns the project directory path.
	 * @see GetProjectConfigPath
	 * @see GetProjectDir
	 * @see IsWithEditor
	 * 
	 * @return The configuration path as a string. The path returned depends on whether the editor is running or not.
	 */
	UFUNCTION(BlueprintCallable, Category="UEasySettingsLib")
	static FString GetConfigPath();

	/**
	 * @brief Retrieves the path to the project's configuration directory.
	 * 
	 * Simply returns the result of `FPaths::ProjectConfigDir()`.
	 * 
	 * @return The project's configuration directory path as a string.
	 */
	UFUNCTION(BlueprintCallable, Category="UEasySettingsLib")
	static FString GetProjectConfigPath();

	/**
	 * @brief Retrieves the path to the project's root directory.
	 * 
	 * Simply returns the result of `FPaths::ProjectDir()`.
	 * 
	 * @return The project's root directory path as a string.
	 */
	UFUNCTION(BlueprintCallable, Category="UEasySettingsLib")
	static FString GetProjectDir();

	/**
	 * @brief Checks whether the editor is currently running.
	 * 
	 * Determined by the `WITH_EDITOR` macro.
	 * 
	 * @return True if the editor is running, false otherwise.
	 */
	UFUNCTION(BlueprintCallable, Category="UEasySettingsLib")
	static bool IsWithEditor();

	/**
	 * @brief Retrieves the version of the project.
	 * 
	 * Reads the project version from the configuration file specified by `GGameIni` and the section
	 * `/Script/EngineSettings.GeneralProjectSettings`.
	 * 
	 * @return The project version as a string.
	 */
	UFUNCTION(BlueprintCallable, Category="UEasySettingsLib")
	static FString GetProjectVersion();

	/**
	 * @brief Converts a relative path to an absolute path.
	 * 
	 * If the provided path is already absolute, it is returned unchanged. Otherwise, it is converted to an absolute path 
	 * using `FPaths::ConvertRelativePathToFull()`.
	 * 
	 * @param InRelativePath The relative path to convert.
	 * @return The absolute path corresponding to the input relative path.
	 */
	UFUNCTION(BlueprintCallable, Category="UEasySettingsLib")
	static FString RelativePathToFull(FString InRelativePath);
};
