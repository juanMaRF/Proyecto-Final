#include "mru.h"
#include "player.h"

mru::mru(int x_, int y_)
{
    x=x_;
    y=y_;
    xi=x_;
    yi=y_;
    setPos(x,y);

    connect(timepo,SIGNAL(timeout()),this,SLOT(move_y()));
    timepo->start(50);
}

QRectF mru::boundingRect() const
{
    return QRectF(-r,-r,r*2,r*2);
}

void mru::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::white);
    painter->drawEllipse(boundingRect());
}

void mru::move_y()
{
    if(yi+300==y){
        delete this;
    }
    y=y+vely*delta;
    if((xi+30==x) || (xi-30==x)){
        velx=velx*-1;
    }
    x=x+velx*delta;
    setPos(x,y);
}
