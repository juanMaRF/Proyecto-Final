#include "caida_libre.h"
#include "mainwindow.h"
#include <QDebug>
#include <QTimer>

extern MainWindow * game;


caida_libre::caida_libre(int x, QGraphicsItem * parent): QObject(), QGraphicsPixmapItem()
{
    PosX= x;
    PosY=70;
    Vel=0;
    w=10;
    h=10;

    setPixmap(QPixmap(":/Imagenes Proyecto final/6 Deceased/Ball.png").scaled(w,h));


    connect(timer,SIGNAL(timeout()),this, SLOT(move()));
    timer->start(50);
}

void caida_libre::actu_vel()
{
   Vel=Vel-g*delta;
}

void caida_libre::move()
{
    if(PosY==700){
        scene()->removeItem(this);
        timer->stop();
        delete this;
    }
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; i++){
        if(typeid(*(colliding_items[i])) == typeid (player)){
            game->jugador->vida-=5;
            //scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            //delete colliding_items[i];
            delete this;
        }
    }

    if(con==0){
        pos_inicial=PosY;
        con=2;
    }
    PosY=PosY-(0.5*Vel*delta);
    setPos(PosX,PosY);
    actu_vel();

}
