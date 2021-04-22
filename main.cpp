#include "fractalapp.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    FractalApp fractalWindow;
    fractalWindow.show();
    return app.exec();
}
