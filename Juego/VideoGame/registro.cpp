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
    //QString ff="E:/Desktop/Proyecto-Final/Juego/VideoGame/registro.TXT";
    QString ff="C:/Users/Usuario/Desktop/Proyecto-Final/Juego/VideoGame/registro.TXT";

    QFile file(ff);

    if(file.open(QFile::WriteOnly | QFile::Append)){
        QTextStream out(&file);
        out<<nombre<<","<<pass<<'\n';
    }
    file.flush();
    file.close();
}

bool Registro::verificar(QString nombre, QString pass)
{
    //se guarda en un string la direccion del txt, para el mejor manejo en el equipo
    //QString ff="E:/Desktop/Proyecto-Final/Juego/VideoGame/registro.TXT";
    QString ff="C:/Users/Usuario/Desktop/Proyecto-Final/Juego/VideoGame/registro.TXT";
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
    QString text=in.readAll(),temp,user,pa;
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
        if((*it)==nombre){
            return true;
        }
        j++;
    }
    return false;
}

void Registro::on_pushButton_clicked()
{
    //guardo los textos en las variables
    nombre=ui->user->text();
    clave=ui->pass->text();
    //si estan vacios sale la alerta
    if((nombre=="") or (clave=="")){
        QMessageBox::warning(this,"Alerta","Usuario o Contraseña vacios");
    }else{
        //verifica si la cuenta ya existe
        if(verificar(nombre,clave)){
            QMessageBox::warning(this,"Alerta","Usuario ya existe");
        }else{
            //lo registra
            registrar(nombre,clave);
            close();
        }
    }
}
