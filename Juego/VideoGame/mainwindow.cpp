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
    connect(time,SIGNAL(timeout()),this,SLOT(Mover()));
    //Boss_1();

    niveles(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::niveles(int x)
{
    if(x==0){
        nivel1=0;
        //añadimos el fondo
        leer_lvl(x);

        //añadimos el jugador a la escena
        jugador = new player(0,200,200,60,60);
        scene->addItem(jugador);
        jugador->setFlag(QGraphicsItem::ItemIsFocusable);
        jugador->setFocus();
        //jugador->setPos(95,90);
        //añadimos slime a la escena
        jugador->slime1();

        //
        //per=new muneco(200,200,70,70);scene->addItem(per);per->setPos(200,200);
        //

        //añadimos el enemigo con ataque a distancia
        enemy_dis = new enemi_dis(0,0,850,200);
        enemy_dis2 = new enemi_dis(0,1,25,200);
        scene->addItem(enemy_dis);
        scene->addItem(enemy_dis2);

        e1=new moob(0,-10,50,50,"perro");scene->addItem(e1);enemigos.push_back(e1);
        e2=new moob(900,-10,50,50,"perro");scene->addItem(e2);enemigos.push_back(e2);
        e3=new moob(300,400,50,50,"perro");scene->addItem(e3);enemigos.push_back(e3);
        e4=new moob(700,400,50,50,"perro");scene->addItem(e4);enemigos.push_back(e4);
        e5=new moob(7000,4000,50,50,"perro");scene->addItem(e5);enemigos.push_back(e5);
    }

    if(x==1){
        nivel1=1;
        //añadimos el fondo
        scene=new QGraphicsScene;
        ui->graphicsView->setScene(scene);
        scene->setSceneRect(-10,-10,1111,621);
        scene->addRect(scene->sceneRect());
        scene->setBackgroundBrush(QBrush(QImage(":/Imagenes Proyecto final/fondo boss.jpeg")));

        //añadimos al boss
        Jefe1 = new boss_CL(450,70,200,200);
        scene->addItem(Jefe1);


        //añadimos al player
        jugador = new player(1,200,300,20,20);
        scene->addItem(jugador);
        jugador->setPos(200,100);
        jugador->setFlag(QGraphicsItem::ItemIsFocusable);
        jugador->setFocus();
    }
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
    if(lvl_==0){
        //lvl="C:/Users/Usuario/Desktop/Proyecto-Final/Juego/VideoGame/lvl_1.TXT";
        lvl="E:/Desktop/Proyecto-Final/Juego/VideoGame/lvl_1.TXT";
    }else if(lvl_==1){
        //lvl="C:/Users/Usuario/Desktop/Proyecto-Final/Juego/VideoGame/lvl_2.TXT";
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

void MainWindow::Boss_2()
{
    int alea=1;
    scene=new QGraphicsScene;

    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,1111,621);
    scene->setBackgroundBrush(QBrush(QImage(":/Imagenes Proyecto final/escena_boss.png")));
    //Añadimos al player
//    jugador = new player(1,200,300,20,20);
//    scene->addItem(jugador);
//    jugador->setPos(200,100);
//    jugador->setFlag(QGraphicsItem::ItemIsFocusable);
//    jugador->setFocus();

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
    }


    time->start(50);
}

obstaculos &MainWindow::colision_player()
{
    obstaculos* tempo=nullptr;
    for (QList<obstaculos*>::iterator it=lista_piedra.begin();it!=lista_piedra.end();it++) {
        if(jugador->collidesWithItem((*it))){
            obstaculos *pepo=(*it);
            return *pepo;
        }
    }
    return *tempo;
}

bool MainWindow::prueba_colsion()
{
    for(int i=0,n=lista_piedra.size();i<n;i++){
        if(typeid ((lista_piedra[i])) == typeid (per)){
            return true;
        }
    }
    return false;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    //Key Event's de movimiento del jugador

    if(event->key()==65){       //izq
        if(!jugador->collidesWithItem(&colision_player())){
            jugador->setPos(jugador->getX1()-7,jugador->getY1());
            jugador->setX1(jugador->getX1()-7);
            tipo=0;
        }
        else if(jugador->getX1()-7 < colision_player().getX()){
            jugador->setPos(jugador->getX1()-7,jugador->getY1());
            jugador->setX1(jugador->getX1()-7);
            tipo=0;
    }
    }

    else if (event->key() == 68){       //der
        if(!jugador->collidesWithItem(&colision_player())){
            jugador->setPos(jugador->getX1()+7,jugador->getY1());
            jugador->setX1(jugador->getX1()+7);
            tipo=1;
        }
        else if(jugador->getX1()+7 > colision_player().getX()){
            jugador->setPos(jugador->getX1()+7,jugador->getY1());
            jugador->setX1(jugador->getX1()+7);
            tipo=1;
        }

    }

    else if(event->key()== 87){     //up
        if(!jugador->collidesWithItem(&colision_player())){
            jugador->setPos(jugador->getX1(),jugador->getY1()-7);
            jugador->setY1(jugador->getY1()-7);
        }
        else if(jugador->getY1()-7 < colision_player().getY()){
            jugador->setPos(jugador->getX1(),jugador->getY1()-7);
            jugador->setY1(jugador->getY1()-7);
        }
    }

    else if(event->key()== 83){     //down
        if(!jugador->collidesWithItem(&colision_player())){
            jugador->setPos(jugador->getX1(),jugador->getY1()+7);
            jugador->setY1(jugador->getY1()+7);
        }
        else if(jugador->getY1()+7 > colision_player().getY()){
            jugador->setPos(jugador->getX1(),jugador->getY1()+7);
            jugador->setY1(jugador->getY1()+7);
        }
    }

    //Ataque basico
    else if(event->key()== Qt::Key_Space){
        if(nivel1==0){
            if(tipo==1){
                disparo = new ataque_Bas(0,tipo);
                disparo->setPos(jugador->getX1()+70,jugador->getY1()+20);
            }
            if(tipo==0){
                disparo = new ataque_Bas(0,tipo);
                disparo->setPos(jugador->getX1()-20,jugador->getY1()+20);
            }

            scene->addItem(disparo);
        }
    }

    //Ataque especial (Mov Parabolico)
    else if(event->key()==67){
        if(nivel1==0){
           if(tipo==1){
                ataque_es = new tiropara(1,jugador->getX1()+50,jugador->getY1(),30,-45);
                ataque_es->setPos(jugador->getX1()+50,jugador->getY1());
           }
           if(tipo==0){
               ataque_es = new tiropara(0,jugador->getX1()-10,jugador->getY1(),30,-45);
               ataque_es->setPos(jugador->getX1()-10,jugador->getY1());
           }

           scene->addItem(ataque_es);
        }
    }

    if(tipo==0){
        if(imagen==2){
            imagen=3;

            jugador->setPixmap(QPixmap(":/Imagenes Proyecto final/6 Deceased/Caminar_Player/Deceased_walk5.png").scaled(60,60));

        }
        else if(imagen==3){
            imagen=4;

            jugador->setPixmap(QPixmap(":/Imagenes Proyecto final/6 Deceased/Caminar_Player/Deceased_walk4.png").scaled(60,60));

        }
        else if(imagen==4){
            imagen=5;
            jugador->setPixmap(QPixmap(":/Imagenes Proyecto final/6 Deceased/Caminar_Player/Deceased_walk3.png").scaled(60,60));
        }
        else if(imagen==5){
            imagen=6;

            jugador->setPixmap(QPixmap(":/Imagenes Proyecto final/6 Deceased/Caminar_Player/Deceased_walk2.png").scaled(60,60));
        }
        else if(imagen==6){
            imagen=2;

            jugador->setPixmap(QPixmap(":/Imagenes Proyecto final/6 Deceased/Caminar_Player/Deceased_walk.png").scaled(60,60));
        }
    }

    if(tipo==1){
        if(imagen==2){
            imagen=3;
            jugador->setPixmap(QPixmap(":/Imagenes Proyecto final/6 Deceased/Caminar_Player_Der/Deceased_walk5Der.png").scaled(60,60));
        }
        else if(imagen==3){
            imagen=4;
            jugador->setPixmap(QPixmap(":/Imagenes Proyecto final/6 Deceased/Caminar_Player_Der/Deceased_walk4Der.png").scaled(60,60));
        }
        else if(imagen==4){
            imagen=5;
            jugador->setPixmap(QPixmap(":/Imagenes Proyecto final/6 Deceased/Caminar_Player_Der/Deceased_walk3Der.png").scaled(60,60));
        }
        else if(imagen==5){
            imagen=6;
            jugador->setPixmap(QPixmap(":/Imagenes Proyecto final/6 Deceased/Caminar_Player_Der/Deceased_walk2Der.png").scaled(60,60));
        }
        else if(imagen==6){
            imagen=2;
            jugador->setPixmap(QPixmap(":/Imagenes Proyecto final/6 Deceased/Caminar_Player_Der/Deceased_walk1Der").scaled(60,60));
        }

    }
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
    }
}

