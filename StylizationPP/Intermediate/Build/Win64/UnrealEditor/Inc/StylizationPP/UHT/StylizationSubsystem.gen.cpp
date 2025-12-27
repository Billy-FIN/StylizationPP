// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "StylizationSubsystem.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeStylizationSubsystem() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UEngineSubsystem();
STYLIZATIONPP_API UClass* Z_Construct_UClass_UStylizationSubsystem();
STYLIZATIONPP_API UClass* Z_Construct_UClass_UStylizationSubsystem_NoRegister();
UPackage* Z_Construct_UPackage__Script_StylizationPP();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UStylizationSubsystem ****************************************************
void UStylizationSubsystem::StaticRegisterNativesUStylizationSubsystem()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UStylizationSubsystem;
UClass* UStylizationSubsystem::GetPrivateStaticClass()
{
	using TClass = UStylizationSubsystem;
	if (!Z_Registration_Info_UClass_UStylizationSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("StylizationSubsystem"),
			Z_Registration_Info_UClass_UStylizationSubsystem.InnerSingleton,
			StaticRegisterNativesUStylizationSubsystem,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UStylizationSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UStylizationSubsystem_NoRegister()
{
	return UStylizationSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UStylizationSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "StylizationSubsystem.h" },
		{ "ModuleRelativePath", "Public/StylizationSubsystem.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UStylizationSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UStylizationSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UEngineSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_StylizationPP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UStylizationSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UStylizationSubsystem_Statics::ClassParams = {
	&UStylizationSubsystem::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UStylizationSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UStylizationSubsystem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UStylizationSubsystem()
{
	if (!Z_Registration_Info_UClass_UStylizationSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UStylizationSubsystem.OuterSingleton, Z_Construct_UClass_UStylizationSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UStylizationSubsystem.OuterSingleton;
}
UStylizationSubsystem::UStylizationSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UStylizationSubsystem);
UStylizationSubsystem::~UStylizationSubsystem() {}
// ********** End Class UStylizationSubsystem ******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Projects_ShadingTest_Plugins_StylizationPP_Source_StylizationPP_Public_StylizationSubsystem_h__Script_StylizationPP_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UStylizationSubsystem, UStylizationSubsystem::StaticClass, TEXT("UStylizationSubsystem"), &Z_Registration_Info_UClass_UStylizationSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UStylizationSubsystem), 1611890901U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_ShadingTest_Plugins_StylizationPP_Source_StylizationPP_Public_StylizationSubsystem_h__Script_StylizationPP_1045310487(TEXT("/Script/StylizationPP"),
	Z_CompiledInDeferFile_FID_Projects_ShadingTest_Plugins_StylizationPP_Source_StylizationPP_Public_StylizationSubsystem_h__Script_StylizationPP_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_ShadingTest_Plugins_StylizationPP_Source_StylizationPP_Public_StylizationSubsystem_h__Script_StylizationPP_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
