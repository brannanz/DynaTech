#pragma once

#include <qtreewidget.h>

#include "DataModel.h"

class DynaExplorer : public QTreeWidget
{
public:
	DynaExplorer();

	void recurseThroughDataModel(std::vector<Instance*> children, QTreeWidgetItem* parent);
};