#include "mainwindow.h"
#include <QApplication>
#include "mainmenu.h"

MainWindow * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    game = new MainWindow();
//    w.show();
    Menu m;
    m.show();
    return a.exec();
}
