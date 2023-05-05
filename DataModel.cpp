#include "DataModel.h"

DataModel::DataModel()
	: workspace(new Workspace)
{
	name = "Game";
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
