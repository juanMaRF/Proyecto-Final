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

moob::moob(int x_, int y_, int w_, int h_, QString img)
{
    x=x_;
    y=y_;
    w=w_;
    h=h_;
    if(img=="perro"){
        pixmap.load(":/Imagenes Proyecto final/2 Hyena/Hyena_idle.png");
        Ider=":/Imagenes Proyecto final/2 Hyena/Hyena_walk_right.png";
        Iizq=":/Imagenes Proyecto final/2 Hyena/Hyena_walk.png";
        Ies=":/Imagenes Proyecto final/2 Hyena/Hyena_idle.png";
    }
    timer=new QTimer();
    timer->start(95);// modifica la velocidad en que itera entre las imagenes

    connect(timer,&QTimer::timeout,this,&moob::Actualizacion);
}

QRectF moob::boundingRect() const
{
    return QRectF(-w/2,-h/2,w,h);
}

void moob::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-h/2,-h/2,pixmap,columnas,0,w,h);
}

void moob::move_x()
{
    vel_x=1;
    vel_tempx=2;
    if(vel_tempx<vel_x){
        vel_x=-16;
    x=x+vel_x*delta;
    y=y+vel_y*delta;
    setPos(x,y);
    pixmap.load(Iizq);
    }else if(vel_tempx>vel_x){
        vel_x=16;
    x=x+vel_x*delta;
    y=y+vel_y*delta;
    setPos(x,y);
    pixmap.load(Ider);
    }else{
        pixmap.load(Ies);
    }
}

void moob::move_y()
{
    vel_x=0;
    vel_y=16;
    x=x+vel_x*delta;
    y=y+vel_y*delta;
    setPos(x,y);
}

void moob::Actualizacion()
{
    columnas +=50;
    if(columnas >=300)
    {
        columnas =0;
    }
    this->update(-w/2,-h/2,w,h);
}


