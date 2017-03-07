// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "SlateBasics.h"
#include "RepairMeshSectionMismatch2Style.h"

class FRepairMeshSectionMismatch2Commands : public TCommands<FRepairMeshSectionMismatch2Commands>
{
public:

	FRepairMeshSectionMismatch2Commands()
		: TCommands<FRepairMeshSectionMismatch2Commands>(TEXT("RepairMeshSectionMismatch2"), NSLOCTEXT("Contexts", "RepairMeshSectionMismatch2", "RepairMeshSectionMismatch2 Plugin"), NAME_None, FRepairMeshSectionMismatch2Style::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > PluginAction;
};
