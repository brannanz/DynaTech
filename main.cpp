#include <qapplication.h>

#include "mainwindow.h"

int main(int argc, char *argv[]) 
{
    QApplication::addLibraryPath(":/plugins");

    QApplication app(argc, argv);
    QCoreApplication::setApplicationName("Dyna3D");
    QCoreApplication::setOrganizationName("Dyna3D");
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);

    CMainWindow mainWin;

    mainWin.show();

    return app.exec();
} 