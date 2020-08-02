#include "mainmenu.h"
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
    close();
    in=new inicio(this);
    in->setModal(true);
    in->show();

}

void Menu::on_pushButton_2_clicked()
{
    reg=new Registro;
    reg->setModal(true);
    reg->show();
}
