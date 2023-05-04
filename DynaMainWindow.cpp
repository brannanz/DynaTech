#include "DynaMainWindow.h"

DynaMainWindow::DynaMainWindow()
	: mdiArea(new QMdiArea)
    , explorer(new QDockWidget(tr("Explorer"), this))
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
