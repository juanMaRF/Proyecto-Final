#include "mcu.h"
#include "player.h"
#include "mainwindow.h"

extern MainWindow * game;

mcu::mcu(int x_, int y_):QObject(), QGraphicsPixmapItem()
{
    x=x_;
    y=y_;
    setPos(x,y);
    setPixmap(QPixmap(":/Imagenes Proyecto final/6 Deceased/bola.png").scaled(15,15));
    connect(timepo,SIGNAL(timeout()),this,SLOT(move()));
    timepo->start(50);

    connect(timepo1,SIGNAL(timeout()),this,SLOT(borra()));
    timepo1->start(5000);
}

void mcu::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for(int i=0,n=colliding_items.size();i<n;i++){
        if(typeid (*colliding_items[i]) == typeid (player)){
            game->jugador->vida-=5;
            //qDebug()<<game->jugador->vida;
            scene()->removeItem(this);
            delete this;
            colliding_items.clear();
            break;
        }
    }

    xc=x+(R*cos((Vt/R)*delta));
    yc=y+(R*sin((Vt/R)*delta));
    setPos(xc,yc);
    delta+=0.1;
}

void mcu::borra()
{
    delete this;
}
