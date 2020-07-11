#include "moob.h"

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

moob::moob(int x_, int y_, int w_, int h_, QString img)
{
    x=x_;xi=x_;
    y=y_;yi=y_;
    w=w_;
    h=h_;
    if(img=="perro"){
        pixmap.load(":/Imagenes Proyecto final/4 Vulture/Vulture_walk.png");
        Ider=":/Imagenes Proyecto final/4 Vulture/Vulture_walk_der.png";
        Iizq=":/Imagenes Proyecto final/4 Vulture/Vulture_walk.png";
        //Ies=":/Imagenes Proyecto final/2 Hyena/Hyena_idle.png";
    }
    timer=new QTimer();
    timer->start(95);// modifica la velocidad en que itera entre las imagenes

    connect(timer,&QTimer::timeout,this,&moob::Actualizacion);
}

QRectF moob::boundingRect() const
{
    return QRectF(-w/2,-h/2,w*2,h*2);
}

void moob::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-h/2,-h/2,pixmap,columnas,0,w,h);
}

void moob::move()
{
    x=x+vel_x*delta;
    y=y+vel_y*delta;
    setPos(x,y);

    if(vel_x<0){
        pixmap.load(Iizq);
    }else{
        pixmap.load(Ider);
    }
}

void moob::Actualizacion()
{
    columnas +=50;
    if(columnas >=200)
    {
        columnas =0;
    }
    this->update(-w/2,-h/2,w,h);
}


