#include "StylizationSubsystem.h"
#include "CustomSceneViewExtension.h"
#include "SceneViewExtension.h"

void UStylizationSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	CustomSceneViewExtension = FSceneViewExtensions::NewExtension<FCustomSceneViewExtension>();
	
	// Initialize extension with default settings
	if (CustomSceneViewExtension.IsValid())
	{
		CustomSceneViewExtension->UpdateSettings(CurrentSettings);
	}
	
	UE_LOG(LogTemp, Log, TEXT("StylizationPP: Subsystem initialized & SceneViewExtension created"));
}

void UStylizationSubsystem::Deinitialize()
{
	{
		CustomSceneViewExtension->IsActiveThisFrameFunctions.Empty();

		FSceneViewExtensionIsActiveFunctor IsActiveFunctor;

		IsActiveFunctor.IsActiveFunction = [](const ISceneViewExtension* SceneViewExtension, const FSceneViewExtensionContext& Context)
			{
				return TOptional<bool>(false);
			};

		CustomSceneViewExtension->IsActiveThisFrameFunctions.Add(IsActiveFunctor);
	}

	CustomSceneViewExtension.Reset();
	CustomSceneViewExtension = nullptr;
}

FStylizationSettings UStylizationSubsystem::GetSettings() const
{
	FScopeLock Lock(&SettingsCriticalSection);
	return CurrentSettings;
}

void UStylizationSubsystem::SetSettings(const FStylizationSettings& NewSettings)
{
	{
		FScopeLock Lock(&SettingsCriticalSection);
		CurrentSettings = NewSettings;
	}
	
	// Notify the scene view extension about the settings change
	if (CustomSceneViewExtension.IsValid())
	{
		CustomSceneViewExtension->UpdateSettings(NewSettings);
	}
}