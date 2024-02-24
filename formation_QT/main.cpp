#include "mainwindow.h"


#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //connect to database

    w.show();
    return a.exec();
}
