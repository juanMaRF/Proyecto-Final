#include "obstaculos.h"

int obstaculos::getX() const
{
    return x;
}

void obstaculos::setX(int value)
{
    x = value;
}

int obstaculos::getY() const
{
    return y;
}

void obstaculos::setY(int value)
{
    y = value;
}

obstaculos::obstaculos()
{

}

obstaculos::obstaculos(int x_, int y_, int w_, int h_)
{
    x=x_;
    y=y_;
    w=w_;
    h=h_;
}

QRectF obstaculos::boundingRect() const
{
    return QRect(x,y,w,h);
}

void obstaculos::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/Imagenes Proyecto final/roca1.gif");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}
