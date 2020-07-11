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

//void obstaculos::imagen(QString img)
//{
//    pixmap.load(img);
//}

obstaculos::obstaculos(int x_, int y_, int w_, int h_, QString img)
{
    x=x_;
    y=y_;
    w=w_;
    h=h_;
    if(img=="piedra1"){
        pixmap.load(":/Imagenes Proyecto final/roca1.gif");
    }else if(img=="valla1"){
        pixmap.load(":/Imagenes Proyecto final/valla1.gif");
    }else if (img=="piedra2"){
        pixmap.load(":/Imagenes Proyecto final/roca2.gif");
    }else if(img=="hongo1"){
        pixmap.load(":/Imagenes Proyecto final/hongo1.gif");
    }else if(img=="hojas1"){
        pixmap.load(":/Imagenes Proyecto final/hojas1.gif");
    }
}

QRectF obstaculos::boundingRect() const
{
    return QRect(x,y,w,h);
}

void obstaculos::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}
