#ifndef MCU_H
#define MCU_H

#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <math.h>

class mcu:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
    int x,y,r=8;
    double W=30,R=80,Vt=100,xc,yc,delta=0.1;
    QTimer *timepo=new QTimer, *timepo1=new QTimer;
public:
    mcu();
    mcu(int x_,int y_);
//    QRectF boundingRect() const;
//    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
private slots:
    void move();
    void borra();
};

#endif // MCU_H
