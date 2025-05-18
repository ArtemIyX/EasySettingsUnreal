// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Data/EasySettingsSetter.h"
#include "GameFramework/GameUserSettings.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "EasySettingsSubsystem.generated.h"

/**
 * ESettingsType
 * 
 * An enumeration representing different types of graphical settings in the game.
 */
UENUM(Blueprintable, BlueprintType)
enum class ESettingsType : uint8
{
	/** Represents an invalid or uninitialized setting type. */
	TYPE_NONE UMETA(Hidden),

	/** Represents the Anti-Aliasing quality setting. */
	TYPE_AA UMETA(DisplayName="Anti Aliasing"),

	/** Represents the Texture quality setting. */
	TYPE_Textures UMETA(DisplayName="Textures"),

	/** Represents the Effects quality setting. */
	TYPE_Effects UMETA(DisplayName="Effects"),

	/** Represents the Shadows quality setting. */
	TYPE_Shadows UMETA(DisplayName="Shadows"),

	TYPE_Foliage UMETA(DisplayName="Foliage"),

	TYPE_Reflection UMETA(DisplayName="Reflection"),

	TYPE_GlobalIllumination UMETA(DisplayName="Global Illumination"),

	TYPE_ViewDistance UMETA(DisplayName="View Distance"),

	/** Represents the maximum value for this enum, used internally. */
	TYPE_MAX UMETA(Hidden)
};


/**
 * UEasySettingsSubsystem
 * 
 * A subsystem designed to handle various graphical and system settings within the game. It allows the user to get and set
 * settings related to graphics quality, resolution, VSync, frame rate limits, and window modes. This subsystem is intended to
 * be used within a game instance to control and apply user settings.
 */
UCLASS(BlueprintType, Blueprintable)
class EASYSETTINGS_API UEasySettingsSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
protected:
	UPROPERTY()
	UEasySettingsSetter* SettingsSetter;
protected:
	void SaveContainer();
	void InitContainer();
	FString GetContainerSavePath();
