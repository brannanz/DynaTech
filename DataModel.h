#pragma once

#include "DInstance.h"
#include "Workspace.h"

class DataModel : public Instance
{
public:
	DataModel();

	std::shared_ptr<Workspace> getWorkspace();
private:
	void initialize();
	std::shared_ptr<Workspace> workspace;
};