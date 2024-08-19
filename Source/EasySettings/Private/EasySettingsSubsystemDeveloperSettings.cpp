// Fill out your copyright notice in the Description page of Project Settings.


#include "EasySettingsSubsystemDeveloperSettings.h"

#include "Data/EasySettingsSetter.h"

UEasySettingsSubsystemDeveloperSettings::UEasySettingsSubsystemDeveloperSettings(
	const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SettingsSetterClass = UEasySettingsSetter::StaticClass();
	ContainerSaveName = "Config.bin";
}
