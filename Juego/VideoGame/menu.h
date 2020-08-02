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
    void on_pushButton_clicked();

private:
    MainWindow *game;
    Ui::Menu *ui;
};

#endif // MENU_H
