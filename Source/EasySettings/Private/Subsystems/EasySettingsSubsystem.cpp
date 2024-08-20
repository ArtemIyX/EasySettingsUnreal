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
	case ESettingsType::TYPE_Details:
		SetDetailsQuality(InQuality, bApply);
		break;
	case ESettingsType::TYPE_Shadows:
		SetShadowsQuality(InQuality, bApply);
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
	case ESettingsType::TYPE_AA: return GetAntialiasingQuality();
	case ESettingsType::TYPE_Textures: return GetTextureQuality();
	case ESettingsType::TYPE_Effects: return GetEffectsQuality();
	case ESettingsType::TYPE_Details: return GetDetailsQuality();
	case ESettingsType::TYPE_Shadows: return GetShadowsQuality();
	default: return 0;
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

void UEasySettingsSubsystem::SetDetailsQuality(int32 InValue, bool bApply)
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
}

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

bool UEasySettingsSubsystem::GetContainerValue(uint8 InCategory, float& OutValue)
{
	if (!IsValid(SettingsSetter))
		return false;
	return SettingsSetter->GetValue(InCategory, OutValue);
}

void UEasySettingsSubsystem::ApplySettings()
{
	GetGameUserSettings()->ApplySettings(true);
	SaveContainer();
}

void UEasySettingsSubsystem::SaveContainer()
{
	if (!IsValid(SettingsSetter))
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
