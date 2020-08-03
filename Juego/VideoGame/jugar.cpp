#include "jugar.h"
#include "ui_jugar.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include "inicio.h"

extern MainWindow * game;
extern inicio * ini;

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

int jugar::carga()
{
    QFile file("E:/Desktop/Proyecto-Final/Juego/VideoGame/nivel.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    QString temp=in.readAll();
    int numero=temp.toInt();
    file.flush();
    file.close();
    return numero;
}

void jugar::on_pushButton_clicked()
{
    //se cierra la ventana y se inicia el juego
    close();
    game->show();
}

void jugar::on_pushButton_2_clicked()
{

}

void jugar::on_pushButton_3_clicked()
{
    close();
    game->limpiar();
    game->niveles(carga());
    game->show();
}
