#include "mainwindow.h"

#include <thread>

CMainWindow::CMainWindow()
    : m_dwscriptOutput(new QDockWidget(tr("Script Output"), this))
{
	// setCentralWidget(mdiArea);

    g_output = new CScriptOutput();

    initDockingWidgets();
}

void CreateScriptInstance()
{
    CScriptInterface* scriptInterface = new CScriptInterface();
}

void InitScriptThread()
{
    g_output->Log("ENGINE: Running script");

    // create thread
    std::thread t(&CreateScriptInstance);

    // run along with everything else
    t.detach();
}

void CMainWindow::initDockingWidgets()
{
    // properties
    addDockWidget(Qt::BottomDockWidgetArea, m_dwscriptOutput);
    m_dwscriptOutput->setWidget(g_output);

    InitScriptThread();
}
