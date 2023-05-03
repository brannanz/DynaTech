#pragma once

#include <qmainwindow.h>
#include <qmdiarea.h>
#include <qmdisubwindow.h>

#include "DynaDoc.h"

class DynaMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	DynaMainWindow();
	void newFile();

private slots:
	DynaDoc* createMdiChild();

private:
	DynaDoc* activeMdiChild() const;
	QMdiSubWindow* findMdiChild(const QString& fileName) const;

	QMdiArea* mdiArea = NULL;
};