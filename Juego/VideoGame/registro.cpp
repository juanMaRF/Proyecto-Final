#include "registro.h"
#include "ui_registro.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

Registro::Registro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registro)
{
    ui->setupUi(this);
}

Registro::~Registro()
{
    delete ui;
}

void Registro::registrar(QString nombre, QString pass)
{
    QString ff="E:/Desktop/Proyecto-Final/Juego/VideoGame/registro.TXT";

    QFile file(ff);
//    if(!file.open(QFile::WriteOnly | QFile::Text)){
//        QMessageBox::warning(this,"title","file not open");
//    }
    if(file.open(QFile::WriteOnly | QFile::Append)){
        QTextStream out(&file);
        out<<nombre<<","<<pass<<'\n';
    }
    file.flush();
    file.close();
}

void Registro::on_pushButton_clicked()
{
    nombre=ui->user->text();
    clave=ui->pass->text();
    registrar(nombre,clave);
    close();
}
