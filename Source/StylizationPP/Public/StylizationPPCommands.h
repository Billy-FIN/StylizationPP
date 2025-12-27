#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "Styling/AppStyle.h"

class FStylizationPPCommands : public TCommands<FStylizationPPCommands>
{
public:
	FStylizationPPCommands()
		: TCommands<FStylizationPPCommands>(
			TEXT("StylizationPP"),
			NSLOCTEXT("Contexts", "StylizationPP", "StylizationPP Plugin"),
			NAME_None,
			FAppStyle::GetAppStyleSetName())
	{
	}

	virtual void RegisterCommands() override;

public:
	TSharedPtr<FUICommandInfo> OpenStylizationSettings;
};

