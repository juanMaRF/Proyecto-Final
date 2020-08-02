#include "mainwindow.h"
#include <QApplication>
#include "player.h"
#include "menu.h"

MainWindow *game;
Menu *menu;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    game = new MainWindow();
    menu = new Menu();
    menu->show();
    return a.exec();
}
