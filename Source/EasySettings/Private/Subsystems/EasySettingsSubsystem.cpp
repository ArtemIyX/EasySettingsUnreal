// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/EasySettingsSubsystem.h"

#include "Kismet/KismetSystemLibrary.h"
#include "Libs/DataSerializerLib.h"
#include "Libs/EasySettingsLib.h"

void UEasySettingsSubsystem::SetSettingsQuality(ESettingsType InSettingsType, int32 InQuality, bool bApply)
{
	check((InSettingsType != ESettingsType::TYPE_NONE));
	check((InSettingsType != ESettingsType::TYPE_MAX));
	switch (InSettingsType)
	{
		case ESettingsType::TYPE_AA:
			SetAntialiasingQuality(InQuality, bApply);
			break;
		case ESettingsType::TYPE_Textures:
			SetTextureQuality(InQuality, bApply);
			break;
		case ESettingsType::TYPE_Effects:
			SetEffectsQuality(InQuality, bApply);
			break;
		case ESettingsType::TYPE_Shadows:
			SetShadowsQuality(InQuality, bApply);
			break;
		case ESettingsType::TYPE_Foliage:
			SetFoliageQuality(InQuality, bApply);
			break;
		case ESettingsType::TYPE_Reflection:
			SetReflectionQuality(InQuality, bApply);
			break;
		case ESettingsType::TYPE_GlobalIllumination:
			SetGlobalIlluminationQuality(InQuality, bApply);
			break;
		case ESettingsType::TYPE_ViewDistance:
			SetViewDistanceQuality(InQuality, bApply);
			break;
		default: ;
	}
}

int32 UEasySettingsSubsystem::GetSettingsQuality(ESettingsType InSettingsType) const
{
	check((InSettingsType != ESettingsType::TYPE_NONE));
	check((InSettingsType != ESettingsType::TYPE_MAX));
	switch (InSettingsType)
	{
		case ESettingsType::TYPE_AA:
			return GetAntialiasingQuality();
		case ESettingsType::TYPE_Textures:
			return GetTextureQuality();
		case ESettingsType::TYPE_Effects:
			return GetEffectsQuality();
		case ESettingsType::TYPE_Shadows:
			return GetShadowsQuality();
		case ESettingsType::TYPE_Foliage:
			return GetFoliageQuality();
		case ESettingsType::TYPE_Reflection:
			return GetReflectionQuality();
		case ESettingsType::TYPE_GlobalIllumination:
			return GetGlobalIlluminationQuality();
		case ESettingsType::TYPE_ViewDistance:
			return GetViewDistanceQuality();
		default:
			return 0;
	}
}

void UEasySettingsSubsystem::SetAntialiasingMethod(APlayerController* InController, int32 InValue, bool bApply)
{
	if (!IsValid(InController))
		return;

	int32 clamped = FMath::Clamp(InValue, 0, 4);
	InController->ConsoleCommand(FString::Printf(TEXT("r.AntiAliasingMethod %d"), clamped));

	if (bApply)
		ApplySettings();
}

int32 UEasySettingsSubsystem::GetAntialiasingMethod() const
{
	if (IConsoleVariable* antiAliasingMethod = IConsoleManager::Get().FindConsoleVariable(TEXT("r.AntiAliasingMethod")))
	{
		return antiAliasingMethod->GetInt();
	}
	return 0;
}

void UEasySettingsSubsystem::SetAntialiasingQuality(int32 InValue, bool bApply)
{
	GetGameUserSettings()->SetAntiAliasingQuality(InValue);
	if (bApply)
		ApplySettings();
}

void UEasySettingsSubsystem::SetTextureQuality(int32 InValue, bool bApply)
{
	GetGameUserSettings()->SetTextureQuality(InValue);
	if (bApply)
		ApplySettings();
}

int32 UEasySettingsSubsystem::GetTextureQuality() const
{
	return GetGameUserSettings()->GetTextureQuality();
}

int32 UEasySettingsSubsystem::GetAntialiasingQuality() const
{
	return GetGameUserSettings()->GetAntiAliasingQuality();
}

void UEasySettingsSubsystem::SetEffectsQuality(int32 InValue, bool bApply)
{
	UGameUserSettings* settings = GetGameUserSettings();
	check(IsValid(settings));
	settings->SetVisualEffectQuality(InValue);
	settings->SetPostProcessingQuality(InValue);
	settings->SetShadingQuality(InValue);

	if (bApply)
		ApplySettings();
}

int32 UEasySettingsSubsystem::GetEffectsQuality() const
{
	UGameUserSettings* settings = GetGameUserSettings();
	check(IsValid(settings));
	TArray<int32> values = {
		settings->GetVisualEffectQuality(),
		settings->GetPostProcessingQuality(),
		settings->GetShadingQuality()
	};

	return FMath::Min(values);
}

void UEasySettingsSubsystem::SetFoliageQuality(int32 InValue, bool bApply)
{
	UGameUserSettings* settings = GetGameUserSettings();
	check(IsValid(settings));
	settings->SetFoliageQuality(InValue);
	if (bApply)
		ApplySettings();
}

