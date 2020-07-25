#include "basico.h"

int basico::getX() const
{
    return x;
}

void basico::setX(int value)
{
    x = value;
}

int basico::getY() const
{
    return y;
}

void basico::setY(int value)
{
    y = value;
}

float basico::getVel_x() const
{
    return vel_x;
}

void basico::setVel_x(float value)
{
    vel_x = value;
}

float basico::getVel_y() const
{
    return vel_y;
}

void basico::setVel_y(float value)
{
    vel_y = value;
}

int basico::getDireccion() const
{
    return direccion;
}

void basico::setDireccion(int value)
{
    direccion = value;
}

basico::basico()
{

}

basico::basico(int x_, int y_, int w_, int h_, int direc)
{
    x=x_;
    y=y_;
    w=w_;
    h=h_;
    direccion=direc;
}

QRectF basico::boundingRect() const
{
    return QRectF(x,y,w,h);
}

void basico::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    pixmap.load(":/Imagenes Proyecto final/6 Deceased/Ball.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

void basico::movex()
{
    if(direccion==0){
        vel_x=vel_x*-1;
    }else if(direccion==1){
        //vel_x=vel_x*-1;
    }
    x=x+vel_x*delta;
    setPos(x,y);
}

void basico::movey()
{
    if(direccion==2){
        vel_y=vel_y*-1;
    }
    y=y+vel_y*delta;
    setPos(x,y);
}
