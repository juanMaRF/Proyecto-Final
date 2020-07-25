#include "muneco.h"

int muneco::getX() const
{
    return x;
}

void muneco::setX(int value)
{
    x = value;
}

int muneco::getY() const
{
    return y;
}

void muneco::setY(int value)
{
    y = value;
}

void muneco::Actualizacion()
{
    columnas +=70;
    if(columnas >=420)
    {
        columnas =0;
    }
    this->update(-w/2,-h/2,w,h);
}

muneco::muneco()
{

}

muneco::muneco(int x_, int y_, int w_, int h_)
{
    x=x_;
    y=y_;
    w=w_;
    h=h_;
    setPos(x,y);
    pixmap.load(":/Imagenes Proyecto final/6 Deceased/Deceased_walk.png");
    timer=new QTimer();
    timer->start(80);// modifica la velocidad en que itera entre las imagenes

    connect(timer,&QTimer::timeout,this,&muneco::Actualizacion);
}

void muneco::MoveUp()
{
    if(vel_y>0){
        vel_y=vel_y*-1;
    }
    y=y+vel_y*delta;
    setPos(x,y);
}

void muneco::MoveDown()
{
    if(vel_y<0){
        vel_y=vel_y*-1;
    }
    y=y+vel_y*delta;
    setPos(x,y);
}

void muneco::MoveLeft()
{
    if(vel_x>0){
        vel_x=vel_x*-1;
    }
    x=x+vel_x*delta;
    setPos(x,y);
}

void muneco::MoveRight()
{
    if(vel_x<0){
        vel_x=vel_x*-1;
    }
    x=x+vel_x*delta;
    setPos(x,y);
}

QRectF muneco::boundingRect() const
{
    return QRectF(-w/2,-h/2,w,h);
}

void muneco::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-h/2,-h/2,pixmap,columnas,0,w,h);
}
