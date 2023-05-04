#include "DInstance.h"
#include "DynaMainWindow.h"

DynaMainWindow::DynaMainWindow()
	: mdiArea(new QMdiArea)
    , explorer(new QDockWidget(tr("Explorer"), this))
    , explorerTree(new DynaExplorer())
    , properties(new QDockWidget(tr("Properties"), this))
    , propertyGrid(new DynaPropertyGrid())
{
	setCentralWidget(mdiArea);

    initDockingWidgets();
}

void DynaMainWindow::newFile()
{
	DynaDoc* child = createMdiChild();
	child->show();
}

DynaDoc* DynaMainWindow::createMdiChild()
{
    DynaDoc* child = new DynaDoc;
    mdiArea->addSubWindow(child);
    mdiArea->setViewMode(QMdiArea::TabbedView);
    mdiArea->setTabsClosable(true);
    mdiArea->setTabsMovable(true);

    return child;
}

void DynaMainWindow::initDockingWidgets()
{
    // explorer
    addDockWidget(Qt::RightDockWidgetArea, explorer);
    explorer->setWidget(explorerTree);

    DataModel* dataModel = new DataModel();

    for (int i = 0; i < 8; i++)
    {
        Instance* testInstance = new Instance();
        testInstance->setParent(dataModel);
        testInstance->setName("Instance");
    }

    for (int i = 0; i < dataModel->children.size(); i++) {
        QTreeWidgetItem* topLevelItem = new QTreeWidgetItem();
        explorerTree->addTopLevelItem(topLevelItem);
        topLevelItem->setText(0, QString::fromStdString(dataModel->children[i]->getName()));
    }

    // properties
    addDockWidget(Qt::RightDockWidgetArea, properties);
    properties->setWidget(propertyGrid);
}

DynaDoc* DynaMainWindow::activeMdiChild() const
{
    if (QMdiSubWindow* activeSubWindow = mdiArea->activeSubWindow())
        return qobject_cast<DynaDoc*>(activeSubWindow->widget());
    return nullptr;
}
