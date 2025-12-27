// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "StylizationSettings.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeStylizationSettings() {}

// ********** Begin Cross Module References ********************************************************
STYLIZATIONPP_API UEnum* Z_Construct_UEnum_StylizationPP_EStylizationMode();
STYLIZATIONPP_API UScriptStruct* Z_Construct_UScriptStruct_FStylizationSettings();
UPackage* Z_Construct_UPackage__Script_StylizationPP();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EStylizationMode **********************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EStylizationMode;
static UEnum* EStylizationMode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EStylizationMode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EStylizationMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_StylizationPP_EStylizationMode, (UObject*)Z_Construct_UPackage__Script_StylizationPP(), TEXT("EStylizationMode"));
	}
	return Z_Registration_Info_UEnum_EStylizationMode.OuterSingleton;
}
template<> STYLIZATIONPP_API UEnum* StaticEnum<EStylizationMode>()
{
	return EStylizationMode_StaticEnum();
}
struct Z_Construct_UEnum_StylizationPP_EStylizationMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/StylizationSettings.h" },
		{ "None.DisplayName", "None" },
		{ "None.Name", "EStylizationMode::None" },
		{ "PixelArt.DisplayName", "Pixel Art" },
		{ "PixelArt.Name", "EStylizationMode::PixelArt" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EStylizationMode::None", (int64)EStylizationMode::None },
		{ "EStylizationMode::PixelArt", (int64)EStylizationMode::PixelArt },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_StylizationPP_EStylizationMode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_StylizationPP,
	nullptr,
	"EStylizationMode",
	"EStylizationMode",
	Z_Construct_UEnum_StylizationPP_EStylizationMode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_StylizationPP_EStylizationMode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_StylizationPP_EStylizationMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_StylizationPP_EStylizationMode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_StylizationPP_EStylizationMode()
{
	if (!Z_Registration_Info_UEnum_EStylizationMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EStylizationMode.InnerSingleton, Z_Construct_UEnum_StylizationPP_EStylizationMode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EStylizationMode.InnerSingleton;
}
// ********** End Enum EStylizationMode ************************************************************

// ********** Begin ScriptStruct FStylizationSettings **********************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FStylizationSettings;
class UScriptStruct* FStylizationSettings::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FStylizationSettings.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FStylizationSettings.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FStylizationSettings, (UObject*)Z_Construct_UPackage__Script_StylizationPP(), TEXT("StylizationSettings"));
	}
	return Z_Registration_Info_UScriptStruct_FStylizationSettings.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FStylizationSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/StylizationSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Mode_MetaData[] = {
		{ "Category", "Stylization" },
		{ "ModuleRelativePath", "Public/StylizationSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Pixelation_MetaData[] = {
		{ "Category", "Pixel Art" },
		{ "ClampMax", "10.0" },
		{ "ClampMin", "0.1" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// PixelArt Parameters\n" },
#endif
		{ "ModuleRelativePath", "Public/StylizationSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "PixelArt Parameters" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NumColors_MetaData[] = {
		{ "Category", "Pixel Art" },
		{ "ClampMax", "256.0" },
		{ "ClampMin", "2.0" },
		{ "ModuleRelativePath", "Public/StylizationSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Spread_MetaData[] = {
		{ "Category", "Pixel Art" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/StylizationSettings.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_Mode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Mode;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Pixelation;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_NumColors;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Spread;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FStylizationSettings>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FStylizationSettings_Statics::NewProp_Mode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FStylizationSettings_Statics::NewProp_Mode = { "Mode", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStylizationSettings, Mode), Z_Construct_UEnum_StylizationPP_EStylizationMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Mode_MetaData), NewProp_Mode_MetaData) }; // 2504265525
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FStylizationSettings_Statics::NewProp_Pixelation = { "Pixelation", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStylizationSettings, Pixelation), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Pixelation_MetaData), NewProp_Pixelation_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FStylizationSettings_Statics::NewProp_NumColors = { "NumColors", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStylizationSettings, NumColors), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NumColors_MetaData), NewProp_NumColors_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FStylizationSettings_Statics::NewProp_Spread = { "Spread", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStylizationSettings, Spread), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Spread_MetaData), NewProp_Spread_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FStylizationSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStylizationSettings_Statics::NewProp_Mode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStylizationSettings_Statics::NewProp_Mode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStylizationSettings_Statics::NewProp_Pixelation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStylizationSettings_Statics::NewProp_NumColors,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStylizationSettings_Statics::NewProp_Spread,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStylizationSettings_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FStylizationSettings_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_StylizationPP,
	nullptr,
	&NewStructOps,
	"StylizationSettings",
	Z_Construct_UScriptStruct_FStylizationSettings_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStylizationSettings_Statics::PropPointers),
	sizeof(FStylizationSettings),
	alignof(FStylizationSettings),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStylizationSettings_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FStylizationSettings_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FStylizationSettings()
{
	if (!Z_Registration_Info_UScriptStruct_FStylizationSettings.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FStylizationSettings.InnerSingleton, Z_Construct_UScriptStruct_FStylizationSettings_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FStylizationSettings.InnerSingleton;
}
// ********** End ScriptStruct FStylizationSettings ************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Projects_ShadingTest_Plugins_StylizationPP_Source_StylizationPP_Public_StylizationSettings_h__Script_StylizationPP_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EStylizationMode_StaticEnum, TEXT("EStylizationMode"), &Z_Registration_Info_UEnum_EStylizationMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2504265525U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FStylizationSettings::StaticStruct, Z_Construct_UScriptStruct_FStylizationSettings_Statics::NewStructOps, TEXT("StylizationSettings"), &Z_Registration_Info_UScriptStruct_FStylizationSettings, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FStylizationSettings), 3455416369U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_ShadingTest_Plugins_StylizationPP_Source_StylizationPP_Public_StylizationSettings_h__Script_StylizationPP_829312198(TEXT("/Script/StylizationPP"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Projects_ShadingTest_Plugins_StylizationPP_Source_StylizationPP_Public_StylizationSettings_h__Script_StylizationPP_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_ShadingTest_Plugins_StylizationPP_Source_StylizationPP_Public_StylizationSettings_h__Script_StylizationPP_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_Projects_ShadingTest_Plugins_StylizationPP_Source_StylizationPP_Public_StylizationSettings_h__Script_StylizationPP_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_ShadingTest_Plugins_StylizationPP_Source_StylizationPP_Public_StylizationSettings_h__Script_StylizationPP_Statics::EnumInfo));
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
