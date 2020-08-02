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
    //se guarda en un string la direccion del txt, para el mejor manejo en el equipo
    QString ff="E:/Desktop/Proyecto-Final/Juego/VideoGame/registro.TXT";
    //se abre el archivo
    QFile file(ff);
    //se comprueba si el txt se puede abrir en modo lectura, de lo contrario sale un mensage de alerta
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"Title","File not open");
    }
    //se inicia la variable se escritura
    QTextStream in(&file);
    //en text se guarda todo el texto del txt, en temp voy guardando letra por letra
    //y en user y pass guardo las palabras que van a estar divididas por comas
    QString text=in.readAll(),temp,user,pass;
    //en esta lista guardo a los usuarios y las claves
    QList <QString> usuarios,claves;
    //la uso para saber en que numero esta el usuario, en ese mismo tiene que estar la clave
    int j=0;
    //el for que me recorra todo el string de text
    for(int i=0, n=text.size();i<n;i++){
        //cada cuenta se separa por \n entonces guardo la contraseña en la lista
        //vacio temp para guardar a el siguiente usuario
        if(text[i]=='\n'){
            pass=temp;
            claves.push_back(pass);
            temp.clear();
        }
        //al encontrar la coma se sabe que en temp esa el usuario
        //se guarda en la lista y se vacia temp
        else if(text[i]==','){
            user=temp;
            usuarios.push_back(user);
            temp.clear();
        }
        //si no encontro un \n o una , se guarda en temp la palabra
        else{
            temp.append(text[i]);
        }
    }
    //recorre la lista de usuarios
    for(QList<QString>::iterator it=usuarios.begin();it!=usuarios.end();it++){
        //verifica el nombre
        if((*it)==nom_){
            //cuando encuentra el nombre en la poscicion j tambien esta la clave
            if(claves.at(j)==cla_){
                return true;
                j=0;
            }else{
                return false;
                j=0;
            }
        }
        j++;
    }
    return false;
}

void inicio::on_pushButton_clicked()
{
    //saca el texto de las casillas y se las asigna a estas variables
    nom=ui->user->text();
    pass=ui->pass->text();
    //llama a la funcion que retorna un bool
    //si es true es que si existe la cuenta
    if(iniciar(nom,pass)){
        close();
        play=new jugar(this);
        play->show();
    }
    //si la cuenta no existe saca este mensage
    else{
        QMessageBox::warning(this,"Alerta","Usuario o Contraseña incorrectas");
    }
}
