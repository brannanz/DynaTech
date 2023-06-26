#pragma once

#include <qmainwindow.h>
#include <qmdiarea.h>
#include <qmdisubwindow.h>
#include <qdockwidget.h>

#include "scriptinterface.h"

class CMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	CMainWindow();

private slots:
	void initDockingWidgets(); // this functions is called 
	                           // to position dockwidgets after they've been created

private:
	QDockWidget* m_dwscriptOutput = NULL;
};