// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/EngineSubsystem.h"
#include "StylizationSettings.h"
#include "StylizationSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class STYLIZATIONPP_API UStylizationSubsystem : public UEngineSubsystem
{
	GENERATED_BODY()
	
public:

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	/** Get current stylization settings (thread-safe) */
	FStylizationSettings GetSettings() const;

	/** Set stylization settings (thread-safe) */
	void SetSettings(const FStylizationSettings& NewSettings);

	/** Get the scene view extension (for internal use) */
	TSharedPtr<class FCustomSceneViewExtension, ESPMode::ThreadSafe> GetSceneViewExtension() const { return CustomSceneViewExtension; }

private:
	TSharedPtr<class FCustomSceneViewExtension, ESPMode::ThreadSafe> CustomSceneViewExtension;
	
	/** Thread-safe settings storage */
	mutable FCriticalSection SettingsCriticalSection;
	FStylizationSettings CurrentSettings;
};
