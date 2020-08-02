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

int obstaculos::getW() const
{
    return w;
}

void obstaculos::setW(int value)
{
    w = value;
}

int obstaculos::getH() const
{
    return h;
}

void obstaculos::setH(int value)
{
    h = value;
}

obstaculos::obstaculos(int x_, int y_, int w_, int h_, QString img)
{
    x=x_;
    y=y_;
    w=w_;
    h=h_;
    imga=img;
    //setPos(x,y);
    if(img=="piedra1"){
        pixmap.load(":/Imagenes Proyecto final/roca1.gif");
    }else if(img=="valla1"){
        pixmap.load(":/Imagenes Proyecto final/valla1.png");
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
    return QRectF(x,y,w,h);
}

void obstaculos::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(imga=="nada"){
        //setPos(x,y);
        painter->setBrush(Qt::white);
        painter->drawRect(boundingRect());
    }else{
        //setPos(x,y);
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
}
