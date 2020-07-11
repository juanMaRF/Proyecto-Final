#include "player.h"
#include <QDebug>

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

    if(tipo==0){

        if(imagen==0){
            imagen=2;

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

    if(tipo==1){

        if(imagen==0){
            imagen=2;

            pixmap.load(":/caminader/Imagenes Proyecto final/6 Deceased/Caminar_Player_Der/Deceased_walk6Der.png");
            painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
        }
        else if(imagen==2){
            imagen=3;
            pixmap.load(":/caminader/Imagenes Proyecto final/6 Deceased/Caminar_Player_Der/Deceased_walk5Der.png");
            painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
        }
        else if(imagen==3){
            imagen=4;
            pixmap.load(":/caminader/Imagenes Proyecto final/6 Deceased/Caminar_Player_Der/Deceased_walk4Der.png");
            painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
        }
        else if(imagen==4){
            imagen=5;
            pixmap.load(":/caminader/Imagenes Proyecto final/6 Deceased/Caminar_Player_Der/Deceased_walk3Der.png");
            painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
        }
        else if(imagen==5){
            imagen=6;
            pixmap.load(":/caminader/Imagenes Proyecto final/6 Deceased/Caminar_Player_Der/Deceased_walk2Der.png");
            painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
        }
        else if(imagen==6){
            imagen=0;
            pixmap.load(":/caminader/Imagenes Proyecto final/6 Deceased/Caminar_Player_Der/Deceased_walk1Der.png");
            painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
        }

    }
}

void player::keyPressEvent(QKeyEvent *event)
{

    if(event->key()==Qt::Key_Left){

        setPos(x()-5,y());
        tipo=0;
        qDebug()<<"IZQUIERDA: "<<x()<<"  "<<y();
    }
    else if (event->key() == Qt::Key_Right){

        setPos(x()+5,y());
        tipo=1;
        qDebug()<<"DERECHA: "<<x()<<"  "<<y();
    }
    else if(event->key()== Qt::Key_Up){
        setPos(x(),y()-5);
        qDebug()<<"ARRIBA: "<<x()<<"  "<<y();

    }
    else if(event->key()== Qt::Key_Down){
        setPos(x(),y()+5);
        qDebug()<<"ABAJO: "<<x()<<"  "<<y();

    }
    else if(event->key()== Qt::Key_Space){
        if(tipo==1){
            disparo = new ataque_Bas(tipo,x()+50,y()+20,10,10);
        }
        if(tipo==0){
            disparo = new ataque_Bas(tipo,x()-10,y()+20,10,10);
        }

        disparo->setPos(x1,y1);
        scene()->addItem(disparo);
    }
}