void UEasySettingsSubsystem::SetReflectionQuality(int32 InValue, bool bApply)
{
	UGameUserSettings* settings = GetGameUserSettings();
	check(IsValid(settings));
	settings->SetReflectionQuality(InValue);
	if (bApply)
		ApplySettings();
}

void UEasySettingsSubsystem::SetAudioQualityLevel(int32 InValue, bool bApply)
{
	UGameUserSettings* settings = GetGameUserSettings();
	check(IsValid(settings));
	settings->SetAntiAliasingQuality(InValue);
	if (bApply)
		ApplySettings();
}

void UEasySettingsSubsystem::SetGlobalIlluminationQuality(int32 InValue, bool bApply)
{
	UGameUserSettings* settings = GetGameUserSettings();
	check(IsValid(settings));
	settings->SetGlobalIlluminationQuality(InValue);
	if (bApply)
		ApplySettings();
}

void UEasySettingsSubsystem::SetViewDistanceQuality(int32 InValue, bool bApply)
{
	UGameUserSettings* settings = GetGameUserSettings();
	check(IsValid(settings));
	settings->SetViewDistanceQuality(InValue);
	if (bApply)
		ApplySettings();
}

int32 UEasySettingsSubsystem::GetFoliageQuality() const
{
	UGameUserSettings* settings = GetGameUserSettings();
	check(IsValid(settings));
	return settings->GetFoliageQuality();
}

int32 UEasySettingsSubsystem::GetReflectionQuality() const
{
	UGameUserSettings* settings = GetGameUserSettings();
	check(IsValid(settings));
	return settings->GetReflectionQuality();
}

int32 UEasySettingsSubsystem::GetAudioQualityLevel() const
{
	UGameUserSettings* settings = GetGameUserSettings();
	check(IsValid(settings));
	return settings->GetAudioQualityLevel();
}

int32 UEasySettingsSubsystem::GetGlobalIlluminationQuality() const
{
	UGameUserSettings* settings = GetGameUserSettings();
	check(IsValid(settings));
	return settings->GetGlobalIlluminationQuality();
}

int32 UEasySettingsSubsystem::GetViewDistanceQuality() const
{
	UGameUserSettings* settings = GetGameUserSettings();
	check(IsValid(settings));
	return settings->GetViewDistanceQuality();
}

/*void UEasySettingsSubsystem::SetDetailsQuality(int32 InValue, bool bApply)
{
	UGameUserSettings* settings = GetGameUserSettings();
	check(IsValid(settings));
	settings->SetFoliageQuality(InValue);
	settings->SetReflectionQuality(InValue);
	settings->SetAudioQualityLevel(InValue);
	settings->SetGlobalIlluminationQuality(InValue);
	settings->SetViewDistanceQuality(InValue);
	if (bApply)
		ApplySettings();
}

int32 UEasySettingsSubsystem::GetDetailsQuality() const
{
	UGameUserSettings* settings = GetGameUserSettings();
	check(IsValid(settings));
	TArray<int32> values = {
		settings->GetFoliageQuality(),
		settings->GetReflectionQuality(),
		settings->GetAudioQualityLevel(),
		settings->GetGlobalIlluminationQuality(),
		settings->GetViewDistanceQuality()
	};
	return FMath::Min(values);
}*/

void UEasySettingsSubsystem::SetVsyncEnabled(bool bInValue, bool bApply)
{
	GetGameUserSettings()->SetVSyncEnabled(bInValue);
	if (bApply)
		ApplySettings();
}

bool UEasySettingsSubsystem::GetVsyncEnabled() const
{
	return GetGameUserSettings()->IsVSyncEnabled();
}

void UEasySettingsSubsystem::SetFrameRateLimit(int32 InValue, bool bApply)
{
	GetGameUserSettings()->SetFrameRateLimit(1.0f * InValue);
	if (bApply)
		ApplySettings();
}

int32 UEasySettingsSubsystem::GetFrameRateLimit() const
{
	int32 res = GetGameUserSettings()->GetFrameRateLimit();
	return res;
}

void UEasySettingsSubsystem::SetShadowsQuality(int32 InValue, bool bApply)
{
	GetGameUserSettings()->SetShadowQuality(InValue);
	if (bApply)
		ApplySettings();
}

void UEasySettingsSubsystem::SetOverallQualityLevel(int32 InValue, bool bApply)
{
	GetGameUserSettings()->SetOverallScalabilityLevel(InValue);
	if (bApply)
		ApplySettings();
}

int32 UEasySettingsSubsystem::GetOverallQualityLevel() const
{
	return GetGameUserSettings()->GetOverallScalabilityLevel();
}

void UEasySettingsSubsystem::SetScreenPercentage(int32 InValue, bool bApply)
{
	static auto ScreenPercentageVar = IConsoleManager::Get().FindConsoleVariable(TEXT("r.ScreenPercentage"));
	if (ScreenPercentageVar)
	{
		ScreenPercentageVar->Set(InValue);
	}
	if (bApply)
		ApplySettings();
}

