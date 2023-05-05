#include "DynaExplorer.h"

DynaExplorer::DynaExplorer()
{
	setHeaderHidden(true); // we don't want the header since this doesn't have properties
	setSelectionBehavior(QAbstractItemView::SelectRows);
	setSelectionMode(QAbstractItemView::ContiguousSelection);
}

void DynaExplorer::recurseThroughDataModel(std::vector<Instance*> children, QTreeWidgetItem* parent)
{
	for (int i = 0; i < children.size(); i++) {
		QTreeWidgetItem* item = new QTreeWidgetItem();
		parent->addChild(item);
		item->setText(0, QString::fromStdString(children[i]->getName()));

		if (!children[i]->children.empty())
		{
			recurseThroughDataModel(children[i]->children, item);
		}
	}
}
