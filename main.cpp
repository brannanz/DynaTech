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

    QPalette palette;
    palette.setColor(QPalette::Window, QColor(53, 53, 53));
    palette.setColor(QPalette::WindowText, Qt::white);
    palette.setColor(QPalette::Base, QColor(15, 15, 15));
    palette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
    palette.setColor(QPalette::ToolTipBase, Qt::white);
    palette.setColor(QPalette::ToolTipText, Qt::white);
    palette.setColor(QPalette::Text, Qt::white);
    palette.setColor(QPalette::Button, QColor(53, 53, 53));
    palette.setColor(QPalette::ButtonText, Qt::white);
    palette.setColor(QPalette::BrightText, Qt::red);

    palette.setColor(QPalette::Highlight, QColor(142, 45, 197).lighter());
    palette.setColor(QPalette::HighlightedText, Qt::black);
    palette.setColor(QPalette::Disabled, QPalette::Text, Qt::darkGray);
    palette.setColor(QPalette::Disabled, QPalette::ButtonText, Qt::darkGray);

    app.setPalette(palette);
    // end this horrible block of code.

    DynaMainWindow mainWin;

    mainWin.newFile();
    mainWin.newFile();

    mainWin.show();


    return app.exec();
} 