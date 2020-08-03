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
    QString lvl="‪‪‪:/"+ini->getNom()+".TXT";
    QFile file(lvl);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"Title","File not open");
    }
    QTextStream in(&file);
    int numero=in.readAll().toInt();
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
    game->niveles(carga());
    game->show();
}
