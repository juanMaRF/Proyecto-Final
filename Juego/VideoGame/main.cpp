#include "mainwindow.h"
#include <QApplication>
#include "mainmenu.h"
#include "inicio.h"
#include "jugar.h"

MainWindow * game;
inicio * ini;
jugar *jue;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    game = new MainWindow(1);
//    w.show();
    Menu m;
    m.show();
    return a.exec();
}
