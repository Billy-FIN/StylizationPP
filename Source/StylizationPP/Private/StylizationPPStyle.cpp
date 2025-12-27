// Copyright Epic Games, Inc. All Rights Reserved.

#include "StylizationPPStyle.h"
#include "Styling/SlateStyleRegistry.h"
#include "Framework/Application/SlateApplication.h"
#include "Slate/SlateGameResources.h"
#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyleMacros.h"
#include "Misc/Paths.h"

#define RootToContentDir Style->RootToContentDir

TSharedPtr<FSlateStyleSet> FStylizationPPStyle::StyleInstance = nullptr;

void FStylizationPPStyle::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FStylizationPPStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

FName FStylizationPPStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("StylizationPPStyle"));
	return StyleSetName;
}

const FVector2D Icon20x20(20.0f, 20.0f);

TSharedRef< FSlateStyleSet > FStylizationPPStyle::Create()
{
	TSharedRef< FSlateStyleSet > Style = MakeShareable(new FSlateStyleSet("StylizationPPStyle"));
	
	TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin("StylizationPP");
	if (Plugin.IsValid())
	{
		Style->SetContentRoot(Plugin->GetBaseDir() / TEXT("Resources"));
		
		// Use PNG icon for better compatibility (SVG can be unreliable)
		Style->Set("StylizationPP.OpenStylizationSettings", new IMAGE_BRUSH(TEXT("Icon"), Icon20x20));
	}

	return Style;
}

const ISlateStyle& FStylizationPPStyle::Get()
{
	return *StyleInstance;
}

