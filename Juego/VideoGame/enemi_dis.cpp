#include "enemi_dis.h"

enemi_dis::enemi_dis(int nivel, int tipo,int x, int y, int w, int h)
{
    timer = new QTimer(this);
    tipo1=tipo;
    nivel1=nivel;
    x1=x;
    y1=y;
    w1=w;
    h1=h;

    timer->start(60);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

}

QRectF enemi_dis::boundingRect() const
{
    return QRect(x1,y1,w1,h1);
}

void enemi_dis::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    if(tipo1==1){
        pixmap.load(":/enemy_dis_der/Imagenes Proyecto final/3 Scorpio/Enemy_dis_der/Scorpio_walk1_der.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
    if(tipo1==0){
        pixmap.load(":/enemy_dis/Imagenes Proyecto final/3 Scorpio/Enemy_dis_izq/Scorpio_walk1.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }

    /**
    if(imagen==0){
        pixmap.load(":/enemy_dis/Imagenes Proyecto final/3 Scorpio/Enemy_dis_izq/Scorpio_walk4.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
        imagen=1;
    }
    if(imagen==1){
        pixmap.load(":/enemy_dis/Imagenes Proyecto final/3 Scorpio/Enemy_dis_izq/Scorpio_walk3.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
        imagen=2;
    }
    if(imagen==2){
        pixmap.load(":/enemy_dis/Imagenes Proyecto final/3 Scorpio/Enemy_dis_izq/Scorpio_walk2.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
        imagen=3;
    }
    if(imagen==3){
        pixmap.load(":/enemy_dis/Imagenes Proyecto final/3 Scorpio/Enemy_dis_izq/Scorpio_walk1.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
        imagen=0;
    }
    **/
}

void enemi_dis::move()
{
    if(con==0){
        pos_inicial=this->getY1();
        con=1;
    }

    if(nivel1==0){

        if(this->getY1()<pos_inicial+40 && col==0){
            this->setY1(this->getY1()+2);
            this->setPos(x1,this->getY1());
            if(this->getY1()==pos_inicial+40 or this->getY1()==pos_inicial+20){

            if(tipo1==0){
                shot=new ataque_Bas(0,x1,y1,10,10);
                shot->setPos(x1,y1);
                scene()->addItem(shot);
            }
            if(tipo1==1){
                shot= new ataque_Bas(1,x1,y1,10,10);
                shot->setPos(x1,y1);
                scene()->addItem(shot);
            }
            if(this->getY1()==pos_inicial+40){
               col=1;
            }

            }
        }
        if(this->getY1()>pos_inicial && col==1){
            this->setY1(this->getY1()-2);
            this->setPos(x1,this->getY1());
            if(this->getY1()==pos_inicial or this->getY1()==pos_inicial+20){

                if(tipo1==0){
                    shot=new ataque_Bas(0,x1,y1,10,10);
                    shot->setPos(x1,y1);
                    scene()->addItem(shot);
                }
                if(tipo1==1){
                    shot= new ataque_Bas(1,x1+10,y1,10,10);
                    shot->setPos(x1+10,y1);
                    scene()->addItem(shot);
                }
                if(this->getY1()==pos_inicial){
                   col=0;
                }
            }
        }
    }

}

/**
void enemi_dis::actualizar()
{
    columnas+=46;
    if(columnas>=186){
        columnas = 0;
    }
    this->update(-w1/2,-h1/2,w1,h1);
}
**/


int enemi_dis::getX1() const
{
    return x1;
}

void enemi_dis::setX1(int value)
{
    x1 = value;
}

int enemi_dis::getY1() const
{
    return y1;
}

void enemi_dis::setY1(int value)
{
    y1 = value;
}


