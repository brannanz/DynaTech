#include "DataModel.h"

DataModel::DataModel()
	: workspace(new Workspace)
{
	setName("Game"); // ideally this is never seen
	className = "DataModel";

	initialize();
}

std::shared_ptr<Workspace> DataModel::getWorkspace()
{
	return workspace;
}

void DataModel::initialize()
{
	workspace->setParent(this);
}
