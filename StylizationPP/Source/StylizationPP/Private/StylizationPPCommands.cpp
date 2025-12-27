#include "StylizationPPCommands.h"
#include "StylizationSettingsWidget.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Widgets/SWindow.h"
#include "Framework/Application/SlateApplication.h"

#define LOCTEXT_NAMESPACE "FStylizationPPCommands"

void FStylizationPPCommands::RegisterCommands()
{
	UI_COMMAND(OpenStylizationSettings, "Stylization Settings", "Open the stylization settings window", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE

