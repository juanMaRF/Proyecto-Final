#include "tiropara.h"
#include "mainwindow.h"

extern MainWindow * game;

tiropara::tiropara(double x, double y, double v, double a)
{
    posx=x;
    posy=y;
    vel=v;
    ang=a;
    r=10;
    QTimer * timer = new QTimer();

    connect(timer,SIGNAL(timeout()),this, SLOT(ActualizarPosicion()));

    timer->start(50);
}

double tiropara::getPosy() const
{
    return posy;
}

double tiropara::getPosx() const
{
    return posx;
}

void tiropara::ActualizarPosicion()
{
    //qDebug()<<"ANTES: "<<posx<<"  "<<posy;
    ActualizarVelocidad();
    posx=posx+vel_x*delta;
    posy=posy+vel_y*delta-(0.5*g*delta*delta);
    //qDebug()<<"DESPUES: "<<posx<<"  "<<posy;
    setPos(posx,posy);

    /**
    vel_x=0;
    vel_y=2;
    posx=posx+vel_x*delta;
    posy=posy+vel_y*delta;
    setPos(posx,-posy);
    **/

}

void tiropara::ActualizarVelocidad()
{
    vel_x=vel*cos(ang);
    vel_y=vel*sin(ang)-g*delta;
    ang=atan2(vel_y,vel_x);
    vel= sqrt((vel_x*vel_x) + (vel_y*vel_y));

    /**
    vel_x=2;
    vel_y=0;
    posx=posx+vel_x*delta;
    posy=posy+vel_y*delta;
    setPos(posx,-posy);
    **/
}

QRectF tiropara::boundingRect() const
{
    return QRectF(posx,posy,2*r,2*r);

}

void tiropara::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;

    pixmap.load(":/n/Imagenes Proyecto final/6 Deceased/Ball.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}



