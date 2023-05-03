#include "DynaMainWindow.h"

DynaMainWindow::DynaMainWindow()
	: mdiArea(new QMdiArea)
{
	setCentralWidget(mdiArea);
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

DynaDoc* DynaMainWindow::activeMdiChild() const
{
    if (QMdiSubWindow* activeSubWindow = mdiArea->activeSubWindow())
        return qobject_cast<DynaDoc*>(activeSubWindow->widget());
    return nullptr;
}
