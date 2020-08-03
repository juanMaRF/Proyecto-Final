#ifndef MRU_H
#define MRU_H

#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <math.h>
#include <QDebug>

class mru:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
    //propiedades del objeto y del MRU
    int x,y,r=8,xi,yi;
    double velx=30,vely=30,delta=0.1;
    QTimer *timepo=new QTimer;
public:
    mru(int x_, int y_); //constructor

private slots:
    void move_y(); //se encarga del movimiento
};

#endif // MRU_H
