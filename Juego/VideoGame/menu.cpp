#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_un_pla_clicked()
{
    juego= new MainWindow();
    juego->show();
}

void Menu::on_pushButton_2_clicked()
{
    juego= new MainWindow();
    juego->show();
}
