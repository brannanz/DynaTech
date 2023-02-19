#include <QApplication>

#include "DynaMainWindow.h"

int main(int argc, char *argv[]) 
{
    QApplication::addLibraryPath(":/plugins");

    QApplication app(argc, argv);
    MainWindow window;
    window.show();

    return app.exec();
} 