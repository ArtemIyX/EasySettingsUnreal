// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/EasySettingsSetter.h"

FEasySettingsContainerValue::FEasySettingsContainerValue()
{
	bDefaultValue = true;
	Value = 0.0f;
}

void UEasySettingsSetter::InitializeEmpty()
{
	Values.Empty();
	int32 n = EasySettings::VALUES_NUM;
	Values.Reserve(n);
	for (uint8 i = 0; i < n; ++i)
	{
		Values.Add(i, FEasySettingsContainerValue());
	}
}

void UEasySettingsSetter::SetValue_Implementation(uint8 InCategory, float InValue)
{
	if (!Values.Contains(InCategory))
	{
		return;
	}
	Values[InCategory].bDefaultValue = false;
	Values[InCategory].Value = InValue;
}

void UEasySettingsSetter::ResetValue_Implementation(uint8 InCategory)
{
	if(Values.Contains(InCategory))
	{
		Values[InCategory].bDefaultValue = true;
		Values[InCategory].Value = 0.0f;
	}
}

bool UEasySettingsSetter::GetValue(uint8 InCategory, float& OutValue, bool& bOutDefault)
{
	if (!Values.Contains(InCategory))
	{
		OutValue = 0.0f;
		bOutDefault = true;
		return false;
	}
	OutValue = Values[InCategory].Value;
	bOutDefault = Values[InCategory].bDefaultValue;
	return true;
}

void UEasySettingsSetter::Read(FMemoryReader& MemoryReader)
{
	InitializeEmpty();
	int32 n = EasySettings::VALUES_NUM;
	// Read each element
	for (uint8 i = 0; i < n; ++i)
	{
		bool bDefault;
		MemoryReader << bDefault;
		float elementValue;
		MemoryReader << elementValue;
		Values[i].bDefaultValue = bDefault == 1;
		Values[i].Value = elementValue;
	}
}

void UEasySettingsSetter::Write(FMemoryWriter& MemoryWriter)
{
	int n = EasySettings::VALUES_NUM;
	check((Values.Num() == n));
	// Write each float element
	for (const TTuple<EasySettings::MapKey, EasySettings::MapValue>& pair : Values)
	{
		bool bDefault = pair.Value.bDefaultValue;
		MemoryWriter << bDefault;
		float value = pair.Value.Value;
		MemoryWriter << value;
	}
}
