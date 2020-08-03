#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include "mainwindow.h"
#include "registro.h"
#include "inicio.h"

namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr); //es el constructor para la interfaz de inicio de sesion o registrarce
    ~Menu();

private slots:
    void on_un_pla_clicked();//inicio de sesion

    void on_pushButton_2_clicked();//registrarse

private:
    Ui::Menu *ui;
    MainWindow *juego;
    Registro * reg;
    inicio * in;
};

#endif // MENU_H
