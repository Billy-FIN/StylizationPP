#pragma once

#include "SceneTexturesConfig.h"
#include "ShaderParameterStruct.h"
#include "ScreenPass.h"

class STYLIZATIONPP_API FPixelArtShader : public FGlobalShader
{
public:

	DECLARE_GLOBAL_SHADER(FPixelArtShader)
	SHADER_USE_PARAMETER_STRUCT(FPixelArtShader, FGlobalShader);

	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
		SHADER_PARAMETER(float, Pixelation)
		SHADER_PARAMETER(float, NumColors)
		SHADER_PARAMETER(float, Spread)
		SHADER_PARAMETER_RDG_TEXTURE(Texture2D, SceneColorTexture)
		SHADER_PARAMETER_SAMPLER(SamplerState, SceneColorSampler)
		SHADER_PARAMETER_STRUCT(FScreenPassTextureViewportParameters, ViewParams)

		RENDER_TARGET_BINDING_SLOTS()
	END_SHADER_PARAMETER_STRUCT()
};