#include "jugar.h"
#include "ui_jugar.h"

extern MainWindow * game;

jugar::jugar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::jugar)
{
    ui->setupUi(this);
}

jugar::~jugar()
{
    delete ui;
}

void jugar::on_pushButton_clicked()
{
    close();
//    w=new MainWindow();
//    w->show();
    game->show();
}
