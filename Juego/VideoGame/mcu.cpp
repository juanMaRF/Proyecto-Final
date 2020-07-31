#include "mcu.h"

mcu::mcu(int x_, int y_)
{
    x=x_;
    y=y_;

    connect(timepo,SIGNAL(timeout()),this,SLOT(move()));
    timepo->start(100);

    connect(timepo1,SIGNAL(timeout()),this,SLOT(borra()));
    timepo1->start(5000);
}

QRectF mcu::boundingRect() const
{
    return QRectF(-r,-r,r*2,r*2);
}

void mcu::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::white);
    painter->drawEllipse(boundingRect());
}

void mcu::move()
{
    xc=x+(R*cos((Vt/R)*delta));
    yc=y+(R*sin((Vt/R)*delta));
    setPos(xc,yc);
    delta+=0.1;
}

void mcu::borra()
{
    delete this;
}
