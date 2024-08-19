// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "EasySettingsSubsystemDeveloperSettings.generated.h"

class UEasySettingsSetter;
/**
 * 
 */
UCLASS(Config=Editor, defaultconfig, meta = (DisplayName="Easy Settings"))
class EASYSETTINGS_API UEasySettingsSubsystemDeveloperSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UEasySettingsSubsystemDeveloperSettings(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
public:
	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, NoClear, Category="Container")
	TSubclassOf<UEasySettingsSetter> SettingsSetterClass;

	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category="Container")
	FString ContainerSaveName;
};
