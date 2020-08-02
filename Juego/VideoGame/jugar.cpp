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
    //se cierra la ventana y se inicia el juego
    close();
    game->show();
}
