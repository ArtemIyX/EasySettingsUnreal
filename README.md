# Settings subsystem plugin for Unreal 5.3
![Screenshot](https://cdn.discordapp.com/attachments/1026083841791754250/1275094154103492659/image.png?ex=66c4a378&is=66c351f8&hm=8b900b4e5ce54f78610e930cf767738d37eb411936d51824abf266dcd183e3d7&)
A subsystem that extends and augments game settings, includes changing console variables and more.

# Settings setter
If your game needs to record custom variables of float format like FOV, sensitivity, music volume, brightness, etc. you can use methods of saving variables to a container.
```C++
UEasySettingsSubsystem* subsystem = ...;
subsystem->SetContainerValue(/*uint8 InCategory/* 10, /*float InValue*/ 52.0f, /*bool bApply*/ true)
```
![Screenshot2](https://cdn.discordapp.com/attachments/1026083841791754250/1275424560677912576/image.png?ex=66c5d72f&is=66c485af&hm=b024f13b98fcd9701847a7922275a69b9a0eebed57f803738990c712529b8051&)
The function writes data to disk, so make sure you have included all the dependencies listed below.
You can change the name of the save file, as well as overwrite the settings container class.
This can be useful for reacting to changes in variables. For example, if you change the brightness variable, you can change the camera settings.

![Screenshot3](https://cdn.discordapp.com/attachments/1026083841791754250/1275424914853335060/image.png?ex=66c5d783&is=66c48603&hm=d92b926d7c0b74fb3b127938be97b9806f2d9a9e37ea9e851b9ea8743989d932&)

```C++
UFUNCTION(BlueprintNativeEvent)
	void SetValue(uint8 InCategory, float InValue);
```

# Dependencies
- [DataSerializer](https://github.com/ArtemIyX/DataSerializerUnreal)

# Documentation
Doxygen documentation: [GitHubPages](https://artemiyx.github.io/EasySettingsUnrealDoc/annotated.html)

Documentation sources: [GitHub](https://github.com/ArtemIyX/EasySettingsUnrealDoc)
