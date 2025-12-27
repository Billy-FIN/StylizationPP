#pragma once

#include "CoreMinimal.h"
#include "StylizationSettings.h"
#include "Widgets/SCompoundWidget.h"

// Forward declarations for Slate widgets
class SSlider;
class STextBlock;
class SButton;
class SVerticalBox;
class SHorizontalBox;

class STYLIZATIONPP_API SStylizationSettingsWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SStylizationSettingsWidget)
	{}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

private:
	/** Get the subsystem */
	class UStylizationSubsystem* GetSubsystem() const;

	/** Callbacks */
	FReply OnConfirmClicked();
	FReply OnCancelClicked();
	void OnModeChanged(EStylizationMode NewMode);
	void OnPixelationChanged(float NewValue);
	void OnNumColorsChanged(float NewValue);
	void OnSpreadChanged(float NewValue);

	/** Update UI visibility based on selected mode */
	void UpdateParameterVisibility();

	/** Current settings (local copy for editing) */
	FStylizationSettings CurrentSettings;

	/** UI Widgets */
	TSharedPtr<class SComboBox<TSharedPtr<FString>>> ModeComboBox;
	TSharedPtr<class SSlider> PixelationSlider;
	TSharedPtr<class SSlider> NumColorsSlider;
	TSharedPtr<class SSlider> SpreadSlider;
	TSharedPtr<class STextBlock> PixelationValueText;
	TSharedPtr<class STextBlock> NumColorsValueText;
	TSharedPtr<class STextBlock> SpreadValueText;

	/** Mode options */
	TArray<TSharedPtr<FString>> ModeOptions;
	TSharedPtr<SWidget> PixelArtParameters;
};

