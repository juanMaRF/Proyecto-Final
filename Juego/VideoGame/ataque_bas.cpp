#include "ataque_bas.h"
#include "mainwindow.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QDebug>
#include "enemi_dis.h"

extern MainWindow * game;

ataque_Bas::ataque_Bas(short nivel, short tipo,QGraphicsItem * parent): QObject(), QGraphicsPixmapItem()
{
    nivel1=nivel; //En que nivel se necesita el ataque
    ataque=tipo; //direccion del Ataque

    setPixmap(QPixmap(":/Imagenes Proyecto final/6 Deceased/Ball.png").scaled(10,10)); //Imagen del Ataque

    QTimer * timer = new QTimer();

    connect(timer,SIGNAL(timeout()),this, SLOT(move()));

    timer->start(50);
}

void ataque_Bas::move()
{
    //Almacenamos las colisiones en una QList
    QList<QGraphicsItem *> colliding_items = collidingItems();

    //Comprobamos si las colisiones son contra enemigos u obstaculos
    for(int i = 0, n = colliding_items.size(); i < n; i++){
        if(typeid(*(colliding_items[i])) == typeid (enemi_dis) or typeid(*(colliding_items[i])) == typeid (player) or typeid(*(colliding_items[i])) == typeid(moob) or typeid(*(colliding_items[i])) == typeid(obstaculos)){

            if(this->isVisible()){
                //Si colisiona removemos el ataque
                scene()->removeItem(this);
                delete this;
                colliding_items.clear();
                break;
            }

        }
    }

    if(nivel1==0){
        if(con==1){
            //Guardamos la posicion inicial
            pos_inicial=pos().x();
            con=2;
        }

        if(ataque == 0){
            //Damos una posicion segun la direccion del ataque
            setPos(x()-10,y());
        }
        if(ataque == 1){
            //Damos una posicion segun la direccion del ataque
            setPos(x()+10,y());
        }

        if(pos_inicial+400<=pos().x() or pos_inicial-400>=pos().x()){
            //Rango de ataque, si lo sobrepasa se elimina la bala
            scene()->removeItem(this);
            delete this;
        }
    }
    if(nivel1==1){
        if(ataque == 0){
            //movimiento de la bala derecha a izquierda
            setPos(x()-30,y());
        }
        if(ataque == 1){
            //movimiento de la bala izquierda a derecha
            setPos(x()+30,y());
        }
        if(ataque == 2){
            //movimiento de la bala abajo a arriba
            setPos(x(),y()-30);
        }
    }
}
