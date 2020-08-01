#include "mru.h"
#include "player.h"
#include "mainwindow.h"

extern MainWindow * game;

mru::mru(int x_, int y_):QObject(), QGraphicsPixmapItem()
{
    x=x_;
    y=y_;
    xi=x_;
    yi=y_;
    setPos(x,y);

    setPixmap(QPixmap(":/Imagenes Proyecto final/6 Deceased/bola.png").scaled(15,15));

    connect(timepo,SIGNAL(timeout()),this,SLOT(move_y()));
    timepo->start(50);
}

//QRectF mru::boundingRect() const
//{
//    return QRectF(-r,-r,r*2,r*2);
//}

//void mru::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
//{
//    painter->setBrush(Qt::white);
//    painter->drawEllipse(boundingRect());
//}

void mru::move_y()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i=0,n=colliding_items.size();i<n;i++){
        if(typeid (*colliding_items[i]) == typeid (player)){
            game->jugador->vida-=5;
            qDebug()<<game->jugador->vida;
            scene()->removeItem(this);
            delete this;
            colliding_items.clear();
            break;
        }
    }

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
