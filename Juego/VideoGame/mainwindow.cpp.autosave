#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <math.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    time=new QTimer;
//    connect(time,SIGNAL(timeout()),this,SLOT(Mover()));
//    leer_lvl(2);
    Boss_1();



}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::colision(moob *cuerpo, obstaculos *que)
{
    for (QList <obstaculos*>::iterator it=paredes_sup.begin();it!=paredes_sup.end();it++) {
        if(cuerpo->collidesWithItem((*it))){
            que=(*it);
            return "valla";
        }
    }
    for (QList <obstaculos*>::iterator it=paredes_lateral.begin();it!=paredes_lateral.end();it++) {
        if(cuerpo->collidesWithItem((*it))){
            que=(*it);
            return "lat";
        }
    }
    return "no";
}



void MainWindow::leer_lvl(int lvl_)
{
    QString lvl;
    if(lvl_==1){
        lvl="E:/Desktop/Proyecto-Final/Juego/VideoGame/lvl_1.TXT";
    }else if(lvl_==2){
        lvl="E:/Desktop/Proyecto-Final/Juego/VideoGame/lvl_2.TXT";
    }
    scene=new QGraphicsScene;

    ui->graphicsView->setScene(scene);
    scene->setSceneRect(-85,-90,1111,621);
    scene->setBackgroundBrush(QBrush(QImage(":/Imagenes Proyecto final/WhatsApp Image 2020-07-08 at 6.48.30 PM.jpeg")));

    //leer_ene(1,scene);

    QFile file(lvl);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"Title","File not open");
    }
    QTextStream in(&file);
    QString text=in.readAll(),textura,temp,nomb;
    file.close();
    int comas=0,coordx=0,coordy=0,w_=0,h_=0,tempint;
    for (int i=0;i<text.size();i++) {
        if(text.at(i)=="\n"){
            cant_obj+=1;
            nomb=cant_obj;
            textura=temp;
            temp.clear();
            //crear los objetos y luego agregar a la lista
            scene->addItem(new obstaculos(coordx,coordy,w_,h_,textura));
            lista_piedra.push_back(new obstaculos(coordx,coordy,w_,h_,textura));
            comas=0;
            if(textura=="piedra2" or textura=="hojas1" or textura=="hongo1"){
                paredes_lateral.push_back(new obstaculos(coordx,coordy,w_,h_,textura));
            }else if(textura=="valla1"){
                paredes_sup.push_back(new obstaculos(coordx,coordy,w_,h_,textura));
            }

        }
        if(text.at(i)==","){
            if(comas==0){
                tempint=temp.toInt();
                coordx=tempint;
                temp.clear();
            }else if(comas==1){
                tempint=temp.toInt();
                coordy=tempint;
                temp.clear();
            }else if(comas==2){
                tempint=temp.toInt();
                w_=tempint;
                temp.clear();
            }else if(comas==3){
                tempint=temp.toInt();
                h_=tempint;
                temp.clear();
            }
            comas+=1;
            i++;
        }


        temp.append(text.at(i));
    }
    e1=new moob(0,-10,50,50,"perro");scene->addItem(e1);enemigos.push_back(e1);
    e2=new moob(900,-10,50,50,"perro");scene->addItem(e2);enemigos.push_back(e2);
    e3=new moob(300,400,50,50,"perro");scene->addItem(e3);enemigos.push_back(e3);
    e4=new moob(700,400,50,50,"perro");scene->addItem(e4);enemigos.push_back(e4);
    //leer_ene(lvl_,scene);
    time->start(20);
}

