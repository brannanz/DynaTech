#pragma once

#include "DInstance.h"
#include "Workspace.h"

class DataModel : public Instance
{
public:
	DataModel();
private:
	void initialize();
	std::shared_ptr<Workspace> workspace;
};