// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"
#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"
#include "Interfaces/IPluginManager.h"

class FStylizationPPModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	void RegisterMenus();

#if WITH_EDITOR
	void PluginButtonClicked();
	TSharedPtr<class FUICommandList> PluginCommands;
#endif
};
