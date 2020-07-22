#include "tiropara.h"

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
    posx=posx+vel_x*delta;
    posy=posy+vel_y*delta-(0.5*g*delta*delta);
    setPos(posx,-posy);
    setPos(posx,-posy);

}

void tiropara::ActualizarVelocidad()
{
    vel_x=vel*cos(ang);
    vel_y=vel*sin(ang)-g*delta;
    ang=atan2(vel_y,vel_x);
    vel= sqrt(vel_x*vel_x+ vel_y*vel_y);
    setPos(posx,-posy);
}

QRectF tiropara::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);

}

void tiropara::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::green);
    painter->drawEllipse(boundingRect());
}

tiropara::tiropara()
{

}

tiropara::tiropara(double x, double y, double v, double a)
{
    posx=x;
    posy=y;
    vel=v;
    ang=a;
    r=10;
    setPos(posx,-posy);
}