int32 UEasySettingsSubsystem::GetScreenPercentage() const
{
	static const auto ScreenPercentageVar = IConsoleManager::Get().FindConsoleVariable(TEXT("r.ScreenPercentage"));
	if (ScreenPercentageVar)
	{
		int32 screenPercentage = ScreenPercentageVar->GetInt();
		return screenPercentage;
	}
	return 100.0f;
}

int32 UEasySettingsSubsystem::GetShadowsQuality() const
{
	return GetGameUserSettings()->GetShadowQuality();
}

void UEasySettingsSubsystem::SetWindowedMode(TEnumAsByte<EWindowMode::Type> InWindowMode,
	bool bApply)
{
	GetGameUserSettings()->SetFullscreenMode(InWindowMode);
	if (bApply)
		ApplySettings();
}

TEnumAsByte<EWindowMode::Type> UEasySettingsSubsystem::GetCurrentWindowedMode() const
{
	return GetGameUserSettings()->GetFullscreenMode();
}

FIntPoint UEasySettingsSubsystem::GetCurrentResolution() const
{
	return GetGameUserSettings()->GetScreenResolution();
}

void UEasySettingsSubsystem::SetResolution(FIntPoint InResolution, bool bApply)
{
	GetGameUserSettings()->SetScreenResolution(InResolution);
	if (bApply)
		ApplySettings();
}

void UEasySettingsSubsystem::GetSupportedResolutions(TArray<FIntPoint>& OutResult,
	TEnumAsByte<EWindowMode::Type> InWindowMode)
{
	if (InWindowMode == EWindowMode::Type::Windowed)
	{
		UKismetSystemLibrary::GetConvenientWindowedResolutions(OutResult);
		return;
	}

	UKismetSystemLibrary::GetSupportedFullscreenResolutions(OutResult);
}

void UEasySettingsSubsystem::SetContainerValue(uint8 InCategory, float InValue, bool bApply)
{
	if (!IsValid(SettingsSetter))
		return;
	SettingsSetter->SetValue(InCategory, InValue);
	if (bApply)
		ApplySettings();
}

void UEasySettingsSubsystem::GetContainerValue(uint8 InCategory, float& OutValue, bool& bDefault)
{
	if (!IsValid(SettingsSetter))
		return;
	SettingsSetter->GetValue(InCategory, OutValue, bDefault);
}

void UEasySettingsSubsystem::ResetContainerValue(uint8 InCategory, bool bApply)
{
	if (!IsValid(SettingsSetter))
		return;
	SettingsSetter->ResetValue(InCategory);

	if (bApply)
		ApplySettings();
}

void UEasySettingsSubsystem::ApplySettings()
{
	GetGameUserSettings()->ApplySettings(true);
	SaveContainer();
}

void UEasySettingsSubsystem::ApplyContainer()
{
	SaveContainer();
}

void UEasySettingsSubsystem::SaveContainer()
{
	if (!IsValid(SettingsSetter))
		return;

	if (!UEasySettingsLib::ShouldUseContainer())
		return;

	// Prepare empty byte container
	TArray<uint8> bytes;
	FMemoryWriter writer(bytes);

	// Write bytes from settings
	SettingsSetter->Write(writer);

	// Save to file
	FString path = GetContainerSavePath();
	UDataSerializerLib::WriteBytesToDiskCompressed(bytes, path);
}

void UEasySettingsSubsystem::InitContainer()
{
	if (!UEasySettingsLib::ShouldUseContainer())
		return;

	// Destroy previous container
	if (IsValid(SettingsSetter))
	{
		SettingsSetter->ConditionalBeginDestroy();
		SettingsSetter = nullptr;
	}
	// Create setter based on class from settings
	TSubclassOf<UEasySettingsSetter> settingsSetterClass = UEasySettingsLib::GetSettingsSetterClass();
	SettingsSetter = NewObject<UEasySettingsSetter>(this, settingsSetterClass);

	// Try to read container from disk
	FString path = GetContainerSavePath();
	// File must exist
	if (FPaths::FileExists(path))
	{
		// Read bytes from disk
		TArray<uint8> fileBytes;
		if (UDataSerializerLib::ReadCompressedBytesFromDisk(fileBytes, path))
		{
			// Fill settings data
			FMemoryReader reader(fileBytes);
			SettingsSetter->Read(reader);
		}
	}
	else
	{
		SettingsSetter->InitializeEmpty();
		// Save to disk again (create file if not created)
		SaveContainer();
	}
}

FString UEasySettingsSubsystem::GetContainerSavePath()
{
	FString folder = UEasySettingsLib::GetConfigPath();
	FString name = UEasySettingsLib::GetContainerSaveName();
	FString path = folder / name;
	return path;
}

void UEasySettingsSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	InitContainer();
}

void UEasySettingsSubsystem::Deinitialize()
{
	ApplySettings();
	Super::Deinitialize();
}