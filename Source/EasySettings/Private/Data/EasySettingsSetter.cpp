// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/EasySettingsSetter.h"

void UEasySettingsSetter::InitializeEmpty()
{
	Values.Empty();
	int32 n = EasySettings::VALUES_NUM;
	Values.Reserve(n);
	for (uint8 i = 0; i < n; ++i)
	{
		Values.Add(i, 0.0f);
	}
}

void UEasySettingsSetter::SetValue_Implementation(uint8 InCategory, float InValue)
{
	if (!Values.Contains(InCategory))
	{
		return;
	}
	Values[InCategory] = InValue;
}

bool UEasySettingsSetter::GetValue(uint8 InCategory, float& OutValue)
{
	if (!Values.Contains(InCategory))
	{
		return false;
	}
	OutValue = Values[InCategory];
	return true;
}

void UEasySettingsSetter::Read(FMemoryReader& MemoryReader)
{
	InitializeEmpty();
	int32 n = EasySettings::VALUES_NUM;
	// Read each element
	for (uint8 i = 0; i < n; ++i)
	{
		float elementValue;
		MemoryReader << elementValue;
		Values[i] = elementValue;
	}
}

void UEasySettingsSetter::Write(FMemoryWriter& MemoryWriter)
{
	int n = EasySettings::VALUES_NUM;
	check((Values.Num() == n));
	// Write each float element
	for (TTuple<uint8, float> el : Values)
	{
		MemoryWriter << el.Value;
	}
}
