#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <QKeyEvent>
#include "ataque_bas.h"

class player:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
signals:
    void keyCaught(QKeyEvent *e);
public:
    player(int x_, int y_, int w_, int h_);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
    void keyPressEvent(QKeyEvent *event);
    int getX1() const;
    void setX1(int value);

    int getY1() const;
    void setY1(int value);


private:
    short tipo=1;
    short imagen=0;
    int x1,y1,h1,w1;
    ataque_Bas *disparo;
};

#endif // PLAYER_H
