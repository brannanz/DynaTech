#include "DataModel.h"

DataModel::DataModel()
	: workspace(new Workspace)
{
	name = "Game";
	className = "DataModel";

	initialize();
}

void DataModel::initialize()
{
	workspace->setParent(this);
}
