#include "inicio.h"
#include "ui_inicio.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>


inicio::inicio(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inicio)
{
    ui->setupUi(this);
}

inicio::~inicio()
{
    delete ui;
}

bool inicio::iniciar(QString nom_,QString cla_)
{
    QString ff="E:/Desktop/Proyecto-Final/Juego/VideoGame/registro.TXT";
    QFile file(ff);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"Title","File not open");
    }
    QTextStream in(&file);
    QString text=in.readAll(),temp,user,pass;
    QList <QString> usuarios,claves;
    int j=0;
    for(int i=0, n=text.size();i<n;i++){
        if(text[i]=='\n'){
            pass=temp;
            claves.push_back(pass);
            temp.clear();
        }
        else if(text[i]==','){
            user=temp;
            usuarios.push_back(user);
            temp.clear();
        }else{
            temp.append(text[i]);
        }
    }
    for(QList<QString>::iterator it=usuarios.begin();it!=usuarios.end();it++){
        if((*it)==nom_){
            if(claves.at(j)==cla_){
                return true;
            }else{
                return false;
            }
        }
        j++;
    }
    return false;
}

void inicio::on_pushButton_clicked()
{
    nom=ui->user->text();
    pass=ui->pass->text();
    if(iniciar(nom,pass)){
        close();
        play=new jugar(this);
        play->show();
    }else{
        QMessageBox::warning(this,"Alerta","Usuario o Contraseña incorrectas");
    }
}
