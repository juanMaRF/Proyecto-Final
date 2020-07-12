#ifndef ENEMI_DIS_H
#define ENEMI_DIS_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <QDebug>
#include "ataque_bas.h"

class enemi_dis:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    enemi_dis(int tipo, int x_, int y_, int w_, int h_);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);

    int getX1() const;
    void setX1(int value);

    int getY1() const;
    void setY1(int value);

private slots:
    void move();

private:
    ataque_Bas *shot;
    int pos_inicial;
    QTimer *timer;
    short imagen=0,con=0,col=0;
    int x1,y1,h1,w1,tipo1;
};

#endif // ENEMI_DIS_H
