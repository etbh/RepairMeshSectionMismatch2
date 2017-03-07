// Copyright 2017 Exoception SAS. All Rights Reserved.

#include "RepairMeshSectionMismatch2PrivatePCH.h"

#include "SlateBasics.h"
#include "SlateExtras.h"

#include "RepairMeshSectionMismatch2Style.h"
#include "RepairMeshSectionMismatch2Commands.h"

#include "LevelEditor.h"
#include "StaticMeshResources.h"

static const FName RepairMeshSectionMismatch2TabName("RepairMeshSectionMismatch2");

#define LOCTEXT_NAMESPACE "FRepairMeshSectionMismatch2Module"

void FRepairMeshSectionMismatch2Module::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FRepairMeshSectionMismatch2Style::Initialize();
	FRepairMeshSectionMismatch2Style::ReloadTextures();

	FRepairMeshSectionMismatch2Commands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FRepairMeshSectionMismatch2Commands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &FRepairMeshSectionMismatch2Module::PluginButtonClicked),
		FCanExecuteAction());
		
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	
	{
		TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());
		MenuExtender->AddMenuExtension("WindowLayout", EExtensionHook::After, PluginCommands, FMenuExtensionDelegate::CreateRaw(this, &FRepairMeshSectionMismatch2Module::AddMenuExtension));

		LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
	}
	
	{
		TSharedPtr<FExtender> ToolbarExtender = MakeShareable(new FExtender);
		ToolbarExtender->AddToolBarExtension("Settings", EExtensionHook::After, PluginCommands, FToolBarExtensionDelegate::CreateRaw(this, &FRepairMeshSectionMismatch2Module::AddToolbarExtension));
		
		LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolbarExtender);
	}
}

void FRepairMeshSectionMismatch2Module::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FRepairMeshSectionMismatch2Style::Shutdown();

	FRepairMeshSectionMismatch2Commands::Unregister();
}

void FRepairMeshSectionMismatch2Module::PluginButtonClicked()
{
	// Put your "OnButtonClicked" stuff here

	TArray<FAssetData> Assets;
	for (AActor* Actor : GEditor->GetEditorWorldContext().World()->GetCurrentLevel()->Actors)
		if (Actor && Actor->IsSelected() && Actor->GetClass()->GetName().Equals(TEXT("StaticMeshActor"))){
			
			UE_LOG(LogTemp, Warning, TEXT("%s %d"), *Actor->GetClass()->GetName(), Actor->GetClass()->GetName().Equals(TEXT("StaticMeshActor")));

			AStaticMeshActor* StaticMeshActor = StaticCast<AStaticMeshActor*> (Actor);
			UStaticMeshComponent* StaticMeshComponent = StaticMeshActor->GetStaticMeshComponent();
			UStaticMesh* StaticMesh = StaticMeshComponent->GetStaticMesh();
			TArray<FStaticMeshSection>& Sections = StaticMesh->RenderData->LODResources[0].Sections;
			TArray<UMaterialInterface*> Materials;
			for (int32 i = 0; i < Sections.Num(); i++) {
				FStaticMeshSection& Section = Sections[i];
				FMeshSectionInfo SectionInfo = StaticMesh->SectionInfoMap.Get(0, i);
				UMaterialInterface* material = StaticMeshComponent->GetMaterial(SectionInfo.MaterialIndex);
				UE_LOG(LogTemp, Warning, TEXT("Section : %d, MatIndex : %d"), i, SectionInfo.MaterialIndex);
				SectionInfo.MaterialIndex = i;
				StaticMesh->SectionInfoMap.Set(0, i, SectionInfo);
				Materials.Add(material);
			}
			for (int i = 0; i < StaticMesh->StaticMaterials.Num(); i++) {
				StaticMesh->StaticMaterials[i] = Materials[i];
				StaticMeshComponent->SetMaterial(i, Materials[i]);
			}
			StaticMesh->Modify();

		//	FText DialogText = FText::Format(
		//		LOCTEXT("Repair Plugin", "Assets : {0} : {1}"),
		//		FText::FromName(Asset.AssetName),
		//		FText::FromName(Asset.AssetClass)
		//	);
		//FMessageDialog::Open(EAppMsgType::Ok, DialogText);
	}

}

void FRepairMeshSectionMismatch2Module::AddMenuExtension(FMenuBuilder& Builder)
{
	Builder.AddMenuEntry(FRepairMeshSectionMismatch2Commands::Get().PluginAction);
}

void FRepairMeshSectionMismatch2Module::AddToolbarExtension(FToolBarBuilder& Builder)
{
	Builder.AddToolBarButton(FRepairMeshSectionMismatch2Commands::Get().PluginAction);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FRepairMeshSectionMismatch2Module, RepairMeshSectionMismatch2)