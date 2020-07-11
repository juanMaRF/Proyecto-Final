#include "moob.h"

moob::moob(QObject *parent) : QObject(parent)
{

    timer = new QTimer();
    filas = 0;
    columnas = 0;
    pixmap = new QPixmap(":/Imagenes Proyecto final/2 Hyena/Hyena_walk.png");

    //dimensiones de c/U de las imagenes
    ancho = 50;
    alto  = 50;

    timer->start(100);// modifica la velocidad en que itera entre las imagenes

    connect(timer,&QTimer::timeout,this,&moob::Actualizacion);


}

double moob::getY() const
{
    return y;
}

void moob::setY(double value)
{
    y = value;
}

double moob::getX() const
{
    return x;
}

void moob::setX(double value)
{
    x = value;
}

void moob::Actualizacion()
{
    columnas +=50;
    if(columnas >=300)
    {
        columnas =0;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);

}
QRectF moob::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void moob::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columnas,0,ancho,alto);
}

void moob::actualizar_x()
{
    vel_x=15;
    vel_y=0;
    x=x+vel_x*delta;
    y=y+vel_y*delta;
    setPos(x,y);

}

void moob::mover_m(int x_, int y_)
{

}

void moob::actualizar_y()
{
    vel_x=0;
    vel_y=15;
    x=x+vel_x*delta;
    y=y+vel_y*delta;
    setPos(x,y);
}
