#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
<<<<<<< Updated upstream
=======
    time=new QTimer;
    connect(time,SIGNAL(timeout()),this,SLOT(Mover()));
    //leer_lvl(1);
    //Boss_1();
    vidaScor = new Health();
    vidaScor->setPos(95,100);
    scene->addItem(vidaScor);
>>>>>>> Stashed changes

    niveles(0);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::niveles(int x)
{
    if(x==0){

        //añadimos el fondo
        scene=new QGraphicsScene;
        ui->graphicsView->setScene(scene);
        scene->setSceneRect(0,0,1060,570);
        scene->addRect(scene->sceneRect());
        scene->setBackgroundBrush(QBrush(QImage(":/Imagenes Proyecto final/WhatsApp Image 2020-07-08 at 6.48.30 PM.jpeg")));

        //añadimos el jugador a la escena
        jugador = new player(0,95,90,60,60);
        scene->addItem(jugador);
        jugador->setFlag(QGraphicsItem::ItemIsFocusable);
        jugador->setFocus();
        //keyPressEvent();
        jugador->setPos(95,90);
        //añadimos slime a la escena
        jugador->slime1();


        //añadimos el enemigo con ataque a distancia
<<<<<<< Updated upstream
        enemy_dis = new enemi_dis(0,0,460,100,80,60);
        enemy_dis2 = new enemi_dis(0,1,35,100,80,60);
=======
        enemy_dis = new enemi_dis(0,0,850,180);
        enemy_dis2 = new enemi_dis(0,1,10,180);

>>>>>>> Stashed changes
        scene->addItem(enemy_dis);
        enemy_dis->setPos(850,180);

        scene->addItem(enemy_dis2);
        enemy_dis2->setPos(10,180);






        //añadimos las piedras y limites a la escena
        o1=new obstaculos(55,50,50,50);scene->addItem(o1);lista_piedra.push_back(o1);
        o2=new obstaculos(55,100,50,50);scene->addItem(o2);lista_piedra.push_back(o2);
        o3=new obstaculos(55,150,50,50);scene->addItem(o3);lista_piedra.push_back(o3);
        o4=new obstaculos(105,50,50,50);scene->addItem(o4);lista_piedra.push_back(o4);
        o5=new obstaculos(155,50,50,50);scene->addItem(o5);lista_piedra.push_back(o5);

        o6=new obstaculos(850,50,50,50);scene->addItem(o6);lista_piedra.push_back(o6);
        o7=new obstaculos(900,50,50,50);scene->addItem(o7);lista_piedra.push_back(o7);
        o8=new obstaculos(950,50,50,50);scene->addItem(o8);lista_piedra.push_back(o8);
        o9=new obstaculos(950,100,50,50);scene->addItem(o9);lista_piedra.push_back(o9);
        o10=new obstaculos(950,150,50,50);scene->addItem(o10);lista_piedra.push_back(o10);

        o11=new obstaculos(55,350,50,50);scene->addItem(o11);lista_piedra.push_back(o11);
        o12=new obstaculos(55,400,50,50);scene->addItem(o12);lista_piedra.push_back(o12);
        o13=new obstaculos(55,450,50,50);scene->addItem(o13);lista_piedra.push_back(o13);
        o14=new obstaculos(105,450,50,50);scene->addItem(o14);lista_piedra.push_back(o14);
        o15=new obstaculos(155,450,50,50);scene->addItem(o15);lista_piedra.push_back(o15);

        o16=new obstaculos(850,450,50,50);scene->addItem(o16);lista_piedra.push_back(o16);
        o17=new obstaculos(900,450,50,50);scene->addItem(o17);lista_piedra.push_back(o17);
        o18=new obstaculos(950,450,50,50);scene->addItem(o18);lista_piedra.push_back(o18);
        o19=new obstaculos(950,400,50,50);scene->addItem(o19);lista_piedra.push_back(o19);
        o20=new obstaculos(950,350,50,50);scene->addItem(o20);lista_piedra.push_back(o20);

        o21=new obstaculos(500,250,50,50);scene->addItem(o21);lista_piedra.push_back(o21);
        o22=new obstaculos(500,200,50,50);scene->addItem(o22);lista_piedra.push_back(o22);
        o23=new obstaculos(500,300,50,50);scene->addItem(o23);lista_piedra.push_back(o23);
        o24=new obstaculos(550,250,50,50);scene->addItem(o24);lista_piedra.push_back(o24);
        o25=new obstaculos(450,250,50,50);scene->addItem(o25);lista_piedra.push_back(o25);
    }


    if(x==1){
        //añadimos el fondo
        scene=new QGraphicsScene;
        ui->graphicsView->setScene(scene);
        scene->setSceneRect(0,0,1111,621);
        scene->addRect(scene->sceneRect());
        scene->setBackgroundBrush(QBrush(QImage(":/Imagenes Proyecto final/fondo boss.jpeg")));

        //añadimos al boss
        B1 = new boss1(450,70,200,200);
        scene->addItem(B1);

        //añadimos al player
        jugador = new player(1,200,400,20,20);
        scene->addItem(jugador);
        jugador->setPos(200,400);
        jugador->setFlag(QGraphicsItem::ItemIsFocusable);
        jugador->setFocus();
    }

<<<<<<< Updated upstream
=======
void MainWindow::leer_lvl(int lvl_)
{
    QString lvl;
    if(lvl_==0){
        lvl="C:/Users/Usuario/Desktop/Proyecto-Final/Juego/VideoGame/lvl_1.TXT";
        //lvl="E:/Desktop/Proyecto-Final/Juego/VideoGame/lvl_1.TXT";
    }else if(lvl_==1){
        lvl="C:/Users/Usuario/Desktop/Proyecto-Final/Juego/VideoGame/lvl_2.TXT";
        //lvl="E:/Desktop/Proyecto-Final/Juego/VideoGame/lvl_2.TXT";
    }
    scene=new QGraphicsScene;
>>>>>>> Stashed changes

    if(x==2){

        //añadimos el fondo
        scene=new QGraphicsScene;
        ui->graphicsView->setScene(scene);
        scene->setSceneRect(0,0,1060,570);
        scene->addRect(scene->sceneRect());
        scene->setBackgroundBrush(QBrush(QImage(":/Imagenes Proyecto final/WhatsApp Image 2020-07-08 at 6.48.30 PM.jpeg")));

        //añadimos piedras y limites a la escena
        o1=new obstaculos(55,50,50,50);scene->addItem(o1);lista_piedra.push_back(o1);
        o2=new obstaculos(915,50,50,50);scene->addItem(o2);lista_piedra.push_back(o2);
        o3=new obstaculos(915,450,50,50);scene->addItem(o3);lista_piedra.push_back(o3);
        o4=new obstaculos(55,450,50,50);scene->addItem(o4);lista_piedra.push_back(o4);
        o5=new obstaculos(460,50,50,50);scene->addItem(o5);lista_piedra.push_back(o5);
        o6=new obstaculos(460,450,50,50);scene->addItem(o6);lista_piedra.push_back(o6);
        o7=new obstaculos(460,250,50,50);scene->addItem(o7);lista_piedra.push_back(o7);
        o8=new obstaculos(55,250,50,50);scene->addItem(o8);lista_piedra.push_back(o8);
        o9=new obstaculos(915,250,50,50);scene->addItem(o9);lista_piedra.push_back(o9);
        o10=new obstaculos(10,50,50,50);scene->addItem(o10);lista_piedra.push_back(o10);
        o11=new obstaculos(960,50,50,50);scene->addItem(o11);lista_piedra.push_back(o11);

        //añadimos el jugador a la escena
        jugador = new player(0,95,90,60,60);
        scene->addItem(jugador);
        jugador->setFlag(QGraphicsItem::ItemIsFocusable);
        jugador->setFocus();

        //añadimos el enemigo con ataque a distancia
        enemy_dis = new enemi_dis(0,0,460,50,70,60);
        enemy_dis2 = new enemi_dis(0,1,35,50,70,60);
        enemy_dis3 = new enemi_dis(0,0,460,150,70,60);
        enemy_dis4 = new enemi_dis(0,1,35,150,70,60);
        scene->addItem(enemy_dis);
        scene->addItem(enemy_dis2);
        scene->addItem(enemy_dis3);
        scene->addItem(enemy_dis4);
    }
<<<<<<< Updated upstream
=======

    time->start(20);
>>>>>>> Stashed changes
}

bool MainWindow::colision()
{
<<<<<<< Updated upstream
    QList <obstaculos *>::iterator it=lista_piedra.begin();
    for (it=lista_piedra.begin();it<lista_piedra.end();it++) {
        if(jugador->collidesWithItem((*it))){
            return  true;
=======
    QString lvl;
    if(lvl_==0){
        lvl="C:/Users/Usuario/Desktop/Proyecto-Final/Juego/VideoGame/lvl_1.TXT";
        //lvl="E:/Desktop/Proyecto-Final/Juego/VideoGame/atk_1.TXT";
    }
    else if(lvl_==1){
        lvl="C:/Users/Usuario/Desktop/Proyecto-Final/Juego/VideoGame/lvl_2.TXT";
        //lvl="E:/Desktop/Proyecto-Final/Juego/VideoGame/atk_2.TXT";
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
>>>>>>> Stashed changes
        }
    }
    return false;
}

/**
void MainWindow::keyPressEvent(QKeyEvent *event)
{
<<<<<<< Updated upstream
    //Key Event's de movimiento del jugador

    if(event->key()==0x41){
            if(!colision()){
                jugador->setPos(jugador->getX1()-5,jugador->getY1());
                jugador->setX1(jugador->getX1()-5);
                tipo=0;
            }
            else if(jugador->getX1()-5 < recorrer()->getX()){
                jugador->setPos(jugador->getX1()-5,jugador->getY1());
                jugador->setX1(jugador->getX1()-5);
                tipo=0;
            }
=======
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
    }else if(alea==2){
//        b1=new boss(550,450);scene->addItem(b1);atks.push_back(b1);
//        b2=new boss(190,430);scene->addItem(b2);atks.push_back(b2);
//        b3=new boss(910,430);scene->addItem(b3);atks.push_back(b3);
//        b4=new boss(190,500);scene->addItem(b4);atks.push_back(b4);
//        b5=new boss(910,500);scene->addItem(b5);atks.push_back(b5);
//        for(int i=0;i<5;i++){

//        }
//        connect(time,SIGNAL(timeout()),this,SLOT(atk_2()));
>>>>>>> Stashed changes
    }
    else if (event->key() == 0x44){

        for(int i=0;i<lentitud.size();i++){
            if(this->collidesWithItem(lentitud.at(i))){
                rozamiento(1);
            }
            else{
                rozamiento(0);
            }
        }

        jugador->setPos(jugador->getX1()+5,jugador->getY1());
        jugador->setX1(jugador->getX1()+5);
        tipo=1;

<<<<<<< Updated upstream
=======
obstaculos &MainWindow::colision_player()
{
    obstaculos* tempo=nullptr;
    for (QList<obstaculos*>::iterator it=lista_piedra.begin();it!=lista_piedra.end();it++) {
        if(jugador->collidesWithItem((*it))){
            obstaculos *pepo=(*it);
            return *pepo;
        }
>>>>>>> Stashed changes
    }
    else if(event->key()== 0x57){

<<<<<<< Updated upstream
        for(int i=0;i<lentitud.size();i++){
            if(this->collidesWithItem(lentitud.at(i))){
                rozamiento(1);
            }
            else{
                rozamiento(0);
            }
        }

        jugador->setPos(jugador->getX1(),jugador->getY1()-5);
        jugador->setY1(jugador->getY1()-5);


=======
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    //Key Event's de movimiento del jugador

    if(event->key()==65){       //izq


        if(!jugador->collidesWithItem(&colision_player())){
            if(nivel1==0){

                //friccion
                /**
                for(int i=0;i<lentitud.size();i++){
                    if(this->collidesWithItem(lentitud.at(i))){
                        rozamiento(1);
                    }
                    else{
                        rozamiento(0);
                    }
                }
                **/

                jugador->setPos(jugador->getX1()-5,jugador->getY1());
                jugador->setX1(jugador->getX1()-5);
                tipo=0;
            }
            else{
                jugador->setPos(jugador->x()-7,jugador->y());
            }
        }
        /**
//        else if(jugador->getX1()-5 < colision_player().getX()){

//            if(nivel1==0){

//                jugador->setPos(jugador->getX1()-3,jugador->getY1());
//                jugador->setX1(jugador->getX1()-3);
//                tipo=0;
//            }
//            else{
//                jugador->setPos(jugador->x()-7,jugador->y());
//            }
//        }
**/
        else{
            jugador->setPos(jugador->getX1()+12,jugador->getY1());
            jugador->setX1(jugador->getX1()+12);
        }
