#pragma once

#include <qtreeview.h>
#include <qstandarditemmodel.h>

#include "DataModel.h"

class DynaExplorer : public QTreeView
{
public:
	DynaExplorer();

	void recurseThroughDataModel(std::vector<Instance*> children, QStandardItem* parent);

	QStandardItemModel* model;
	QStandardItem* root = model->invisibleRootItem();
};