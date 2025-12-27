#pragma once


#include "PostProcess/PostProcessMaterial.h"
#include "PostProcess/PostProcessing.h"
#include "PixelShaderUtils.h"

#include "StylizationSettings.h"
#include "PixelArtShader.h"

class FCustomSceneViewExtension : public FSceneViewExtensionBase
{
public:
	FCustomSceneViewExtension(const FAutoRegister& AutoRegister);

	/** Update settings from subsystem (called from game thread, used on render thread) */
	void UpdateSettings(const FStylizationSettings& NewSettings);

public:
	// This is the method to hook into PostProcessing pass
	virtual void SubscribeToPostProcessingPass(EPostProcessingPass PassId, const FSceneView& View, FAfterPassCallbackDelegateArray& InOutPassCallbacks, bool bIsPassEnabled);

	// This is the actual processing function
	FScreenPassTexture CustomPostProcessing(FRDGBuilder& GraphBuilder, const FSceneView& View, const FPostProcessMaterialInputs& Inputs);

	// Shader functions
	void RunPixelArtPass(
		FRDGBuilder& GraphBuilder,
		const FSceneView& View,
		const FScreenPassTexture& SceneColor,
		const FScreenPassTexture& Output, // Added this
		float Pixelation,
		float NumColors,
		float Spread);

private:
	/** Thread-safe settings storage (read on render thread, written from game thread) */
	mutable FCriticalSection SettingsCriticalSection;
	FStylizationSettings RenderThreadSettings;
};
