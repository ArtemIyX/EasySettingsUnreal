// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EasySettingsSetter.generated.h"

namespace EasySettings
{
	constexpr int32 VALUES_NUM = 256;
	typedef uint8 MapKey;
	typedef float MapValue;
	typedef TMap<EasySettings::MapKey, EasySettings::MapValue> FContainer;
}


/**
 * @brief A class that manages categorized float values.
 * 
 * UEasySettingsSetter is designed to store, retrieve, and serialize float values that are categorized by an `uint8` key.
 * It provides functionality to initialize, set, get, read, and write these categorized values.
 */
UCLASS(Blueprintable, BlueprintType)
class EASYSETTINGS_API UEasySettingsSetter : public UObject
{
	GENERATED_BODY()

protected:
	/** 
	 * @brief A map that stores float values categorized by an `uint8` key.
	 * 
	 * The map allows for fast retrieval and update of float values based on their category.
	 */
	EasySettings::FContainer Values;
public:

	/**
	 * @brief Initializes the Values map with default float values.
	 * 
	 * Clears the existing map, reserves space for the required number of categories (as defined by `VALUES_NUM`),
	 * and initializes each category with a default value of 0.0f.
	 * 
	 * @note This method is intended to be overridden in Blueprints.
	 */
	UFUNCTION(BlueprintNativeEvent)
	void InitializeEmpty();

	/**
	 * @brief Sets the float value for a specific category.
	 * 
	 * If the provided category exists in the Values map, this method updates the associated float value.
	 * If the category does not exist, no action is taken.
	 * 
	 * @param InCategory The category key (`uint8`) for which to set the value.
	 * @param InValue The float value to assign to the category.
	 * 
	 * @note This method is intended to be overridden in Blueprints.
	 */
	UFUNCTION(BlueprintNativeEvent)
	void SetValue(uint8 InCategory, float InValue);

	/**
	 * @brief Retrieves the float value associated with a specific category.
	 * 
	 * If the category exists, the method assigns the associated float value to the provided reference and returns true.
	 * If the category does not exist, the method returns false.
	 * 
	 * @param InCategory The category key (`uint8`) for which to retrieve the value.
	 * @param OutValue A reference to store the retrieved float value.
	 * @return true if the category exists and the value is retrieved successfully.
	 * @return false if the category does not exist.
	 */
	UFUNCTION()
	virtual bool GetValue(uint8 InCategory, float& OutValue);

	/**
	 * @brief Reads and deserializes float values from a memory stream.
	 * 
	 * This method reads float values from the provided `FMemoryReader` and populates the Values map with these values.
	 * It first calls `InitializeEmpty()` to ensure the map is properly initialized before reading.
	 * 
	 * @param MemoryReader A reference to the `FMemoryReader` from which to read the data.
	 */
	virtual void Read(FMemoryReader& MemoryReader);

	/**
	 * @brief Writes and serializes the float values to a memory stream.
	 * 
	 * This method serializes the current values in the Values map and writes them to the provided `FMemoryWriter`.
	 * It asserts that the number of elements in the map matches the expected number (`VALUES_NUM`).
	 * 
	 * @param MemoryWriter A reference to the `FMemoryWriter` to which the data will be written.
	 */
	virtual void Write(FMemoryWriter& MemoryWriter);
};
