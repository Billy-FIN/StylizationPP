// Copyright Epic Games, Inc. All Rights Reserved.

#include "StylizationPP.h"

#if WITH_EDITOR
#include "StylizationPPCommands.h"
#include "StylizationPPStyle.h"
#include "StylizationSettingsWidget.h"
#include "ToolMenus.h"
#include "LevelEditor.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Widgets/SWindow.h"
#include "Framework/Application/SlateApplication.h"
#include "Styling/AppStyle.h"
#include "Interfaces/IPluginManager.h"
#endif

#define LOCTEXT_NAMESPACE "FStylizationPPModule"

void FStylizationPPModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	FString PluginShaderDir = FPaths::Combine(IPluginManager::Get().FindPlugin(TEXT("StylizationPP"))->GetBaseDir(), TEXT("Shaders"));
	AddShaderSourceDirectoryMapping(TEXT("/Plugins/StylizationPP"), PluginShaderDir);

#if WITH_EDITOR
	FStylizationPPStyle::Initialize();
	FStylizationPPCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FStylizationPPCommands::Get().OpenStylizationSettings,
		FUIAction(
			FExecuteAction::CreateRaw(this, &FStylizationPPModule::PluginButtonClicked)
		));

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FStylizationPPModule::RegisterMenus));
#endif
}

void FStylizationPPModule::ShutdownModule()
{
#if WITH_EDITOR
	UToolMenus::UnRegisterStartupCallback(this);
	UToolMenus::UnregisterOwner(this);
	FStylizationPPCommands::Unregister();
	FStylizationPPStyle::Shutdown();
#endif
}

#if WITH_EDITOR
void FStylizationPPModule::PluginButtonClicked()
{
	// Create the widget
	TSharedRef<SStylizationSettingsWidget> SettingsWidget = SNew(SStylizationSettingsWidget);

	// Create the window
	TSharedRef<SWindow> Window = SNew(SWindow)
		.Title(FText::FromString(TEXT("Stylization Settings")))
		.ClientSize(FVector2D(500, 400))
		.SupportsMaximize(false)
		.SupportsMinimize(false)
		[
			SettingsWidget
		];

	// Show the window
	FSlateApplication::Get().AddWindow(Window);
}

void FStylizationPPModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.PlayToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("PluginTools");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FStylizationPPCommands::Get().OpenStylizationSettings));
				Entry.SetCommandList(PluginCommands);
				Entry.Icon = FSlateIcon(FStylizationPPStyle::GetStyleSetName(), "StylizationPP.OpenStylizationSettings");
			}
		}
	}
}
#endif

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FStylizationPPModule, StylizationPP)