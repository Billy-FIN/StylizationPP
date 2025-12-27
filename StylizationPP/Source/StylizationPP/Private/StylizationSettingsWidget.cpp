#include "StylizationSettingsWidget.h"
#include "StylizationSubsystem.h"
#include "Engine/Engine.h"

// Slate widget includes - standard UE5 includes
#include "Widgets/Input/SComboBox.h"
#include "Widgets/Input/SSlider.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/SBoxPanel.h"  // SVerticalBox and SHorizontalBox are defined here in UE5.6

#include "Styling/AppStyle.h"
#include "Framework/Application/SlateApplication.h"

void SStylizationSettingsWidget::Construct(const FArguments& InArgs)
{
	// Get initial settings from subsystem
	UStylizationSubsystem* Subsystem = GetSubsystem();
	if (Subsystem)
	{
		CurrentSettings = Subsystem->GetSettings();
	}

	// Build mode options
	ModeOptions.Add(MakeShared<FString>(TEXT("None")));
	ModeOptions.Add(MakeShared<FString>(TEXT("Pixel Art")));

	// Find current mode index
	int32 CurrentModeIndex = 0;
	switch (CurrentSettings.Mode)
	{
	case EStylizationMode::None:
		CurrentModeIndex = 0;
		break;
	case EStylizationMode::PixelArt:
		CurrentModeIndex = 1;
		break;
	default:
		CurrentModeIndex = 0;
		break;
	}

	ChildSlot
	[
		SNew(SVerticalBox)
		
		// Title
		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(10, 10, 10, 5)
		[
			SNew(STextBlock)
			.Text(FText::FromString(TEXT("Stylization Settings")))
			.TextStyle(FAppStyle::Get(), "ContentBrowser.TopBar.Font")
		]

		// Mode Selection
		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(10, 5)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(0, 0, 10, 0)
			[
				SNew(STextBlock)
				.Text(FText::FromString(TEXT("Mode:")))
				.MinDesiredWidth(100)
			]
			+ SHorizontalBox::Slot()
			.FillWidth(1.0f)
			[
				SAssignNew(ModeComboBox, SComboBox<TSharedPtr<FString>>)
				.OptionsSource(&ModeOptions)
				.InitiallySelectedItem(CurrentModeIndex < ModeOptions.Num() ? ModeOptions[CurrentModeIndex] : ModeOptions[0])
				.OnGenerateWidget_Lambda([](TSharedPtr<FString> InOption)
				{
					return SNew(STextBlock).Text(FText::FromString(*InOption));
				})
				.OnSelectionChanged_Lambda([this](TSharedPtr<FString> NewValue, ESelectInfo::Type)
				{
					if (NewValue.IsValid())
					{
						if (*NewValue == TEXT("None"))
						{
							OnModeChanged(EStylizationMode::None);
						}
						else if (*NewValue == TEXT("Pixel Art"))
						{
							OnModeChanged(EStylizationMode::PixelArt);
						}
					}
				})
				[
					SNew(STextBlock)
					.Text_Lambda([this]()
					{
						if (ModeComboBox->GetSelectedItem().IsValid())
						{
							return FText::FromString(*ModeComboBox->GetSelectedItem());
						}
						return FText::FromString(TEXT("None"));
					})
				]
			]
		]

		// Pixel Art Parameters
		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(10, 5)
		[
			SAssignNew(PixelArtParameters, SVerticalBox)
			+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(0, 5)
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.AutoWidth()
				.VAlign(VAlign_Center)
				.Padding(0, 0, 10, 0)
				[
					SNew(STextBlock)
					.Text(FText::FromString(TEXT("Pixelation:")))
					.MinDesiredWidth(100)
				]
				+ SHorizontalBox::Slot()
				.FillWidth(1.0f)
				[
					SAssignNew(PixelationSlider, SSlider)
					.Value(CurrentSettings.Pixelation / 10.0f)
					.StepSize(0.1f / 10.0f)
					.OnValueChanged_Lambda([this](float NewValue)
					{
						OnPixelationChanged(NewValue * 10.0f);
					})
				]
				+ SHorizontalBox::Slot()
				.AutoWidth()
				.Padding(10, 0, 0, 0)
				[
					SAssignNew(PixelationValueText, STextBlock)
					.Text(FText::AsNumber(CurrentSettings.Pixelation))
					.MinDesiredWidth(50)
				]
			]
			+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(0, 5)
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.AutoWidth()
				.VAlign(VAlign_Center)
				.Padding(0, 0, 10, 0)
				[
					SNew(STextBlock)
					.Text(FText::FromString(TEXT("Num Colors:")))
					.MinDesiredWidth(100)
				]
				+ SHorizontalBox::Slot()
				.FillWidth(1.0f)
				[
					SAssignNew(NumColorsSlider, SSlider)
					.Value((CurrentSettings.NumColors - 2.0f) / 254.0f)
					.StepSize(1.0f / 254.0f)
					.OnValueChanged_Lambda([this](float NewValue)
					{
						OnNumColorsChanged(2.0f + NewValue * 254.0f);
					})
				]
				+ SHorizontalBox::Slot()
				.AutoWidth()
				.Padding(10, 0, 0, 0)
				[
					SAssignNew(NumColorsValueText, STextBlock)
					.Text(FText::AsNumber(CurrentSettings.NumColors))
					.MinDesiredWidth(50)
				]
			]
			+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(0, 5)
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.AutoWidth()
				.VAlign(VAlign_Center)
				.Padding(0, 0, 10, 0)
				[
					SNew(STextBlock)
					.Text(FText::FromString(TEXT("Spread:")))
					.MinDesiredWidth(100)
				]
				+ SHorizontalBox::Slot()
				.FillWidth(1.0f)
				[
					SAssignNew(SpreadSlider, SSlider)
					.Value(CurrentSettings.Spread)
					.StepSize(0.01f)
					.OnValueChanged_Lambda([this](float NewValue)
					{
						OnSpreadChanged(NewValue);
					})
				]
				+ SHorizontalBox::Slot()
				.AutoWidth()
				.Padding(10, 0, 0, 0)
				[
					SAssignNew(SpreadValueText, STextBlock)
					.Text(FText::AsNumber(CurrentSettings.Spread))
					.MinDesiredWidth(50)
				]
			]
		]

		// Buttons
		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(10, 10, 10, 10)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.FillWidth(1.0f)
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(5, 0)
			[
				SNew(SButton)
				.Text(FText::FromString(TEXT("Cancel")))
				.OnClicked(this, &SStylizationSettingsWidget::OnCancelClicked)
			]
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(5, 0)
			[
				SNew(SButton)
				.Text(FText::FromString(TEXT("Confirm")))
				.OnClicked(this, &SStylizationSettingsWidget::OnConfirmClicked)
			]
		]
	];

	// Update parameter visibility
	UpdateParameterVisibility();
}