>>>>>>> Stashed changes
    }
    else if(event->key()== 0x53){

<<<<<<< Updated upstream
        for(int i=0;i<lentitud.size();i++){
            if(this->collidesWithItem(lentitud.at(i))){
                rozamiento(1);
            }
            else{
                rozamiento(0);
            }
        }

        jugador->setPos(jugador->getX1(),jugador->getY1()+5);
        jugador->setY1(jugador->getY1()+5);

    }

=======

    else if (event->key() == 68){       //der

        if(!jugador->collidesWithItem(&colision_player())){
            if(nivel1==0){
                //friccion
    //            for(int i=0;i<lentitud.size();i++){
    //                if(this->collidesWithItem(lentitud.at(i))){
    //                    rozamiento(1);
    //                }
    //                else{
    //                    rozamiento(0);
    //                }
    //            }
                jugador->setPos(jugador->getX1()+5,jugador->getY1());
                jugador->setX1(jugador->getX1()+5);
                tipo=1;
            }
            else{
                jugador->setPos(jugador->x()+7,jugador->y());
            }
        }
        /**
        else if(jugador->getX1()+5 > colision_player().getX()){

            if(nivel1==0){
                jugador->setPos(jugador->getX1()+3,jugador->getY1());
                jugador->setX1(jugador->getX1()+3);
                tipo=1;
            }
            else{
                jugador->setPos(jugador->x()+7,jugador->y());
            }
        }
        **/
        else{
            jugador->setPos(jugador->getX1()-12,jugador->getY1());
            jugador->setX1(jugador->getX1()-12);
        }
    }


    else if(event->key()== 87){     //up


        if(!jugador->collidesWithItem(&colision_player())){
            if(nivel1==0){
                //friccion
    //            for(int i=0;i<lentitud.size();i++){
    //                if(this->collidesWithItem(lentitud.at(i))){
    //                    rozamiento(1);
    //                }
    //                else{
    //                    rozamiento(0);
    //                }
    //            }
                jugador->setPos(jugador->getX1(),jugador->getY1()-5);
                jugador->setY1(jugador->getY1()-5);
            }
            else{
                jugador->setPos(jugador->x(),jugador->y()-7);

            }
        }
        /**
        else if(jugador->getY1()-5 < colision_player().getY()){

            if(nivel1==0){
                jugador->setPos(jugador->getX1(),jugador->getY1()-3);
                jugador->setY1(jugador->getY1()-3);
            }
            else{
                jugador->setPos(jugador->x(),jugador->y()-7);

            }
        }
        **/
        else{
            jugador->setPos(jugador->getX1(),jugador->getY1()+12);
            jugador->setY1(jugador->getY1()+12);
        }
    }

    else if(event->key()== 83){     //down


        if(!jugador->collidesWithItem(&colision_player())){
            if(nivel1==0){
    //            for(int i=0;i<lentitud.size();i++){
    //                if(this->collidesWithItem(lentitud.at(i))){
    //                    rozamiento(1);
    //                }
    //                else{
    //                    rozamiento(0);
    //                }
    //            }
                jugador->setPos(jugador->getX1(),jugador->getY1()+5);
                jugador->setY1(jugador->getY1()+5);
            }
            else{
                jugador->setPos(jugador->x(),jugador->y()+7);
            }
        }
        /**
        else if(jugador->getY1()-5 < colision_player().getY()){

            if(nivel1==0){
                jugador->setPos(jugador->getX1(),jugador->getY1()+3);
                jugador->setY1(jugador->getY1()+3);
            }
            else{
                jugador->setPos(jugador->x(),jugador->y()+7);
            }
        }
        **/
        else{
            jugador->setPos(jugador->getX1(),jugador->getY1()-12);
            jugador->setY1(jugador->getY1()-12);
        }
    }