public:

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	
	/**
	 * Sets the quality of a specific setting type.
	 * 
	 * @param InSettingsType The type of setting to adjust (e.g., Anti-Aliasing, Textures).
	 * @param InQuality The quality level to set (typically 0 to 4).
	 * @param bApply Whether to immediately apply the setting.
	 */
	UFUNCTION(BlueprintCallable, Category="GameSettingsSubsystem|Graphics|Extra")
	void SetSettingsQuality(ESettingsType InSettingsType = ESettingsType::TYPE_Effects, int32 InQuality = 3,
	                        bool bApply = true);

	/**
	 * Retrieves the current quality level of a specific setting type.
	 * 
	 * @param InSettingsType The type of setting to query.
	 * @return The current quality level of the specified setting.
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="GameSettingsSubsystem|Graphics|Extra")
	int32 GetSettingsQuality(ESettingsType InSettingsType = ESettingsType::TYPE_Effects) const;

	/**
	* Sets the Anti-Aliasing method.
	* 
	* @param InController The player controller that will execute the command.
	* @param InValue The method index (typically 0 to 4).
	* @param bApply Whether to immediately apply the setting.
	*/
	UFUNCTION(BlueprintCallable, Category="GameSettingsSubsystem|Graphics|Extra")
	void SetAntialiasingMethod(
		APlayerController* InController,
		int32 InValue,
		bool bApply = true);

	/**
	* Retrieves the current Anti-Aliasing method.
	* 
	* @return The current method index.
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="GameSettingsSubsystem|Graphics|Extra")
	int32 GetAntialiasingMethod() const;

	/**
	 * Sets the Anti-Aliasing quality level.
	 * 
	 * @param InValue The quality level to set (typically 0 to 4).
	 * @param bApply Whether to immediately apply the setting.
	 */
	UFUNCTION(BlueprintCallable, Category="GameSettingsSubsystem|Graphics|Extra")
	void SetAntialiasingQuality(int32 InValue, bool bApply = true);

	/**
	* Retrieves the current Anti-Aliasing quality level.
	* 
	* @return The current Anti-Aliasing quality level.
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="GameSettingsSubsystem|Graphics|Extra")
	int32 GetAntialiasingQuality() const;

	/**
	* Sets the Texture quality level.
	* 
	* @param InValue The quality level to set (typically 0 to 4).
	* @param bApply Whether to immediately apply the setting.
	*/
	UFUNCTION(BlueprintCallable, Category="GameSettingsSubsystem|Graphics|Extra")
	void SetTextureQuality(int32 InValue, bool bApply = true);

	/**
	* Retrieves the current Texture quality level.
	* 
	* @return The current Texture quality level.
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="GameSettingsSubsystem|Graphics|Extra")
	int32 GetTextureQuality() const;

	/**
	 * Sets the Effects quality level.
	 * 
	 * @param InValue The quality level to set (typically 0 to 4).
	 * @param bApply Whether to immediately apply the setting.
	 */
	UFUNCTION(BlueprintCallable, Category="GameSettingsSubsystem|Graphics|Extra")
	void SetEffectsQuality(int32 InValue, bool bApply = true);
	
	/**
	 * Retrieves the current Effects quality level.
	 * 
	 * @return The current Effects quality level.
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="GameSettingsSubsystem|Graphics|Extra")
	int32 GetEffectsQuality() const;

	UFUNCTION(BlueprintCallable, Category="GameSettingsSubsystem|Graphics|Extra")
	void SetFoliageQuality(int32 InValue, bool bApply = true);
	
	UFUNCTION(BlueprintCallable, Category="GameSettingsSubsystem|Graphics|Extra")
	void SetReflectionQuality(int32 InValue, bool bApply = true);
	
	UFUNCTION(BlueprintCallable, Category="GameSettingsSubsystem|Graphics|Extra")
	void SetAudioQualityLevel(int32 InValue, bool bApply = true);
	
	UFUNCTION(BlueprintCallable, Category="GameSettingsSubsystem|Graphics|Extra")
	void SetGlobalIlluminationQuality(int32 InValue, bool bApply = true);
	
	UFUNCTION(BlueprintCallable, Category="GameSettingsSubsystem|Graphics|Extra")
	void SetViewDistanceQuality(int32 InValue, bool bApply = true);

	UFUNCTION(BlueprintCallable, Category="GameSettingsSubsystem|Graphics|Extra")
	int32 GetFoliageQuality() const;
	
	UFUNCTION(BlueprintCallable, Category="GameSettingsSubsystem|Graphics|Extra")
	int32 GetReflectionQuality() const;

	UFUNCTION(BlueprintCallable, Category="GameSettingsSubsystem|Graphics|Extra")
	int32 GetAudioQualityLevel() const;
	
	UFUNCTION(BlueprintCallable, Category="GameSettingsSubsystem|Graphics|Extra")
	int32 GetGlobalIlluminationQuality() const;

	UFUNCTION(BlueprintCallable, Category="GameSettingsSubsystem|Graphics|Extra")
	int32 GetViewDistanceQuality() const;
	/**
	 * Enables or disables VSync.
	 * 
	 * @param bInValue Whether VSync should be enabled.
	 * @param bApply Whether to immediately apply the setting.
	 */
	UFUNCTION(BlueprintCallable)
	void SetVsyncEnabled(bool bInValue, bool bApply = true);

	/**
	* Checks whether VSync is currently enabled.
	* 
	* @return True if VSync is enabled, false otherwise.
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="GameSettingsSubsystem|Graphics|Extra")
	bool GetVsyncEnabled() const;

	/**
	 * Sets the frame rate limit.
	 * 
	 * @param InValue The frame rate limit to set (e.g., 60 for 60 FPS, 0 for unlimited).
	 * @param bApply Whether to immediately apply the setting.
	 */
	UFUNCTION(BlueprintCallable)
	void SetFrameRateLimit(int32 InValue, bool bApply = true);

	/**
	* Retrieves the current frame rate limit.
	* 
	* @return The current frame rate limit.
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="GameSettingsSubsystem|Graphics|Extra")
	int32 GetFrameRateLimit() const;
	
	/**
	 * Sets the Shadows quality level.
	 *
	 * @param InValue The quality level to set (typically 0 to 4).
	 * @param bApply Whether to immediately apply the setting.
	 */
	UFUNCTION(BlueprintCallable, Category="GameSettingsSubsystem|Graphics|Extra")
	void SetShadowsQuality(int32 InValue, bool bApply = true);

	/**
	 * Sets the Overall quality level.
	 *
	 * @param InValue The quality level to set (typically 0 to 4).
	 * @param bApply Whether to immediately apply the setting.
	 */
	UFUNCTION(BlueprintCallable, Category="GameSettingsSubsystem|Graphics|Extra")
	void SetOverallQualityLevel(int32 InValue, bool bApply = true);

	/**
	 * Retrieves the current Overall quality level.
	 * 
	 * @return The current Overall quality level.
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="GameSettingsSubsystem|Graphics|Extra")
	int32 GetOverallQualityLevel() const;
	
	/**
	 * @brief Sets the screen percentage scaling factor for rendering.
	 * 
	 * This function allows modifying the `r.ScreenPercentage` console variable, 
	 * which controls the resolution scale of the rendered scene.
	 * 
	 * @param InValue The desired screen percentage (default is 100).
	 * @param bApply If true, applies the new value immediately (default is true).
	 */
	UFUNCTION(BlueprintCallable, Category="GameSettingsSubsystem|Graphics|Extra")
	void SetScreenPercentage(int32 InValue = 100, bool bApply = true);

	/**
	 * @brief Retrieves the current screen percentage scaling factor.
	 * 
	 * This function reads the value of the `r.ScreenPercentage` console variable, 
	 * which determines the resolution scale used for rendering.
	 * 
	 * @return The current screen percentage value.
	 */
	UFUNCTION(BlueprintCallable, Category="GameSettingsSubsystem|Graphics|Extra")
	int32 GetScreenPercentage() const;
	
	/**
	 * Retrieves the current Shadows quality level.
	 * 
	 * @return The current Shadows quality level.
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="GameSettingsSubsystem|Graphics|Extra")
	int32 GetShadowsQuality() const;

	/**
	 * Sets the window mode (fullscreen, windowed, or borderless window).
	 * 
	 * @param InWindowMode The desired window mode.
	 * @param bApply Whether to immediately apply the setting.
	 */
	UFUNCTION(BlueprintCallable, Category="GameSettingsSubsystem|Window")
	void SetWindowedMode(
		TEnumAsByte<EWindowMode::Type> InWindowMode = EWindowMode::Type::Windowed,
		bool bApply = true);

	/**
	 * Retrieves the current window mode.
	 * 
	 * @return The current window mode.
	 */
	UFUNCTION(BlueprintCallable, Category="GameSettingsSubsystem|Window")
	TEnumAsByte<EWindowMode::Type> GetCurrentWindowedMode() const;

	/**
	 * Retrieves the current screen resolution.
	 * 
	 * @return The current screen resolution.
	 */
	UFUNCTION(BlueprintCallable, Category="GameSettingsSubsystem|Window")
	FIntPoint GetCurrentResolution() const;

	/**
	 * Sets the screen resolution.
	 * 
	 * @param InResolution The desired screen resolution.
	 * @param bApply Whether to immediately apply the setting.
	 */
	UFUNCTION(BlueprintCallable, Category="GameSettingsSubsystem|Window")
	void SetResolution(FIntPoint InResolution, bool bApply = true);


	/**
	 * Retrieves the current fullscreen mode.
	 * 
	 * This function returns the current fullscreen mode as configured in the game's settings. The possible modes
	 * include fullscreen, windowed, and borderless windowed.
	 * 
	 * @return The current fullscreen mode as an enum value of type `EWindowMode::Type`.
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="GameSettingsSubsystem|Window")
	TEnumAsByte<EWindowMode::Type> GetFullscreenMode() const { return GetGameUserSettings()->GetFullscreenMode(); }

	/**
	 * Retrieves the supported screen resolutions based on the current window mode.
	 * 
	 * @param OutResult An array that will be filled with the supported resolutions.
	 * @param InWindowMode The window mode to consider (windowed or fullscreen).
	 */
	UFUNCTION(BlueprintCallable, Category="GameSettingsSubsystem|Window")
	void GetSupportedResolutions(TArray<FIntPoint>& OutResult,
	                             TEnumAsByte<EWindowMode::Type> InWindowMode = EWindowMode::Type::Windowed);

	/**
	 * @brief Sets the container value for a specific category.
	 *
	 * This method sets the float value for a given category in the container. 
	 * If the `bApply` flag is true, the settings are applied immediately after setting the value.
	 *
	 * @param InCategory The category key (`uint8`) for which to set the value.
	 * @param InValue The float value to set for the category.
	 * @param bApply If true, applies the settings immediately after setting the value.
	 * 
	 * @note This method is intended to be used within the GameSettingsSubsystem.
	 */
	UFUNCTION(BlueprintCallable, Category="GameSettingsSubsystem|Container")
	void SetContainerValue(uint8 InCategory, float InValue, bool bApply = true);

	/**
	 * @brief Retrieves the container value for a specific category.
	 *
	 * This method gets the float value for a given category in the container.
	 *
	 * @param InCategory The category key (`uint8`) for which to get the value.
	 * @param OutValue A reference to store the retrieved float value.
	 * @return true if the value was successfully retrieved; false otherwise.
	 * 
	 * @note This method is intended to be used within the GameSettingsSubsystem.
	 */
	UFUNCTION(BlueprintCallable, Category="GameSettingsSubsystem|Container")
	void GetContainerValue(uint8 InCategory, float& OutValue,
		bool& bDefault);

	UFUNCTION(BlueprintCallable, Category="GameSettingsSubsystem|Container")
	void ResetContainerValue(uint8 InCategory, bool bApply = true);
	
	/**
	* Applies the current settings, saving them to the user's configuration file.
	*/
	UFUNCTION(BlueprintCallable, Category="GameSettingsSubsystem|Misc")
	void ApplySettings();

	/**
	* Applies the current container values, saving them to the user's configuration file.
	*/
	UFUNCTION(BlueprintCallable, Category="GameSettingsSubsystem|Misc")
	void ApplyContainer();
	
	/**
	* Retrieves the UGameUserSettings instance for this game, which manages user-specific graphics and performance settings.
	* 
	* @return A pointer to the UGameUserSettings instance.
	*/
	UFUNCTION(BlueprintCallable, Category="GameSettingsSubsystem|Misc")
	UGameUserSettings* GetGameUserSettings() const { return GEngine->GameUserSettings; }


};
