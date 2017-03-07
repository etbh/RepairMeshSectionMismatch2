// Copyright 2017 Exoception SAS. All Rights Reserved.

#pragma once

#include "ModuleManager.h"

class FToolBarBuilder;
class FMenuBuilder;

class FRepairMeshSectionMismatch2Module : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
	/** This function will be bound to Command. */
	void PluginButtonClicked();
	
private:

	void AddToolbarExtension(FToolBarBuilder& Builder);
	void AddMenuExtension(FMenuBuilder& Builder);

private:
	TSharedPtr<class FUICommandList> PluginCommands;
};