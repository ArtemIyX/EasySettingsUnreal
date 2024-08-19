// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameUserSettings.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "EasySettingsSubsystem.generated.h"

UENUM(Blueprintable, BlueprintType)
enum class ESettingsType : uint8
{
	TYPE_NONE UMETA(Hidden),
	TYPE_AA UMETA(DisplayName="Anti Aliasing"),
	TYPE_Textures UMETA(DisplayName="Textures"),
	TYPE_Effects UMETA(DisplayName="Effects"),
	TYPE_Details UMETA(DisplayName="Details"),
	TYPE_Shadows UMETA(DisplayName="Shadows"),
	TYPE_MAX UMETA(Hidden)
};

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class EASYSETTINGS_API UEasySettingsSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="GameSettingsSubsystem|Graphics|Extra")
	void SetSettingsQuality(ESettingsType InSettingsType = ESettingsType::TYPE_Details, int32 InQuality = 3, bool bApply = true);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="GameSettingsSubsystem|Graphics|Extra")
	int32 GetSettingsQuality(ESettingsType InSettingsType = ESettingsType::TYPE_Details) const;
	
	UFUNCTION(BlueprintCallable, Category="GameSettingsSubsystem|Graphics|Extra")
	void SetAntialiasingMethod(
		APlayerController* InController,
		int32 InValue,
		bool bApply = true);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="GameSettingsSubsystem|Graphics|Extra")
	int32 GetAntialiasingMethod() const;

	UFUNCTION(BlueprintCallable, Category="GameSettingsSubsystem|Graphics|Extra")
	void SetAntialiasingQuality(int32 InValue, bool bApply = true);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="GameSettingsSubsystem|Graphics|Extra")
	int32 GetAntialiasingQuality() const;
	
	UFUNCTION(BlueprintCallable, Category="GameSettingsSubsystem|Graphics|Extra")
	void SetTextureQuality(int32 InValue, bool bApply = true);
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="GameSettingsSubsystem|Graphics|Extra")
	int32 GetTextureQuality() const;

	UFUNCTION(BlueprintCallable, Category="GameSettingsSubsystem|Graphics|Extra")
	void SetEffectsQuality(int32 InValue, bool bApply = true);
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="GameSettingsSubsystem|Graphics|Extra")
	int32 GetEffectsQuality() const;

	UFUNCTION(BlueprintCallable, Category="GameSettingsSubsystem|Graphics|Extra")
	void SetDetailsQuality(int32 InValue, bool bApply = true);

	UFUNCTION(BlueprintCallable, Category="GameSettingsSubsystem|Graphics|Extra")
	int32 GetDetailsQuality() const;

	UFUNCTION(BlueprintCallable)
	void SetVsyncEnabled(bool bInValue, bool bApply = true);
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="GameSettingsSubsystem|Graphics|Extra")
	bool GetVsyncEnabled() const;

	UFUNCTION(BlueprintCallable)
	void SetFrameRateLimit(int32 InValue, bool bApply = true);
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="GameSettingsSubsystem|Graphics|Extra")
	int32 GetFrameRateLimit() const;

	UFUNCTION(BlueprintCallable, Category="GameSettingsSubsystem|Graphics|Extra")
	void SetShadowsQuality(int32 InValue, bool bApply = true);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="GameSettingsSubsystem|Graphics|Extra")
	int32 GetShadowsQuality() const;
	
	UFUNCTION(BlueprintCallable, Category="GameSettingsSubsystem|Window")
	void SetWindowedMode(
		TEnumAsByte<EWindowMode::Type> InWindowMode = EWindowMode::Type::Windowed,
		bool bApply = true);

	UFUNCTION(BlueprintCallable, Category="GameSettingsSubsystem|Window")
	TEnumAsByte<EWindowMode::Type> GetCurrentWindowedMode() const;

	UFUNCTION(BlueprintCallable, Category="GameSettingsSubsystem|Window")
	FIntPoint GetCurrentResolution() const;
	
	UFUNCTION(BlueprintCallable, Category="GameSettingsSubsystem|Window")
	void SetResolution(FIntPoint InResolution, bool bApply = true);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="GameSettingsSubsystem|Window")
	TEnumAsByte<EWindowMode::Type> GetFullscreenMode() const { return GetGameUserSettings()->GetFullscreenMode(); }

	UFUNCTION(BlueprintCallable, Category="GameSettingsSubsystem|Window")
	void GetSupportedResolutions(TArray<FIntPoint>& OutResult, TEnumAsByte<EWindowMode::Type> InWindowMode = EWindowMode::Type::Windowed);

	UFUNCTION(BlueprintCallable, Category="GameSettingsSubsystem|Misc")
	void ApplySettings();

	UFUNCTION(BlueprintCallable, Category="GameSettingsSubsystem|Misc")
	UGameUserSettings* GetGameUserSettings() const { return GEngine->GameUserSettings; }
};
