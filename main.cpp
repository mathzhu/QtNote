#include "mainwindow.h"
#include <QApplication>
#include "widget.h"
#include <painterdevicetest.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    Widget w;
//    w.show();
    PainterDeviceTest t;
    t.show();
    return a.exec();
}
