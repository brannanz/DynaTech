#include "DynaExplorer.h"

DynaExplorer::DynaExplorer()
{
	setHeaderHidden(true); // we don't want the header since this doesn't have properties
	setSelectionBehavior(QAbstractItemView::SelectRows);
	setSelectionMode(QAbstractItemView::ContiguousSelection);
}
