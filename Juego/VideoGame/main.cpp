#include "mainwindow.h"

#include <QApplication>

#include "menu.h"

Menu *login;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    login = new Menu();
    login->show();

//    MainWindow w;
//    w.show();
    return a.exec();
}
