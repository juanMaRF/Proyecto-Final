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
    nivel1=nivel;
    ataque=tipo;

    setPixmap(QPixmap(":/Imagenes Proyecto final/6 Deceased/Ball.png").scaled(10,10));

    QTimer * timer = new QTimer();

    connect(timer,SIGNAL(timeout()),this, SLOT(move()));

    timer->start(50);
}

void ataque_Bas::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for(int i = 0, n = colliding_items.size(); i < n; i++){
        if(typeid(*(colliding_items[i])) == typeid (enemi_dis) or typeid(*(colliding_items[i])) == typeid (player) or typeid(*(colliding_items[i])) == typeid(moob) or typeid(*(colliding_items[i])) == typeid(obstaculos)){

            //scene()->removeItem(colliding_items[i]);
            if(this->isVisible()){
                scene()->removeItem(this);
                //delete colliding_items[i];
                delete this;
                colliding_items.clear();
                break;
            }

        }
    }

    if(nivel1==0){
        if(con==1){
            pos_inicial=pos().x();
            con=2;
        }

        if(ataque == 0){
            setPos(x()-10,y());
        }
        if(ataque == 1){
            setPos(x()+10,y());
        }

        if(pos_inicial+400<=pos().x() or pos_inicial-400>=pos().x()){
            scene()->removeItem(this);
            delete this;
        }
    }
    if(nivel1==1){
        if(ataque == 0){
            setPos(x()-30,y());
        }
        if(ataque == 1){
            setPos(x()+30,y());
        }
        if(ataque == 2){
            setPos(x(),y()-30);
        }
    }

//    if(pos_inicial+1000000<=pos().x() || pos_inicial-1000000>=pos().x() || pos_inicial-100000>=pos().y()){
//        scene()->removeItem(this);
//        delete this;
//    }

}
