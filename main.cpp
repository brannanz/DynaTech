#include <qapplication.h>
#include <qstylefactory.h>

#include "DynaMainWindow.h"

int main(int argc, char *argv[]) 
{
    QApplication::addLibraryPath(":/plugins");

    QApplication app(argc, argv);
    QCoreApplication::setApplicationName("Dyna3D");
    QCoreApplication::setOrganizationName("Dyna3D");
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);

    // TODO: move this out of main! it doesn't need to be here, we have more important things to do.
    app.setStyle(QStyleFactory::create("Fusion"));

    DynaMainWindow mainWin;

    mainWin.newFile();
    mainWin.newFile();

    mainWin.show();


    return app.exec();
} 