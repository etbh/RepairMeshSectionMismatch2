// Copyright 2017 Exoception SAS. All Rights Reserved.

#include "RepairMeshSectionMismatch2PrivatePCH.h"

#include "RepairMeshSectionMismatch2Style.h"
#include "SlateGameResources.h"
#include "IPluginManager.h"

TSharedPtr< FSlateStyleSet > FRepairMeshSectionMismatch2Style::StyleInstance = NULL;

void FRepairMeshSectionMismatch2Style::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FRepairMeshSectionMismatch2Style::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

FName FRepairMeshSectionMismatch2Style::GetStyleSetName()
{
	static FName StyleSetName(TEXT("RepairMeshSectionMismatch2Style"));
	return StyleSetName;
}

#define IMAGE_BRUSH( RelativePath, ... ) FSlateImageBrush( Style->RootToContentDir( RelativePath, TEXT(".png") ), __VA_ARGS__ )
#define BOX_BRUSH( RelativePath, ... ) FSlateBoxBrush( Style->RootToContentDir( RelativePath, TEXT(".png") ), __VA_ARGS__ )
#define BORDER_BRUSH( RelativePath, ... ) FSlateBorderBrush( Style->RootToContentDir( RelativePath, TEXT(".png") ), __VA_ARGS__ )
#define TTF_FONT( RelativePath, ... ) FSlateFontInfo( Style->RootToContentDir( RelativePath, TEXT(".ttf") ), __VA_ARGS__ )
#define OTF_FONT( RelativePath, ... ) FSlateFontInfo( Style->RootToContentDir( RelativePath, TEXT(".otf") ), __VA_ARGS__ )

const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon20x20(20.0f, 20.0f);
const FVector2D Icon40x40(40.0f, 40.0f);

TSharedRef< FSlateStyleSet > FRepairMeshSectionMismatch2Style::Create()
{
	TSharedRef< FSlateStyleSet > Style = MakeShareable(new FSlateStyleSet("RepairMeshSectionMismatch2Style"));
	Style->SetContentRoot(IPluginManager::Get().FindPlugin("RepairMeshSectionMismatch2")->GetBaseDir() / TEXT("Resources"));

	Style->Set("RepairMeshSectionMismatch2.PluginAction", new IMAGE_BRUSH(TEXT("ButtonIcon_40x"), Icon40x40));

	return Style;
}

#undef IMAGE_BRUSH
#undef BOX_BRUSH
#undef BORDER_BRUSH
#undef TTF_FONT
#undef OTF_FONT

void FRepairMeshSectionMismatch2Style::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

const ISlateStyle& FRepairMeshSectionMismatch2Style::Get()
{
	return *StyleInstance;
}
