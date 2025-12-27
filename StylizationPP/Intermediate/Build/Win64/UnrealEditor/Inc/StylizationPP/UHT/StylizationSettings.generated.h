// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "StylizationSettings.h"

#ifdef STYLIZATIONPP_StylizationSettings_generated_h
#error "StylizationSettings.generated.h already included, missing '#pragma once' in StylizationSettings.h"
#endif
#define STYLIZATIONPP_StylizationSettings_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin ScriptStruct FStylizationSettings **********************************************
#define FID_Projects_ShadingTest_Plugins_StylizationPP_Source_StylizationPP_Public_StylizationSettings_h_16_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FStylizationSettings_Statics; \
	static class UScriptStruct* StaticStruct();


struct FStylizationSettings;
// ********** End ScriptStruct FStylizationSettings ************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Projects_ShadingTest_Plugins_StylizationPP_Source_StylizationPP_Public_StylizationSettings_h

// ********** Begin Enum EStylizationMode **********************************************************
#define FOREACH_ENUM_ESTYLIZATIONMODE(op) \
	op(EStylizationMode::None) \
	op(EStylizationMode::PixelArt) 

enum class EStylizationMode : uint8;
template<> struct TIsUEnumClass<EStylizationMode> { enum { Value = true }; };
template<> STYLIZATIONPP_API UEnum* StaticEnum<EStylizationMode>();
// ********** End Enum EStylizationMode ************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
