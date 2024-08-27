# Settings subsystem plugin for Unreal 5.3
![Screenshot1](https://github.com/user-attachments/assets/702162bf-2f2c-471d-b785-042da85ec4c1)

A subsystem that extends and augments game settings, includes changing console variables and more.

## Settings setter
If your game needs to record custom variables of float format like FOV, sensitivity, music volume, brightness, etc. you can use methods of saving variables to a container.
```C++
UEasySettingsSubsystem* subsystem = ...;
subsystem->SetContainerValue(/*uint8 InCategory/* 10, /*float InValue*/ 52.0f, /*bool bApply*/ true)
```
![Screenshot2](https://github.com/user-attachments/assets/7b69b7ed-b30a-4a77-8821-fcb34adeb306)

The function writes data to disk, so make sure you have included all the dependencies listed below.
You can change the name of the save file, as well as overwrite the settings container class.
This can be useful for reacting to changes in variables. For example, if you change the brightness variable, you can change the camera settings.

![Screenshot3](https://github.com/user-attachments/assets/818fa496-7507-4cb6-a74c-e21925af97c7)


```C++
UFUNCTION(BlueprintNativeEvent)
	void SetValue(uint8 InCategory, float InValue);
```

## Dependencies
- [DataSerializer](https://github.com/ArtemIyX/DataSerializerUnreal)

## Documentation
Doxygen documentation: [GitHubPages](https://artemiyx.github.io/EasySettingsUnrealDoc/annotated.html)

Documentation sources: [GitHub](https://github.com/ArtemIyX/EasySettingsUnrealDoc)
