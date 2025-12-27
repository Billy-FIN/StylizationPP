#include "CustomSceneViewExtension.h"


// Register the scene view extension
FCustomSceneViewExtension::FCustomSceneViewExtension(const FAutoRegister& AutoRegister) : FSceneViewExtensionBase(AutoRegister)
{
    UE_LOG(LogTemp, Log, TEXT("StylizationPP: SceneViewExtension registered"));
}

void FCustomSceneViewExtension::UpdateSettings(const FStylizationSettings& NewSettings)
{
    FScopeLock Lock(&SettingsCriticalSection);
    RenderThreadSettings = NewSettings;
}

void FCustomSceneViewExtension::SubscribeToPostProcessingPass(EPostProcessingPass PassId, const FSceneView& View, FAfterPassCallbackDelegateArray& InOutPassCallbacks, bool bIsPassEnabled)
{
    if (PassId == EPostProcessingPass::Tonemap)
    {
        // Only hook when effect is active
        FStylizationSettings Settings;
        {
            FScopeLock Lock(&SettingsCriticalSection);
            Settings = RenderThreadSettings;
        }

        if (Settings.Mode != EStylizationMode::None)
        {
            InOutPassCallbacks.Add(
                FAfterPassCallbackDelegate::CreateRaw(
                    this,
                    &FCustomSceneViewExtension::CustomPostProcessing));
        }
    }
}


// Choose and run the appropriate stylization effect
FScreenPassTexture FCustomSceneViewExtension::CustomPostProcessing(FRDGBuilder& GraphBuilder, const FSceneView& SceneView, const FPostProcessMaterialInputs& Inputs)
{
    FScreenPassTexture SceneColor = FScreenPassTexture::CopyFromSlice(GraphBuilder, Inputs.GetInput(EPostProcessMaterialInput::SceneColor));

    if (!SceneColor.IsValid())
    {
        UE_LOG(LogTemp, Warning, TEXT("SceneColor is invalid!"));
        return SceneColor;
    }

    const FIntRect ViewRect = SceneView.UnconstrainedViewRect;

    // Thread-safe settings read
    FStylizationSettings Settings;
    {
        FScopeLock Lock(&SettingsCriticalSection);
        Settings = RenderThreadSettings;
    }

    // Check if the engine provided a final target (OverrideOutput)
    FScreenPassTexture Output = Inputs.OverrideOutput;

    if (!Output.IsValid())
    {
        // Fallback: Create our own if Override is null
        FRDGTextureDesc OutputDesc = SceneColor.Texture->Desc;
        OutputDesc.Flags |= TexCreate_RenderTargetable;
        OutputDesc.ClearValue = FClearValueBinding::Black;

        FRDGTextureRef OutputTexture = GraphBuilder.CreateTexture(OutputDesc, TEXT("StylizationPPOutput"));
        Output = FScreenPassTexture(OutputTexture, ViewRect);
    }

    if (Settings.Mode == EStylizationMode::PixelArt)
    {
        RunPixelArtPass(
            GraphBuilder,
            SceneView,
            SceneColor,
            Output,
            Settings.Pixelation,
            Settings.NumColors,
            Settings.Spread);
        return Output;
    }
	return SceneColor;
}


// PixelArt
void FCustomSceneViewExtension::RunPixelArtPass(
    FRDGBuilder& GraphBuilder,
    const FSceneView& View,
    const FScreenPassTexture& SceneColor,
    const FScreenPassTexture& Output, // Accept Output
    float Pixelation,
    float NumColors,
    float Spread)
{
    const FIntRect ViewRect = Output.ViewRect; // Use the Output's Rect

	// Set up parameters
    FPixelArtShader::FParameters* Params = GraphBuilder.AllocParameters<FPixelArtShader::FParameters>();
    Params->SceneColorTexture = SceneColor.Texture;
    Params->SceneColorSampler = TStaticSamplerState<SF_Point>::GetRHI();
    Params->Pixelation = Pixelation;
    Params->NumColors = NumColors;
    Params->Spread = Spread;
    Params->ViewParams = GetScreenPassTextureViewportParameters(FScreenPassTextureViewport(SceneColor));
    Params->RenderTargets[0] = FRenderTargetBinding(Output.Texture, ERenderTargetLoadAction::ENoAction);

	// Get the shader
    TShaderMapRef<FPixelArtShader> PixelShader(GetGlobalShaderMap(View.GetFeatureLevel()));

	// Add the pass
    FPixelShaderUtils::AddFullscreenPass(
        GraphBuilder,
        GetGlobalShaderMap(View.GetFeatureLevel()),
        RDG_EVENT_NAME("PixelArtTonemap"),
        PixelShader,
        Params,
        ViewRect);
}