UStylizationSubsystem* SStylizationSettingsWidget::GetSubsystem() const
{
	return GEngine->GetEngineSubsystem<UStylizationSubsystem>();
}

FReply SStylizationSettingsWidget::OnConfirmClicked()
{
	UStylizationSubsystem* Subsystem = GetSubsystem();
	if (Subsystem)
	{
		Subsystem->SetSettings(CurrentSettings);
	}

	// Close the window
	TSharedPtr<SWindow> ParentWindow = FSlateApplication::Get().FindWidgetWindow(AsShared());
	if (ParentWindow.IsValid())
	{
		ParentWindow->RequestDestroyWindow();
	}

	return FReply::Handled();
}

FReply SStylizationSettingsWidget::OnCancelClicked()
{
	// Close the window without applying changes
	TSharedPtr<SWindow> ParentWindow = FSlateApplication::Get().FindWidgetWindow(AsShared());
	if (ParentWindow.IsValid())
	{
		ParentWindow->RequestDestroyWindow();
	}

	return FReply::Handled();
}

void SStylizationSettingsWidget::OnModeChanged(EStylizationMode NewMode)
{
	CurrentSettings.Mode = NewMode;
	UpdateParameterVisibility();
}

void SStylizationSettingsWidget::OnPixelationChanged(float NewValue)
{
	// Round to 0.1 increments for easier control
	float RoundedValue = FMath::RoundToFloat(NewValue * 10.0f) / 10.0f;
	CurrentSettings.Pixelation = FMath::Clamp(RoundedValue, 0.1f, 10.0f);
	if (PixelationValueText.IsValid())
	{
		PixelationValueText->SetText(FText::AsNumber(CurrentSettings.Pixelation));
	}
}

void SStylizationSettingsWidget::OnNumColorsChanged(float NewValue)
{
	// Round to 1.0 increments for easier control
	float RoundedValue = FMath::RoundToFloat(NewValue);
	CurrentSettings.NumColors = FMath::Clamp(RoundedValue, 2.0f, 256.0f);
	if (NumColorsValueText.IsValid())
	{
		NumColorsValueText->SetText(FText::AsNumber(CurrentSettings.NumColors));
	}
}

void SStylizationSettingsWidget::OnSpreadChanged(float NewValue)
{
	// Round to 0.01 increments for easier control
	float RoundedValue = FMath::RoundToFloat(NewValue * 100.0f) / 100.0f;
	CurrentSettings.Spread = FMath::Clamp(RoundedValue, 0.0f, 1.0f);
	if (SpreadValueText.IsValid())
	{
		SpreadValueText->SetText(FText::AsNumber(CurrentSettings.Spread));
	}
}

void SStylizationSettingsWidget::UpdateParameterVisibility()
{
	if (!PixelArtParameters.IsValid())
	{
		return;
	}

	switch (CurrentSettings.Mode)
	{
	case EStylizationMode::PixelArt:
		PixelArtParameters->SetVisibility(EVisibility::Visible);
		break;
	case EStylizationMode::None:
	default:
		PixelArtParameters->SetVisibility(EVisibility::Collapsed);
		break;
	}
}

