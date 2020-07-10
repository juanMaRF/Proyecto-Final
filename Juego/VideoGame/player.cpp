#include "player.h"

int player::getX1() const
{
    return x1;
}

void player::setX1(int value)
{
    x1 = value;
}

int player::getY1() const
{
    return y1;
}

void player::setY1(int value)
{
    y1 = value;
}

player::player(int x_, int y_, int w_, int h_)
{
    x1=x_;
    y1=y_;
    w1=w_;
    h1=h_;
}

QRectF player::boundingRect() const
{
    return QRect(x1,y1,w1,h1);
}



void player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;



    if(imagen==0){
        imagen=2;

        //pixmap.load(":/n/Imagenes Proyecto final/6 Deceased/Caminar_Player/Deceased_walk6.png");
        pixmap.transformed(QTransform().scale(-1,-1)).load(":/n/Imagenes Proyecto final/6 Deceased/Caminar_Player/Deceased_walk6.png");
        pixmap.load(":/n/Imagenes Proyecto final/6 Deceased/Caminar_Player/Deceased_walk6.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
    else if(imagen==2){
        imagen=3;
        pixmap.load(":/n/Imagenes Proyecto final/6 Deceased/Caminar_Player/Deceased_walk5.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
    else if(imagen==3){
        imagen=4;
        pixmap.load(":/n/Imagenes Proyecto final/6 Deceased/Caminar_Player/Deceased_walk4.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
    else if(imagen==4){
        imagen=5;
        pixmap.load(":/n/Imagenes Proyecto final/6 Deceased/Caminar_Player/Deceased_walk3.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
    else if(imagen==5){
        imagen=6;
        pixmap.load(":/n/Imagenes Proyecto final/6 Deceased/Caminar_Player/Deceased_walk2.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
    else if(imagen==6){
        imagen=0;
        pixmap.load(":/n/Imagenes Proyecto final/6 Deceased/Caminar_Player/Deceased_walk.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
}

void player::keyPressEvent(QKeyEvent *event)
{

    if(event->key()==Qt::Key_Left){
        setPos(x()-5,y());
        tipo=0;
    }
    else if (event->key() == Qt::Key_Right){
        setPos(x()+5,y());
        tipo=1;
    }
    else if(event->key()== Qt::Key_Up){
        setPos(x(),y()-5);
        tipo=2;
    }
    else if(event->key()== Qt::Key_Down){
        setPos(x(),y()+5);
        tipo=3;
    }
    else if(event->key()== Qt::Key_Space){
        disparo = new ataque_Bas(tipo);
        disparo->setPos(x(),y());
        scene()->addItem(disparo);
    }
}
