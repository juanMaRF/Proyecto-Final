#ifndef BOSS_H
#define BOSS_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <math.h>



class boss:public QObject,public QGraphicsItem
{
    float pi=3.14159;
    int vida=100,x,y,velx=100,vely=30,r=8;
    int xi,yi;
    double W=5,R=5,xc,yc,S,Vc,Ac,Rx,Ry;
    double delta=0.1;
public:


    boss();
    boss(int x_,int y_);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
    void atk_1();
    void atk_2();
    void atk_3();

    int getX() const;
    void setX(int value);
    int getY() const;
    void setY(int value);

    int getVelx() const;
    void setVelx(int value);

    int getXi() const;
    void setXi(int value);

    int getYi() const;
    void setYi(int value);

private slots:

};

#endif // BOSS_H
