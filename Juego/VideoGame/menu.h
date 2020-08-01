#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
    void on_un_pla_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Menu *ui;
    MainWindow *juego;
};

#endif // MENU_H
