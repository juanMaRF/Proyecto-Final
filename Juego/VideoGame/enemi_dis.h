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
#include "ataque_enemy.h"

class enemi_dis:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    enemi_dis(int nivel, int tipo, int x_, int y_,QGraphicsItem * parent=0);

    int getX1() const;
    void setX1(int value);

    int getY1() const;
    void setY1(int value);


    int getVida() const;
    void setVida(int value);

private slots:
    void move();
private:
    ataque_enemy *SED;
    int pos_inicial;
    QTimer *timer;
    //QTimer *time;
    short imagen=0,con=0,col=0;
    int x1,y1,tipo1,nivel1,vida=30;
};

#endif // ENEMI_DIS_H
