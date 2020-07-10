#include "player.h"

int player::getX() const
{
    return x;
}

void player::setX(int value)
{
    x = value;
}

int player::getY() const
{
    return y;
}

void player::setY(int value)
{
    y = value;
}

player::player(int x_, int y_, int w_, int h_)
{
    x=x_;
    y=y_;
    w=w_;
    h=h_;
}

QRectF player::boundingRect() const
{
    return QRect(x,y,w,h);
}



void player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/Imagenes Proyecto final/6 Deceased/Deceased.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

void player::keyPressEvent(QKeyEvent *event)
{
    setTransformOriginPoint(15,15);

    if(event->key()==Qt::Key_Left){

    }
}
