// Fill out your copyright notice in the Description page of Project Settings.


#include "Libs/EasySettingsLib.h"

TSubclassOf<UEasySettingsSetter> UEasySettingsLib::GetSettingsSetterClass()
{
	return GetDeveloperSettings()->SettingsSetterClass;
}

FString UEasySettingsLib::GetContainerSaveName()
{
	return GetDeveloperSettings()->ContainerSaveName;
}

const UEasySettingsSubsystemDeveloperSettings* UEasySettingsLib::GetDeveloperSettings()
{
	return GetDefault<UEasySettingsSubsystemDeveloperSettings>();
}

FString UEasySettingsLib::GetConfigPath()
{
	return IsWithEditor() ? GetProjectConfigPath() : GetProjectDir();
}

FString UEasySettingsLib::GetProjectConfigPath()
{
	return FString(FPaths::ProjectConfigDir());
}

FString UEasySettingsLib::GetProjectDir()
{
	return FString(FPaths::ProjectDir());
}

bool UEasySettingsLib::IsWithEditor()
{
#if WITH_EDITOR
	return true;
#else
	return false;
#endif
}

FString UEasySettingsLib::GetProjectVersion()
{
	FString projectVersion;
	GConfig->GetString(
		TEXT("/Script/EngineSettings.GeneralProjectSettings"),
		TEXT("ProjectVersion"),
		projectVersion, GGameIni);
	return projectVersion;
}

FString UEasySettingsLib::RelativePathToFull(FString InRelativePath)
{
	return FPaths::ConvertRelativePathToFull(InRelativePath);
}
