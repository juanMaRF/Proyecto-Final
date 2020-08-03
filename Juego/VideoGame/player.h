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
#include "tiropara.h"
#include "slime.h"

class player:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    player(QGraphicsItem * parent=0);
    player(short nivel,int x_, int y_, int w_, int h_,QGraphicsItem * parent=0);
    int getX1() const;
    void setX1(int value);

    int getY1() const;
    void setY1(int value);

    void rozamiento(short n);
    //QList<slime *> lentitud;
    //void slime1();


    int getW1() const;
    void setW1(int value);

    int getH1() const;
    void setH1(int value);

    int vida=20;

private:
    tiropara *ataque_es;
    ataque_Bas *disparo;
    short tipo=1, nivel1;
    short imagen=0;
    int x1,y1,h1,w1;
};

#endif // PLAYER_H
