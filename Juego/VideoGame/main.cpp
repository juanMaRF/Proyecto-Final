#include "mainwindow.h"
#include <QApplication>
#include "player.h"

MainWindow * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    game = new MainWindow();
    w.show();
    return a.exec();
}
