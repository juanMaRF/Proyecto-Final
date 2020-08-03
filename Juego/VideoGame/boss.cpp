#include "boss.h"

int boss::getX() const
{
    return x;
}

void boss::setX(int value)
{
    x = value;
}

int boss::getY() const
{
    return y;
}

void boss::setY(int value)
{
    y = value;
}

int boss::getVelx() const
{
    return velx;
}

void boss::setVelx(int value)
{
    velx = value;
}

int boss::getXi() const
{
    return xi;
}

void boss::setXi(int value)
{
    xi = value;
}

int boss::getYi() const
{
    return yi;
}

void boss::setYi(int value)
{
    yi = value;
}

boss::boss()
{

}

boss::boss(int x_, int y_)
{
    x=x_;
    y=y_;
    xi=x;
    yi=y;
}

QRectF boss::boundingRect() const
{
    return QRectF(-r,-r,r*2,r*2);
}

void boss::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::white);
    painter->drawEllipse(boundingRect());
}

void boss::atk_1()
{
    y=y+vely*delta;
    if((xi+30==x) || (xi-30==x)){
        velx=velx*-1;
    }
    x=x+velx*delta;
    setPos(x,y);
}

void boss::atk_2()
{
    xc=x+(R*cos((Vt/R)*delta));
    yc=y+(R*sin((Vt/R)*delta));
    setPos(xc,yc);
    delta+=0.1;
}
