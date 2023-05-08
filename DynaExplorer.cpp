#include "DynaExplorer.h"

DynaExplorer::DynaExplorer()
	: model(new QStandardItemModel())
{
	setHeaderHidden(true); // we don't want the header since this doesn't have properties

	setModel(model);
}

void DynaExplorer::recurseThroughDataModel(std::vector<Instance*> children, QStandardItem* parent)
{
	for (int i = 0; i < children.size(); i++) {
		QStandardItem* item = new QStandardItem(QString::fromStdString(children[i]->getName()));

		parent->appendRow(item);

		if (!children[i]->children.empty())
		{
			recurseThroughDataModel(children[i]->children, item);
		}
	}
}
