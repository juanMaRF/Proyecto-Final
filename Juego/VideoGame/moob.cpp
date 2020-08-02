#include "moob.h"
#include "mainwindow.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QDebug>

extern MainWindow * game;

float moob::getVel_tempx() const
{
    return vel_tempx;
}

void moob::setVel_tempx(float value)
{
    vel_tempx = value;
}

float moob::getVel_tempy() const
{
    return vel_tempy;
}

void moob::setVel_tempy(float value)
{
    vel_tempy = value;
}

float moob::getVel_x() const
{
    return vel_x;
}

void moob::setVel_x(float value)
{
    vel_x = value;
}

float moob::getVel_y() const
{
    return vel_y;
}

void moob::setVel_y(float value)
{
    vel_y = value;
}

int moob::getVida() const
{
    return vida;
}

void moob::setVida(int value)
{
    vida = value;
}

int moob::getX() const
{
    return x;
}

void moob::setX(int value)
{
    x = value;
}

int moob::getY() const
{
    return y;
}

void moob::setY(int value)
{
    y = value;
}

moob::moob(int x_, int y_, int w_, int h_, QString img)
{
    x=x_;xi=x_;
    y=y_;yi=y_;
    w=w_;
    h=h_;
    if(img=="perro"){
        pixmap.load(":/Imagenes Proyecto final/4 Vulture/Vulture_walk.png");
    }else if(img=="sans"){
        pixmap.load(":/Imagenes Proyecto final/sans.png");
    }
    timer=new QTimer();
    timer->start(80);// modifica la velocidad en que itera entre las imagenes

    //connect(timer,&QTimer::timeout,this,&moob::Actualizacion);
    connect(timer,SIGNAL(timeout()),this,SLOT(Actualizacion()));
}


QRectF moob::boundingRect() const
{
    return QRectF(-w/2,-h/2,w,h);
}

void moob::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-h/2,-h/2,pixmap,columnas,0,w,h);
}


void moob::move()
{
    this->setX(this->getX()+vel_x*delta);
    y=y+vel_y*delta;
    this->setPos(this->getX(),y);

    if(vel_x<0){
        pixmap.load(Iizq);
    }else{
        pixmap.load(Ider);
    }
}

void moob::Actualizacion()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; i++){
        if(typeid (*colliding_items[i]) == typeid (ataque_Bas)){
            this->setVida(this->getVida()-5);
            qDebug()<<"Pajaro: "<<this->getVida();

            if(this->getVida()==0){
                game->puntaje->increase();
                //scene()->removeItem(colliding_items[i]);
                //scene()->removeItem(this);
                this->setX(100000);
                this->setPos(getX(),y);
                //delete colliding_items[i];
                //delete this;
            }
        }
    }

    columnas +=50;
    if(columnas >=200)
    {
        columnas =0;
    }
    this->update(-w/2,-h/2,w,h);
}


