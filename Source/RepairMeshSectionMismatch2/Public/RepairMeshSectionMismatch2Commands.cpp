// Copyright 2017 Exoception SAS. All Rights Reserved.

#include "RepairMeshSectionMismatch2PrivatePCH.h"
#include "RepairMeshSectionMismatch2Commands.h"

#define LOCTEXT_NAMESPACE "FRepairMeshSectionMismatch2Module"

void FRepairMeshSectionMismatch2Commands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "Repair Meshes Sections", "Execute RepairMeshSectionMismatch2 action", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
