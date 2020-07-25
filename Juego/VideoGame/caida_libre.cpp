#include "caida_libre.h"
#include "mainwindow.h"
#include <QDebug>
#include <QTimer>

extern MainWindow * game;

QRectF caida_libre::boundingRect() const
{
    return QRect(PosX,PosY,w,h);
}

void caida_libre::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;

    pixmap.load(":/Imagenes Proyecto final/6 Deceased/Ball.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

caida_libre::caida_libre(int x)
{
    PosX= x;
    PosY=70;
    Vel=0;
    w=10;
    h=10;
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this, SLOT(move()));
    timer->start(50);
}

void caida_libre::actu_vel()
{
   Vel=Vel-g*delta;
}

void caida_libre::move()
{
    if(con==0){
        pos_inicial=PosY;
        con=2;
    }
    PosY=PosY-(0.5*Vel*delta);
    setPos(PosX,PosY);
    actu_vel();

}
