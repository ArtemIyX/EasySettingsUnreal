// Fill out your copyright notice in the Description page of Project Settings.


#include "Libs/EasySettingsLib.h"

TSubclassOf<UEasySettingsSetter> UEasySettingsLib::GetSettingsSetterClass()
{
	return GetDeveloperSettings()->SettingsSetterClass;
}

const UEasySettingsSubsystemDeveloperSettings* UEasySettingsLib::GetDeveloperSettings()
{
	return GetDefault<UEasySettingsSubsystemDeveloperSettings>();
}
