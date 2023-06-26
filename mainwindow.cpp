#include "mainwindow.h"

#include <thread>

#include "filesystem.h"

CMainWindow::CMainWindow()
    : m_dwscriptOutput(new QDockWidget(tr("Script Output"), this))
{
	// setCentralWidget(mdiArea);

    g_output = new CScriptOutput();

    initDockingWidgets();
}

void CreateScriptInstance(std::string file)
{
    CScriptInterface* scriptInterface = new CScriptInterface(file);
}

void InitScriptThread(std::string file)
{
    g_output->Log("ENGINE: Running script " + file, false);

    // create thread
    std::thread t(&CreateScriptInstance, filesystem::LoadAsset(file));

    // run along with everything else
    t.detach();
}

void CMainWindow::initDockingWidgets()
{
    // properties
    addDockWidget(Qt::BottomDockWidgetArea, m_dwscriptOutput);
    m_dwscriptOutput->setWidget(g_output);

    InitScriptThread("scripts/test.wren");
}
