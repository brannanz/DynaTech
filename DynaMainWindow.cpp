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

    for (int i = 0; i < 10; i++)
    {
        Instance* instance = new Instance();
        instance->setName("An instance");
        instance->setParent(dataModel->getWorkspace().get());

        Instance* instance2 = new Instance();
        instance2->setName("An instance 2");
        instance2->setParent(instance);
    }

    QTreeWidgetItem* topLevelItem = new QTreeWidgetItem();
    explorerTree->addTopLevelItem(topLevelItem);
    topLevelItem->setExpanded(true);

    explorerTree->recurseThroughDataModel(dataModel->children, topLevelItem);

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