>>>>>>> Stashed changes

    //Ataque basico
    else if(event->key()== Qt::Key_Space){
        if(nivel1==0){
            if(tipo==1){
                disparo = new ataque_Bas(0,tipo,jugador->getX1()+50,jugador->getY1()+20,10,10);
            }
            if(tipo==0){
                disparo = new ataque_Bas(0,tipo,jugador->getX1()-10,jugador->getY1()+20,10,10);
            }

            //disparo->setPos(x1,y1);
            scene->addItem(disparo);
        }
    }

    //Ataque especial (Mov Parabolico)
    else if(event->key()==0x43){
        if(nivel1==0){
           if(tipo==1){
                ataque_es = new tiropara(1,jugador->getX1(),jugador->getY1(),20,-45);
                scene->addItem(ataque_es);

           }
           if(tipo==0){
               ataque_es = new tiropara(0,jugador->getX1(),jugador->getY1(),20,-45);
               scene->addItem(ataque_es);
           }
        }
    }

<<<<<<< Updated upstream
=======
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
>>>>>>> Stashed changes
}
**/

<<<<<<< Updated upstream

obstaculos *MainWindow::recorrer()
=======
void MainWindow::atk_1()
>>>>>>> Stashed changes
{
    QList <obstaculos *>::iterator it=lista_piedra.begin();
    for (it=lista_piedra.begin();it<lista_piedra.end();it++) {
        if(jugador->collidesWithItem((*it))){
            return (*it);
        }
    }
    return (*it);
}
<<<<<<< Updated upstream
=======

void MainWindow::atk_2()
{
    for (QList <boss*>::iterator it=atks.begin();it!=atks.end();it++) {
        (*it)->atk_2();
//        if((*it)->getYi()+300==(*it)->getY()){
//            scene->removeItem((*it));
//       }
    }
}
>>>>>>> Stashed changes
