#include "moob.h"


double moob::getX() const
{
    return x;
}

void moob::setX(double value)
{
    x = value;
}

double moob::getY() const
{
    return y;
}

void moob::setY(double value)
{
    y = value;
}

moob::moob(int x_, int y_, int w_, int h_)
{
    x=x_;
    y=y_;
    w=w_;
    h=h_;
}

QRectF moob::boundingRect() const
{
    return QRectF(x,y,w,h);
}

void moob::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/Imagenes Proyecto final/2 Hyena/Hyena.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

void moob::actualizar_x(int posx_per)
{
    if(posx_per>x){
    vel_x=12;
    vel_y=0;
    x=x+vel_x*delta;
    y=y+vel_y*delta;
    setPos(x,y);
    }
    else if(posx_per<x){
        vel_x=-12;
        vel_y=0;
        x=x+vel_x*delta;
        y=y+vel_y*delta;
        setPos(x,y);
    }


}

void moob::actualizar_y(int posy_per)
{
    if(posy_per>y){
    vel_x=0;
    vel_y=12;
    x=x+vel_x*delta;
    y=y+vel_y*delta;
    setPos(x,y);
    }
    else if(posy_per>y){
        vel_x=0;
        vel_y=-12;
        x=x+vel_x*delta;
        y=y+vel_y*delta;
        setPos(x,y);
    }
}
