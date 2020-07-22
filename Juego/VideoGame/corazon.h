#ifndef CORAZON_H
#define CORAZON_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class corazon:public QObject,public QGraphicsItem
{
    int vida,x,y,velx,vely,r=25;
    double delta=0.1;
public:
    corazon();
    corazon(int x_,int y_);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
    void move();
};

#endif // CORAZON_H
