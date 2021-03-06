#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <math.h>
#include <string>

extern MainWindow * game;

MainWindow::MainWindow(int tipo, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    view->setScene(scene);
    view->resize(1150,650);
    this->resize(1150,650);

    multi = tipo;
    time=new QTimer;
    //connect(time,SIGNAL(timeout()),this,SLOT(Mover()));
    niveles(0);

    puntaje = new Score();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::niveles(int x)
{
    if(x==0){

        //
        nivel1=0;
        //añadimos el fondo
        leer_lvl(x);

        //Añadimos el slime
        lentitud.push_back(new slime(200,200));
        lentitud.push_back(new slime(300,400));
        lentitud.push_back(new slime(800,250));
        lentitud.push_back(new slime(600,350));
        for(int i=0;i<lentitud.size();i++){
            lentitud[i]->setPos(lentitud[i]->getX(),lentitud[i]->getY());
            scene->addItem(lentitud[i]);
        }

        //añadimos el jugador a la escena
        jugador = new player(1,0,400,100,60,60);
        jugador2=nullptr;
        scene->addItem(jugador);
        rects.push_back(jugador);
        jugador->setFlag(QGraphicsItem::ItemIsFocusable);
        jugador->setFocus();
        view->centerOn(rects.at(0)->x(),rects.at(0)->y());
        jugador2=nullptr;

        if(multi==2){
            jugador2 = new player(2,0,600,100,60,60);
            scene->addItem(jugador2);
            rects.push_back(jugador2);
            jugador2->setFlag(QGraphicsItem::ItemIsFocusable);
            jugador2->setFocus();
        }

        //añadimos el enemigo con ataque a distancia
        enemy_dis = new enemi_dis(0,0,850,180);
        enemy_dis2 = new enemi_dis(0,1,25,180);
        scene->addItem(enemy_dis);
        scene->addItem(enemy_dis2);



        e1=new moob(0,-10,50,50,"perro");scene->addItem(e1);
        e2=new moob(900,-10,50,50,"perro");scene->addItem(e2);
        e3=new moob(300,400,50,50,"perro");scene->addItem(e3);
        e4=new moob(700,400,50,50,"perro");scene->addItem(e4);
        e5=new moob(7000,4000,50,50,"perro");scene->addItem(e5);


    }

    if(x==1){
        nivel1=1;
        //añadimos el fondo
        scene=new QGraphicsScene;
        ui->graphicsView->setScene(scene);
        scene->setSceneRect(-10,-10,1111,621);
        scene->addRect(scene->sceneRect());
        scene->setBackgroundBrush(QBrush(QImage(":/Imagenes Proyecto final/fondo.png")));



        //añadimos al boss
        Jefe1 = new boss_CL(450,70,200,200);
        scene->addItem(Jefe1);
        qDebug()<<"PRIMER CAMBIO";

        //añadimos los limites de movimiento
        pared1=new obstaculos(110,286,910,5,"nada");scene->addItem(pared1);p_boss.push_back(pared1);
        pared2=new obstaculos(109,285,5,310,"nada");scene->addItem(pared2);p_boss.push_back(pared2);
        pared3=new obstaculos(110,595,910,5,"nada");scene->addItem(pared3);p_boss.push_back(pared3);
        pared4=new obstaculos(1018,285,5,310,"nada");scene->addItem(pared4);p_boss.push_back(pared4);

        //añadimos al player
        jugador = new player(3,1,200,300,20,20);
        jugador2=nullptr;
        scene->addItem(jugador);
        jugador->setFlag(QGraphicsItem::ItemIsFocusable);
        jugador->setFocus();
        jugador2=nullptr;

        if(multi==2){
            jugador2 = new player(4,1,400,300,20,20);
            scene->addItem(jugador2);
            jugador2->setFlag(QGraphicsItem::ItemIsFocusable);
            jugador2->setFocus();
        }
    }

    if(x==2){
        qDebug()<<"SEGUNDO CAMBIO";
        nivel1=0;
        //añadimos el fondo
        leer_lvl(1);

        //Añadimos el slime
        lentitud.push_back(new slime(200,200));
        lentitud.push_back(new slime(300,400));
        lentitud.push_back(new slime(800,250));
        lentitud.push_back(new slime(600,350));
        for(int i=0;i<lentitud.size();i++){
            lentitud[i]->setPos(lentitud[i]->getX(),lentitud[i]->getY());
            scene->addItem(lentitud[i]);
        }

        //añadimos el jugador a la escena
        jugador = new player(1,0,400,100,60,60);
        scene->addItem(jugador);
        jugador->setFlag(QGraphicsItem::ItemIsFocusable);
        jugador->setFocus();

        jugador2=nullptr;

        if(multi==2){
            jugador2 = new player(2,0,600,100,60,60);
            scene->addItem(jugador2);
            rects.push_back(jugador2);
            jugador2->setFlag(QGraphicsItem::ItemIsFocusable);
            jugador2->setFocus();
        }

        //añadimos el enemigo con ataque a distancia
        enemy_dis = new enemi_dis(0,0,850,100);
        enemy_dis2 = new enemi_dis(0,1,20,100);
        scene->addItem(enemy_dis);
        scene->addItem(enemy_dis2);
        enemy_dis3 = new enemi_dis(0,0,850,300);scene->addItem(enemy_dis3);
        enemy_dis4 = new enemi_dis(0,1,20,300);scene->addItem(enemy_dis4);



        e1=new moob(0,-10,50,50,"perro");scene->addItem(e1);
        e2=new moob(900,-10,50,50,"perro");scene->addItem(e2);
        e3=new moob(300,400,50,50,"perro");scene->addItem(e3);
        e4=new moob(700,400,50,50,"perro");scene->addItem(e4);
        e5=new moob(7000,4000,50,50,"perro");scene->addItem(e5);
    }

    if(x==3){
        nivel1=1;
        //añadimos el fondo
        scene=new QGraphicsScene;
        ui->graphicsView->setScene(scene);
        scene->setSceneRect(-10,-10,1111,621);
        scene->addRect(scene->sceneRect());
        scene->setBackgroundBrush(QBrush(QImage(":/Imagenes Proyecto final/fondo.png")));

        //añadimos el boss
        gf=new boss_jm(450,70,200,200);
        scene->addItem(gf);

        //añadimos los limites de movimiento
        pared1=new obstaculos(110,286,910,5,"nada");scene->addItem(pared1);p_boss.push_back(pared1);
        pared2=new obstaculos(109,285,5,310,"nada");scene->addItem(pared2);p_boss.push_back(pared2);
        pared3=new obstaculos(110,595,910,5,"nada");scene->addItem(pared3);p_boss.push_back(pared3);
        pared4=new obstaculos(1018,285,5,310,"nada");scene->addItem(pared4);p_boss.push_back(pared4);

        //añadimos al player
        jugador = new player(3,1,500,500,20,20);
        scene->addItem(jugador);
        jugador->setFlag(QGraphicsItem::ItemIsFocusable);
        jugador->setFocus();

        jugador2=nullptr;

        if(multi==2){
            jugador2 = new player(4,1,500,600,20,20);
            scene->addItem(jugador2);
            jugador2->setFlag(QGraphicsItem::ItemIsFocusable);
            jugador2->setFocus();
        }

        //jugador->setPos(200,100);
        jugador->setFlag(QGraphicsItem::ItemIsFocusable);
        jugador->setFocus();
    }

    if(x==5){
        //añadimos el fondo
        scene=new QGraphicsScene;
        ui->graphicsView->setScene(scene);
        scene->setSceneRect(-10,-10,1111,621);
        scene->addRect(scene->sceneRect());
        scene->setBackgroundBrush(QBrush(QImage(":/Imagenes Proyecto final/final.png")));
    }
    if(x==4){
        //añadimos el fondo
        scene=new QGraphicsScene;
        ui->graphicsView->setScene(scene);
        scene->setSceneRect(-10,-10,1111,621);
        scene->addRect(scene->sceneRect());
        scene->setBackgroundBrush(QBrush(QImage(":/Imagenes Proyecto final/perder.png")));
    }
}

void MainWindow::guardado(int nivel)
{
    //QFile fil("E:/Desktop/Proyecto-Final/Juego/VideoGame/nivel.txt");
    QFile fil(":/nivel.TXT");
    fil.open(QIODevice::WriteOnly | QIODevice::Text);
    if(!fil.isOpen()){
        qDebug()<<"El archivo no se abrio";
    }
    QTextStream stream(&fil);
    stream << nivel;
    fil.flush();
    fil.close();

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
        lvl=":/lvl_1.TXT";
        //lvl="E:/Desktop/Proyecto-Final/Juego/VideoGame/lvl_1.TXT";
    }else if(lvl_==1){
        lvl=":/lvl_2.TXT";
        //lvl="E:/Desktop/Proyecto-Final/Juego/VideoGame/lvl_2.TXT";
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

obstaculos &MainWindow::colision_player()
{

    obstaculos* tempo=nullptr;
    for (QList<obstaculos*>::iterator it=lista_piedra.begin();it!=lista_piedra.end();it++) {
        if(jugador->collidesWithItem((*it))){
            obstaculos *pepo=(*it);
            return *pepo;
        }
    }
    for (QList<obstaculos*>::iterator it=p_boss.begin();it!=p_boss.end();it++) {
        if(jugador->collidesWithItem((*it))){
            obstaculos *pepo=(*it);
            return *pepo;
        }
    }
    return *tempo;
}

obstaculos &MainWindow::colision_player2()
{
    obstaculos* tempo=nullptr;
    for (QList<obstaculos*>::iterator it=lista_piedra.begin();it!=lista_piedra.end();it++) {
        if(jugador2->collidesWithItem((*it))){
            obstaculos *pepo=(*it);
            return *pepo;
        }
    }
    for (QList<obstaculos*>::iterator it=p_boss.begin();it!=p_boss.end();it++) {
        if(jugador2->collidesWithItem((*it))){
            obstaculos *pepo=(*it);
            return *pepo;
        }
    }
    return *tempo;
}

void MainWindow::rozamiento(short n)
{
    if(n==0){
        fuerzaT=15-R1*6;
    }
    if(n==1){
        fuerzaT=15-R2*6;
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{

    if(multi==1){
        animacion = 0;
        //Key Event's de movimiento del jugador

        if(event->key()==65){       //izq

            if(nivel1==0){

                for(int i=0;i<lentitud.size();i++){
                    if(jugador->collidesWithItem(lentitud[i])){
                        rozamiento(1);
                        break;
                    }
                    else {
                        rozamiento(0);
                    }
                }


                //qDebug()<<fuerzaT;

                if(!jugador->collidesWithItem(&colision_player())){
                    jugador->setPos(jugador->getX1()-fuerzaT,jugador->getY1());
                    jugador->setX1(jugador->getX1()-fuerzaT);
                    view->centerOn(rects.at(0)->x(),rects.at(0)->y());
                    tipo=0;
                }
                else if(jugador->getX1()-5 < colision_player().getX()){
                    jugador->setPos(jugador->getX1()-fuerzaT,jugador->getY1());
                    jugador->setX1(jugador->getX1()-fuerzaT);
                    view->centerOn(rects.at(0)->x(),rects.at(0)->y());
                    tipo=0;
                }
            }
            else{
                if(!jugador->collidesWithItem(&colision_player())){
                    jugador->setPos(jugador->getX1()-7,jugador->getY1());
                    jugador->setX1(jugador->getX1()-7);
                    view->centerOn(rects.at(0)->x(),rects.at(0)->y());
                    tipo=0;
                }

                else if(jugador->getX1()+5 > colision_player().getX()){
                    jugador->setPos(jugador->getX1()+7,jugador->getY1());
                    jugador->setX1(jugador->getX1()+7);
                    view->centerOn(rects.at(0)->x(),rects.at(0)->y());
                    tipo=1;
                }
            }
        }

        else if (event->key() == 68){       //der

            if(nivel1==0){

                for(int i=0;i<lentitud.size();i++){
                    if(jugador->collidesWithItem(lentitud[i])){
                        rozamiento(1);
                        break;
                    }
                    else {
                        rozamiento(0);
                    }
                }

                //qDebug()<<fuerzaT;

                if(!jugador->collidesWithItem(&colision_player())){
                    jugador->setPos(jugador->getX1()+fuerzaT,jugador->getY1());
                    jugador->setX1(jugador->getX1()+fuerzaT);
                    view->centerOn(rects.at(0)->x(),rects.at(0)->y());
                    tipo=1;
                }
                else if(jugador->getX1()+5 > colision_player().getX()){
                    jugador->setPos(jugador->getX1()+fuerzaT,jugador->getY1());
                    jugador->setX1(jugador->getX1()+fuerzaT);
                    view->centerOn(rects.at(0)->x(),rects.at(0)->y());
                    tipo=1;
                }
            }
            else{

                if(!jugador->collidesWithItem(&colision_player())){
                    jugador->setPos(jugador->getX1()+7,jugador->getY1());
                    jugador->setX1(jugador->getX1()+7);
                    view->centerOn(rects.at(0)->x(),rects.at(0)->y());
                    tipo=1;
                }
                else if(jugador->getX1()-5 < colision_player().getX()){
                    jugador->setPos(jugador->getX1()-7,jugador->getY1());
                    jugador->setX1(jugador->getX1()-7);
                    view->centerOn(rects.at(0)->x(),rects.at(0)->y());
                    tipo=0;
                }
            }

        }

        else if(event->key()== 87){     //up

            if(nivel1==0){

                for(int i=0;i<lentitud.size();i++){
                    if(jugador->collidesWithItem(lentitud[i])){
                        rozamiento(1);
                        break;
                    }
                    else {
                        rozamiento(0);
                    }
                }

                //qDebug()<<fuerzaT;

                if(!jugador->collidesWithItem(&colision_player())){
                    jugador->setPos(jugador->getX1(),jugador->getY1()-fuerzaT);
                    jugador->setY1(jugador->getY1()-fuerzaT);
                    view->centerOn(rects.at(0)->x(),rects.at(0)->y());
                }
                else if(jugador->getY1()-5 < colision_player().getY()){
                    jugador->setPos(jugador->getX1(),jugador->getY1()-fuerzaT);
                    jugador->setY1(jugador->getY1()-fuerzaT);
                    view->centerOn(rects.at(0)->x(),rects.at(0)->y());
                }
            }
            else{
                if(!jugador->collidesWithItem(&colision_player())){
                    jugador->setPos(jugador->getX1(),jugador->getY1()-7);
                    jugador->setY1(jugador->getY1()-7);
                    view->centerOn(rects.at(0)->x(),rects.at(0)->y());
                }

                else if(jugador->getY1()+5 > colision_player().getY()){
                    jugador->setPos(jugador->getX1(),jugador->getY1()+7);
                    jugador->setY1(jugador->getY1()+7);
                    view->centerOn(rects.at(0)->x(),rects.at(0)->y());
                }
            }
        }

        else if(event->key()== 83){     //down

            if(nivel1==0){

                for(int i=0;i<lentitud.size();i++){
                    if(jugador->collidesWithItem(lentitud[i])){
                        rozamiento(1);
                        break;
                    }
                    else {
                        rozamiento(0);
                    }
                }

                //qDebug()<<fuerzaT;

                if(!jugador->collidesWithItem(&colision_player())){
                    jugador->setPos(jugador->getX1(),jugador->getY1()+fuerzaT);
                    jugador->setY1(jugador->getY1()+fuerzaT);
                    view->centerOn(rects.at(0)->x(),rects.at(0)->y());
                }
                else if(jugador->getY1()+5 > colision_player().getY()){
                    jugador->setPos(jugador->getX1(),jugador->getY1()+fuerzaT);
                    jugador->setY1(jugador->getY1()+fuerzaT);
                    view->centerOn(rects.at(0)->x(),rects.at(0)->y());
                }
            }
            else{

                if(!jugador->collidesWithItem(&colision_player())){
                    jugador->setPos(jugador->getX1(),jugador->getY1()+7);
                    jugador->setY1(jugador->getY1()+7);
                    view->centerOn(rects.at(0)->x(),rects.at(0)->y());
                }
                else if(jugador->getY1()-5 < colision_player().getY()){
                    jugador->setPos(jugador->getX1(),jugador->getY1()-7);
                    jugador->setY1(jugador->getY1()-7);
                    view->centerOn(rects.at(0)->x(),rects.at(0)->y());
                }
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
    }

    if(multi==2){


        //Key Event's de movimiento del jugador

        if(event->key()==65){       //izq
            animacion=0;
            if(nivel1==0){

                for(int i=0;i<lentitud.size();i++){
                    if(jugador->collidesWithItem(lentitud[i])){
                        rozamiento(1);
                        break;
                    }
                    else {
                        rozamiento(0);
                    }
                }


                //qDebug()<<fuerzaT;

                if(!jugador->collidesWithItem(&colision_player())){
                    jugador->setPos(jugador->getX1()-fuerzaT,jugador->getY1());
                    jugador->setX1(jugador->getX1()-fuerzaT);
                    view->centerOn(rects.at(0)->x(),rects.at(0)->y());
                    tipo=0;
                }
                else if(jugador->getX1()-5 < colision_player().getX()){
                    jugador->setPos(jugador->getX1()-fuerzaT,jugador->getY1());
                    jugador->setX1(jugador->getX1()-fuerzaT);
                    view->centerOn(rects.at(0)->x(),rects.at(0)->y());
                    tipo=0;
                }
            }
            else{
                if(!jugador->collidesWithItem(&colision_player())){
                    jugador->setPos(jugador->getX1()-7,jugador->getY1());
                    jugador->setX1(jugador->getX1()-7);
                    view->centerOn(rects.at(0)->x(),rects.at(0)->y());
                    tipo=0;
                }
                //--------------------
                else if(jugador->getX1()+5 > colision_player().getX()){
    //                qDebug()<<"jugador x: "<<jugador->getX1()<<"  y: "<<jugador->getY1();
    //                qDebug()<<"pared   x: "<<colision_player().getX()<<"  y: "<<colision_player().getY();
                    jugador->setPos(jugador->getX1()+7,jugador->getY1());
                    jugador->setX1(jugador->getX1()+7);
                    view->centerOn(rects.at(0)->x(),rects.at(0)->y());
                    tipo=1;
                }
            }
        }

        if(event->key() == 68){       //der
            animacion = 0;
            if(nivel1==0){

                for(int i=0;i<lentitud.size();i++){
                    if(jugador->collidesWithItem(lentitud[i])){
                        rozamiento(1);
                        break;
                    }
                    else {
                        rozamiento(0);
                    }
                }

                //qDebug()<<fuerzaT;

                if(!jugador->collidesWithItem(&colision_player())){
                    jugador->setPos(jugador->getX1()+fuerzaT,jugador->getY1());
                    jugador->setX1(jugador->getX1()+fuerzaT);
                    view->centerOn(rects.at(0)->x(),rects.at(0)->y());
                    tipo=1;
                }
                else if(jugador->getX1()+5 > colision_player().getX()){
                    jugador->setPos(jugador->getX1()+fuerzaT,jugador->getY1());
                    jugador->setX1(jugador->getX1()+fuerzaT);
                    view->centerOn(rects.at(0)->x(),rects.at(0)->y());
                    tipo=1;
                }
            }
            else{

                if(!jugador->collidesWithItem(&colision_player())){
                    jugador->setPos(jugador->getX1()+7,jugador->getY1());
                    jugador->setX1(jugador->getX1()+7);
                    view->centerOn(rects.at(0)->x(),rects.at(0)->y());
                    tipo=1;
                }
                else if(jugador->getX1()-5 < colision_player().getX()){
    //                qDebug()<<"jugador x: "<<jugador->getX1()<<"  y: "<<jugador->getY1();
    //                qDebug()<<"pared   x: "<<colision_player().getX()<<"  y: "<<colision_player().getY();
                    jugador->setPos(jugador->getX1()-7,jugador->getY1());
                    jugador->setX1(jugador->getX1()-7);
                    view->centerOn(rects.at(0)->x(),rects.at(0)->y());
                    tipo=0;
                }
            }

        }

        if(event->key()== 87){     //up
            animacion = 0;
            if(nivel1==0){

                for(int i=0;i<lentitud.size();i++){
                    if(jugador->collidesWithItem(lentitud[i])){
                        rozamiento(1);
                        break;
                    }
                    else {
                        rozamiento(0);
                    }
                }

                //qDebug()<<fuerzaT;

                if(!jugador->collidesWithItem(&colision_player())){
                    jugador->setPos(jugador->getX1(),jugador->getY1()-fuerzaT);
                    jugador->setY1(jugador->getY1()-fuerzaT);
                    view->centerOn(rects.at(0)->x(),rects.at(0)->y());
                }
                else if(jugador->getY1()-5 < colision_player().getY()){
                    jugador->setPos(jugador->getX1(),jugador->getY1()-fuerzaT);
                    jugador->setY1(jugador->getY1()-fuerzaT);
                    view->centerOn(rects.at(0)->x(),rects.at(0)->y());
                }
            }
            else{
                if(!jugador->collidesWithItem(&colision_player())){
                    jugador->setPos(jugador->getX1(),jugador->getY1()-7);
                    jugador->setY1(jugador->getY1()-7);
                    view->centerOn(rects.at(0)->x(),rects.at(0)->y());
                }

                else if(jugador->getY1()+5 > colision_player().getY()){
    //                qDebug()<<"jugador x: "<<jugador->getX1()<<"  y: "<<jugador->getY1();
    //                qDebug()<<"pared   x: "<<colision_player().getX()<<"  y: "<<colision_player().getY();
                    jugador->setPos(jugador->getX1(),jugador->getY1()+7);
                    jugador->setY1(jugador->getY1()+7);
                    view->centerOn(rects.at(0)->x(),rects.at(0)->y());
                }
            }
        }

        if(event->key()== 83){     //down
            animacion = 0;
            if(nivel1==0){

                for(int i=0;i<lentitud.size();i++){
                    if(jugador->collidesWithItem(lentitud[i])){
                        rozamiento(1);
                        break;
                    }
                    else {
                        rozamiento(0);
                    }
                }

                //qDebug()<<fuerzaT;

                if(!jugador->collidesWithItem(&colision_player())){
                    jugador->setPos(jugador->getX1(),jugador->getY1()+fuerzaT);
                    jugador->setY1(jugador->getY1()+fuerzaT);
                    view->centerOn(rects.at(0)->x(),rects.at(0)->y());
                }
                else if(jugador->getY1()+5 > colision_player().getY()){
                    jugador->setPos(jugador->getX1(),jugador->getY1()+fuerzaT);
                    jugador->setY1(jugador->getY1()+fuerzaT);
                    view->centerOn(rects.at(0)->x(),rects.at(0)->y());
                }
            }
            else{

                if(!jugador->collidesWithItem(&colision_player())){
                    jugador->setPos(jugador->getX1(),jugador->getY1()+7);
                    jugador->setY1(jugador->getY1()+7);
                    view->centerOn(rects.at(0)->x(),rects.at(0)->y());
                }
                else if(jugador->getY1()-5 < colision_player().getY()){
    //                qDebug()<<"jugador x: "<<jugador->getX1()<<"  y: "<<jugador->getY1();
    //                qDebug()<<"pared   x: "<<colision_player().getX()<<"  y: "<<colision_player().getY();
                    jugador->setPos(jugador->getX1(),jugador->getY1()-7);
                    jugador->setY1(jugador->getY1()-7);
                    view->centerOn(rects.at(0)->x(),rects.at(0)->y());
                }
            }
        }

        //Ataque basico
        if(event->key()== Qt::Key_Space){
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
        if(event->key()==67){
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


        //Key Event's de movimiento del jugador2

        if(event->key()==74){       //izq
            animacion=1;
            if(nivel1==0){

                for(int i=0;i<lentitud.size();i++){
                    if(jugador2->collidesWithItem(lentitud[i])){
                        rozamiento(1);
                        break;
                    }
                    else {
                        rozamiento(0);
                    }
                }


                //qDebug()<<fuerzaT;

                if(!jugador2->collidesWithItem(&colision_player2())){
                    jugador2->setPos(jugador2->getX1()-fuerzaT,jugador2->getY1());
                    jugador2->setX1(jugador2->getX1()-fuerzaT);
                    view->centerOn(rects.at(1)->x(),rects.at(1)->y());
                    tipo=0;
                }
                else if(jugador2->getX1()-5 < colision_player2().getX()){
                    jugador2->setPos(jugador2->getX1()-fuerzaT,jugador2->getY1());
                    jugador2->setX1(jugador2->getX1()-fuerzaT);
                    view->centerOn(rects.at(1)->x(),rects.at(1)->y());
                    tipo=0;
                }
            }
            else{
                if(!jugador2->collidesWithItem(&colision_player2())){
                    jugador2->setPos(jugador2->getX1()-7,jugador2->getY1());
                    jugador2->setX1(jugador2->getX1()-7);
                    view->centerOn(rects.at(1)->x(),rects.at(1)->y());
                    tipo=0;
                }
                //--------------------
                else if(jugador2->getX1()+5 > colision_player2().getX()){
    //                qDebug()<<"jugador x: "<<jugador->getX1()<<"  y: "<<jugador->getY1();
    //                qDebug()<<"pared   x: "<<colision_player().getX()<<"  y: "<<colision_player().getY();
                    jugador2->setPos(jugador2->getX1()+7,jugador2->getY1());
                    jugador2->setX1(jugador2->getX1()+7);
                    view->centerOn(rects.at(1)->x(),rects.at(1)->y());
                    tipo=1;
                }
            }
        }

        if (event->key() == 76){    //der
            animacion=1;
            if(nivel1==0){

                for(int i=0;i<lentitud.size();i++){
                    if(jugador2->collidesWithItem(lentitud[i])){
                        rozamiento(1);
                        break;
                    }
                    else {
                        rozamiento(0);
                    }
                }

                //qDebug()<<fuerzaT;

                if(!jugador2->collidesWithItem(&colision_player2())){
                    jugador2->setPos(jugador2->getX1()+fuerzaT,jugador2->getY1());
                    jugador2->setX1(jugador2->getX1()+fuerzaT);
                    view->centerOn(rects.at(1)->x(),rects.at(1)->y());
                    tipo=1;
                }
                else if(jugador2->getX1()+5 > colision_player2().getX()){
                    jugador2->setPos(jugador2->getX1()+fuerzaT,jugador2->getY1());
                    jugador2->setX1(jugador2->getX1()+fuerzaT);
                    view->centerOn(rects.at(1)->x(),rects.at(1)->y());
                    tipo=1;
                }
            }
            else{

                if(!jugador2->collidesWithItem(&colision_player2())){
                    jugador2->setPos(jugador2->getX1()+7,jugador2->getY1());
                    jugador2->setX1(jugador2->getX1()+7);
                    view->centerOn(rects.at(1)->x(),rects.at(1)->y());
                    tipo=1;
                }
                else if(jugador2->getX1()-5 < colision_player2().getX()){
    //                qDebug()<<"jugador x: "<<jugador->getX1()<<"  y: "<<jugador->getY1();
    //                qDebug()<<"pared   x: "<<colision_player().getX()<<"  y: "<<colision_player().getY();
                    jugador2->setPos(jugador2->getX1()-7,jugador2->getY1());
                    jugador2->setX1(jugador2->getX1()-7);
                    view->centerOn(rects.at(1)->x(),rects.at(1)->y());
                    tipo=0;
                }
            }

        }

        if(event->key()== 73){     //up
            animacion=1;
            if(nivel1==0){

                for(int i=0;i<lentitud.size();i++){
                    if(jugador2->collidesWithItem(lentitud[i])){
                        rozamiento(1);
                        break;
                    }
                    else {
                        rozamiento(0);
                    }
                }

                //qDebug()<<fuerzaT;

                if(!jugador2->collidesWithItem(&colision_player2())){
                    jugador2->setPos(jugador2->getX1(),jugador2->getY1()-fuerzaT);
                    jugador2->setY1(jugador2->getY1()-fuerzaT);
                    view->centerOn(rects.at(1)->x(),rects.at(1)->y());
                }
                else if(jugador2->getY1()-5 < colision_player2().getY()){
                    jugador2->setPos(jugador2->getX1(),jugador2->getY1()-fuerzaT);
                    jugador2->setY1(jugador2->getY1()-fuerzaT);
                    view->centerOn(rects.at(1)->x(),rects.at(1)->y());
                }
            }
            else{
                if(!jugador2->collidesWithItem(&colision_player2())){
                    jugador2->setPos(jugador2->getX1(),jugador2->getY1()-7);
                    jugador2->setY1(jugador2->getY1()-7);
                    view->centerOn(rects.at(1)->x(),rects.at(1)->y());
                }

                else if(jugador2->getY1()+5 > colision_player2().getY()){
    //                qDebug()<<"jugador x: "<<jugador->getX1()<<"  y: "<<jugador->getY1();
    //                qDebug()<<"pared   x: "<<colision_player().getX()<<"  y: "<<colision_player().getY();
                    jugador2->setPos(jugador2->getX1(),jugador2->getY1()+7);
                    jugador2->setY1(jugador2->getY1()+7);
                    view->centerOn(rects.at(1)->x(),rects.at(1)->y());
                }
            }
        }

        if(event->key()== 75){     //down
            animacion=1;
            if(nivel1==0){

                for(int i=0;i<lentitud.size();i++){
                    if(jugador2->collidesWithItem(lentitud[i])){
                        rozamiento(1);
                        break;
                    }
                    else {
                        rozamiento(0);
                    }
                }

                //qDebug()<<fuerzaT;

                if(!jugador2->collidesWithItem(&colision_player2())){
                    jugador2->setPos(jugador2->getX1(),jugador2->getY1()+fuerzaT);
                    jugador2->setY1(jugador2->getY1()+fuerzaT);
                    view->centerOn(rects.at(1)->x(),rects.at(1)->y());
                }
                else if(jugador2->getY1()+5 > colision_player2().getY()){
                    jugador2->setPos(jugador2->getX1(),jugador2->getY1()+fuerzaT);
                    jugador2->setY1(jugador2->getY1()+fuerzaT);
                    view->centerOn(rects.at(1)->x(),rects.at(1)->y());
                }
            }
            else{

                if(!jugador2->collidesWithItem(&colision_player2())){
                    jugador2->setPos(jugador2->getX1(),jugador2->getY1()+7);
                    jugador2->setY1(jugador2->getY1()+7);
                    view->centerOn(rects.at(1)->x(),rects.at(1)->y());
                }
                else if(jugador2->getY1()-5 < colision_player2().getY()){
    //                qDebug()<<"jugador x: "<<jugador->getX1()<<"  y: "<<jugador->getY1();
    //                qDebug()<<"pared   x: "<<colision_player().getX()<<"  y: "<<colision_player().getY();
                    jugador2->setPos(jugador2->getX1(),jugador2->getY1()-7);
                    jugador2->setY1(jugador2->getY1()-7);
                    view->centerOn(rects.at(1)->x(),rects.at(1)->y());
                }
            }
        }

        //Ataque basico
        if(event->key()== 66){
            if(nivel1==0){
                if(tipo==1){
                    disparo = new ataque_Bas(0,tipo);
                    disparo->setPos(jugador2->getX1()+70,jugador2->getY1()+20);
                }
                if(tipo==0){
                    disparo = new ataque_Bas(0,tipo);
                    disparo->setPos(jugador2->getX1()-20,jugador2->getY1()+20);
                }

                scene->addItem(disparo);
            }
        }

        //Ataque especial (Mov Parabolico)
        if(event->key()==78){
            if(nivel1==0){
               if(tipo==1){
                    ataque_es = new tiropara(1,jugador2->getX1()+50,jugador2->getY1(),30,-45);
                    ataque_es->setPos(jugador2->getX1()+50,jugador2->getY1());
               }
               if(tipo==0){
                   ataque_es = new tiropara(0,jugador2->getX1()-10,jugador2->getY1(),30,-45);
                   ataque_es->setPos(jugador2->getX1()-10,jugador2->getY1());
               }

               scene->addItem(ataque_es);
            }
        }
    }


    //Animacion primer jugador
    if(nivel1==0 && animacion==0){

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


    //Animacion segundo jugador
    if(nivel1==0 && animacion==1){

        if(tipo==0){
            if(imagen2==2){
                imagen2=3;

                jugador2->setPixmap(QPixmap(":/new/prefix1/Imagenes Proyecto final/6 Deceased/MultiPlayer/Multi_iz/Deceased_walk2.png").scaled(60,60));

            }
            else if(imagen2==3){
                imagen2=4;

                jugador2->setPixmap(QPixmap(":/new/prefix1/Imagenes Proyecto final/6 Deceased/MultiPlayer/Multi_iz/Deceased_walk3.png").scaled(60,60));

            }
            else if(imagen2==4){
                imagen2=5;
                jugador2->setPixmap(QPixmap(":/new/prefix1/Imagenes Proyecto final/6 Deceased/MultiPlayer/Multi_iz/Deceased_walk4.png").scaled(60,60));
            }
            else if(imagen2==5){
                imagen2=6;

                jugador2->setPixmap(QPixmap(":/new/prefix1/Imagenes Proyecto final/6 Deceased/MultiPlayer/Multi_iz/Deceased_walk5.png").scaled(60,60));
            }
            else if(imagen2==6){
                imagen2=2;

                jugador2->setPixmap(QPixmap(":/new/prefix1/Imagenes Proyecto final/6 Deceased/MultiPlayer/Multi_iz/Deceased_walk6.png").scaled(60,60));
            }
        }

        if(tipo==1){
            if(imagen==2){
                imagen=3;
                jugador2->setPixmap(QPixmap(":/new/prefix1/Imagenes Proyecto final/6 Deceased/MultiPlayer/Multi_Der/Deceased_walk5Der.png").scaled(60,60));
            }
            else if(imagen==3){
                imagen=4;
                jugador2->setPixmap(QPixmap(":/new/prefix1/Imagenes Proyecto final/6 Deceased/MultiPlayer/Multi_Der/Deceased_walk4Der.png").scaled(60,60));
            }
            else if(imagen==4){
                imagen=5;
                jugador2->setPixmap(QPixmap(":/new/prefix1/Imagenes Proyecto final/6 Deceased/MultiPlayer/Multi_Der/Deceased_walk3Der.png").scaled(60,60));
            }
            else if(imagen==5){
                imagen=6;
                jugador2->setPixmap(QPixmap(":/new/prefix1/Imagenes Proyecto final/6 Deceased/MultiPlayer/Multi_Der/Deceased_walk2Der.png").scaled(60,60));
            }
            else if(imagen==6){
                imagen=2;
                jugador2->setPixmap(QPixmap(":/new/prefix1/Imagenes Proyecto final/6 Deceased/MultiPlayer/Multi_Der/Deceased_walk1Der.png").scaled(60,60));
            }

        }

    }
}

void MainWindow::limpiar()
{
    for (QList<enemi_dis*>::iterator it=mru.begin();it!=mru.end();it++) {
        //scene->removeItem((*it));
        mru.removeOne((*it));
        delete (*it);
    }
    for (QList<obstaculos*>::iterator it=lista_piedra.begin();it!=lista_piedra.end();it++) {
        //scene->removeItem((*it));
        lista_piedra.removeOne((*it));
        delete (*it);
    }
    for (QList<ataque_Bas*>::iterator it=balas.begin();it!=balas.end();it++) {
        //scene->removeItem((*it));
        balas.removeOne((*it));
        delete (*it);
    }
    for (QList<obstaculos*>::iterator it=p_boss.begin();it!=p_boss.end();it++) {
        //scene->removeItem((*it));
        p_boss.removeOne((*it));
        delete (*it);
    }
}

void MainWindow::final()
{
    close();
    niveles(4);
    game->show();
}

void MainWindow::cambio_mapas(int x)
{
    limpiar();
    close();
    niveles(x);
    guardado(x);
    game->show();
}


