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
    //leer_lvl(2);
    Boss_1();



}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::colision(moob *cuerpo)
{
    for (QList <obstaculos*>::iterator it=paredes_sup.begin();it!=paredes_sup.end();it++) {
        if(cuerpo->collidesWithItem(*it)){ return "valla";}
    }
    for (QList <obstaculos*>::iterator it=paredes_lateral.begin();it!=paredes_lateral.end();it++) {
        if(cuerpo->collidesWithItem(*it)){ return "lat";}
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

void MainWindow::leer_ene(int lvl_, QGraphicsScene *scene)
{
    QString lvl;
    if(lvl_==1){
        lvl="E:/Desktop/Proyecto-Final/Juego/VideoGame/enem_lvl1.TXT";
    }
//    else if(lvl_==2){
//        lvl="E:/Desktop/Proyecto-Final/Juego/VideoGame/lvl_2.TXT";
//    }

    //e1=new moob(900,-10,50,50,"perro");scene->addItem(e1);enemigos.push_back(e1);

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
            scene->addItem(new moob(coordx,coordy,w_,h_,textura));
            enemigos.push_back(new moob(coordx,coordy,w_,h_,textura));
            comas=0;

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
}

void MainWindow::Boss_1()
{

    scene=new QGraphicsScene;

    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,1111,621);
    scene->setBackgroundBrush(QBrush(QImage(":/Imagenes Proyecto final/escena_boss.png")));
    p1=new corazon(250,250);scene->addItem(p1);
    b1=new boss(50,0);scene->addItem(b1);atks.push_back(b1);
    b2=new boss(150,0);scene->addItem(b2);atks.push_back(b2);
    b3=new boss(250,0);scene->addItem(b3);atks.push_back(b3);
    b4=new boss(350,0);scene->addItem(b4);atks.push_back(b4);
    b5=new boss(450,0);scene->addItem(b5);atks.push_back(b5);
    b6=new boss(550,0);scene->addItem(b6);atks.push_back(b6);
    b7=new boss(650,0);scene->addItem(b7);atks.push_back(b7);
    b8=new boss(750,0);scene->addItem(b8);atks.push_back(b8);
    b9=new boss(850,0);scene->addItem(b9);atks.push_back(b9);
    b10=new boss(950,0);scene->addItem(b10);atks.push_back(b10);
    connect(time,SIGNAL(timeout()),this,SLOT(atk_1()));
    time->start(50);

        int pp=1;
    for (QList <boss*>::iterator it=atks.begin();it!=atks.end();it++) {
        (*it)->setVelx((*it)->getVelx()*pp);
        pp=pp*-1;
    }




}
void MainWindow::Mover()
{

    for(QList <moob*>::iterator it=enemigos.begin();it!=enemigos.end();it++){
        QString onjto=colision((*it));
        if(onjto=="lat")
        {
            (*it)->setVel_x((*it)->getVel_x()*-1);
            //mover
        }else if(onjto=="valla"){
            (*it)->setVel_y((*it)->getVel_y()*-1);
            //mover
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