void MainWindow::leer_atks(int lvl_)
{
    QString lvl;
    if(lvl_==0){
        lvl="E:/Desktop/Proyecto-Final/Juego/VideoGame/atk_1.TXT";
    }
    else if(lvl_==1){
        lvl="E:/Desktop/Proyecto-Final/Juego/VideoGame/atk_2.TXT";
    }
    QFile file(lvl);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"Title","File not open");         //se abre el archivo para guardarlo en un Qstring
    }
    QTextStream in(&file);
    QString text=in.readAll(),temp;
    file.close();
    int comas=0,coordx=0,coordy=0,tempint;
    for (int i=0;i<text.size();i++) {
        if(text.at(i)==","){
            if(comas==0){
                tempint=temp.toInt();
                coordx=tempint;
                temp.clear();
            }
            comas+=1;
            i++;
        }
        if(text.at(i)=="\n"){
            tempint=temp.toInt();
            coordy=tempint;
            temp.clear();
            atks.push_back(new boss(coordx,coordy));
            comas=0;
        }else
        temp.append(text.at(i));
    }
    for (QList <boss*>::iterator it=atks.begin();it!=atks.end();it++) {
        scene->addItem((*it));
    }
}

void MainWindow::Boss_1()
{
    int alea=1;
    scene=new QGraphicsScene;

    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,1111,621);
    scene->setBackgroundBrush(QBrush(QImage(":/Imagenes Proyecto final/escena_boss.png")));
//    p1=new corazon(250,250);scene->addItem(p1);
    if(alea==0){
        leer_atks(alea);
        int pp=1;
        for (QList <boss*>::iterator it=atks.begin();it!=atks.end();it++) {
            (*it)->setVelx((*it)->getVelx()*pp);
            pp=pp*-1;
        }
        connect(time,SIGNAL(timeout()),this,SLOT(atk_1()));
    }else if(alea==1){
        leer_atks(alea);
        connect(time,SIGNAL(timeout()),this,SLOT(atk_2()));
    }else if(alea==2){
        b1=new boss(550,450);scene->addItem(b1);atks.push_back(b1);
        b2=new boss(190,430);scene->addItem(b2);atks.push_back(b2);
        b3=new boss(910,430);scene->addItem(b3);atks.push_back(b3);
        b4=new boss(190,500);scene->addItem(b4);atks.push_back(b4);
        b5=new boss(910,500);scene->addItem(b5);atks.push_back(b5);
        for(int i=0;i<5;i++){

        }
        connect(time,SIGNAL(timeout()),this,SLOT(atk_2()));
    }


    time->start(50);
}
void MainWindow::Mover()
{
    obstaculos *puntero=nullptr;
    for(QList <moob*>::iterator it=enemigos.begin();it!=enemigos.end();it++){
        QString onjto=colision((*it),puntero);
        if(onjto=="lat")
        {
            if(!(*it)->collidesWithItem(puntero)){
                (*it)->setVel_x((*it)->getVel_x()*-1);
            }
        }else if(onjto=="valla"){
            if(!(*it)->collidesWithItem(puntero)){
                (*it)->setVel_y((*it)->getVel_y()*-1);
            }
        }
        (*it)->move();
    }
}

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::atk_1()
{
    for (QList <boss*>::iterator it=atks.begin();it!=atks.end();it++) {
        (*it)->atk_1();
        if((*it)->getYi()+300==(*it)->getY()){
            scene->removeItem((*it));
        }
    }
}

void MainWindow::atk_2()
{
    for (QList <boss*>::iterator it=atks.begin();it!=atks.end();it++) {
        (*it)->atk_2();
//        if((*it)->getYi()+300==(*it)->getY()){
//            scene->removeItem((*it));
//       }
    }
}
void MainWindow::keyPressEvent(QKeyEvent *evento)
{

//    if(evento->key()==0x57){
//        if(!bola->collidesWithItem(&choca(x))){
//
//        }
//        else if(bola->getPosiy()-5 < choca(x).getY()){
//

//        }
//    }
//    if(evento->key()==0x53){
//        if(!bola->collidesWithItem(&choca(x))){
//
//        }
//        else if(bola->getPosiy()+5 > choca(x).getY()){
//
//        }
//    }
//    if(evento->key()==0x41){
//        if(!bola->collidesWithItem(&choca(x))){
//
//        }
//        else if(bola->getPosix()-5 < choca(x).getX()){
//
//        }
//        }


//    if(evento->key()==0x44){
//        if(!bola->collidesWithItem(&choca(x))){
//
//        }
//        else if(bola->getPosix()+5 > choca(x).getX()){

//        }
//    }



}
