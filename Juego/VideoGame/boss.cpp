#include "boss.h"

//extern MainWindow * game;

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

boss::boss()
{

}

boss::boss(int x_, int y_)
{
    x=x_;
    y=y_;
    xi=x;
    yi=y;

    //    QTimer *tiempo;
//    tiempo=new QTimer;
//    connect(tiempo,SIGNAL(timeout()),this,SLOT(atk_1()));
//    tiempo->start(50);
}

QRectF boss::boundingRect() const
{
    return QRectF(-r,-r,r*2,r*2);
}

void boss::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::cyan);
    painter->drawEllipse(boundingRect());
}

void boss::atk_1()
{
//    int te=1;
//    velx=velx*te;
    y=y+vely*delta;
//    te=te*-1;
    if((xi+50==x) || (xi-50==x)){
        velx=velx*-1;
    }
    x=x+velx*delta;
    setPos(x,y);

}
