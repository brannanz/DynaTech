#pragma once

#include <qmainwindow.h>
#include <qmdiarea.h>
#include <qmdisubwindow.h>
#include <qdockwidget.h>

#include "DynaProperties.h"
#include "DynaDoc.h"

class DynaMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	DynaMainWindow();
	void newFile();

private slots:
	DynaDoc* createMdiChild();
	void initDockingWidgets(); // this functions is called 
	                           // to position dockwidgets after they've been created

private:
	DynaDoc* activeMdiChild() const;
	QMdiSubWindow* findMdiChild(const QString& fileName) const;

	QMdiArea* mdiArea = NULL;

	QDockWidget* explorer = NULL;

	QDockWidget* properties = NULL;
	DynaPropertyGrid* propertyGrid = NULL;
};