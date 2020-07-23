#include "ataque_bas.h"
#include "mainwindow.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QDebug>
#include "enemi_dis.h"

extern MainWindow * game;

ataque_Bas::ataque_Bas(short nivel, short tipo,int x, int y,int w, int h): QObject(), QGraphicsPixmapItem()
{
    nivel1=nivel;
    x1=x;
    y1=y;
    h1=h;
    w1=w;
    ataque=tipo;
    QTimer * timer = new QTimer();

    connect(timer,SIGNAL(timeout()),this, SLOT(move()));

    timer->start(50);
}

QRectF ataque_Bas::boundingRect() const
{
    return QRect(x1,y1,w1,h1);
}

void ataque_Bas::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;

    pixmap.load(":/Imagenes Proyecto final/6 Deceased/Ball.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

void ataque_Bas::move()
{
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


}

int ataque_Bas::getY1() const
{
    return y1;
}

void ataque_Bas::setY1(int value)
{
    y1 = value;
}

int ataque_Bas::getX1() const
{
    return x1;
}

void ataque_Bas::setX1(int value)
{
    x1 = value;
}
