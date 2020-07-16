#include "corazon.h"

corazon::corazon()
{

}

corazon::corazon(int x_, int y_)
{
    x=x_;
    y=y_;
    setPos(x,y);
}

QRectF corazon::boundingRect() const
{
    return QRectF(-r,-r,r*2,r*2);
}

void corazon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/Imagenes Proyecto final/corazon.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

void corazon::move()
{
    x=x+velx*delta;
    y=y+vely*delta;
    setPos(x,y);
}
