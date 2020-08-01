#ifndef MRU_H
#define MRU_H

#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <math.h>
#include <QDebug>

class mru:public QObject,public QGraphicsItem
{
    Q_OBJECT

    int x,y,r=8,xi,yi;
    double velx=30,vely=30,delta=0.1;
    QTimer *timepo=new QTimer;
public:
    mru(int x_, int y_);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);


//    int getX() const;
//    void setX(int value);

//    int getY() const;
//    void setY(int value);

private slots:
    void move_y();
};

#endif // MRU_H
