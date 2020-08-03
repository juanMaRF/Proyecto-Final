#ifndef BOSS_JM_H
#define BOSS_JM_H

#include <time.h>
#include <cstdlib>
#include <vector>
#include <stdlib.h>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <QDebug>
#include "mru.h"
#include "mcu.h"

class boss_jm:public QObject,public QGraphicsItem
{
    Q_OBJECT

    QTimer *timepo=new QTimer,*timepo1=new QTimer;
    int vida=20,tipo,ayuda=0,ayuda1,alea,alea1,x,y,w,h;
    mru *caida,*caida1,*caida2,*caida3,*caida4,*caida5,*caida6,*caida7,*caida8,*caida9,*caida10,*caida11,*caida12,*caida13;
    mcu *b;
    //mcu *b1,*b2,*b3,*b4,*b5,*b6,*b7,*b8,*b9,*b10,*b11,*b12,*b13,*b14,*b15,*b16,*b17;
public:
    boss_jm(int x_,int y_,int w_, int h_);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);

private slots:
    void ataques();
    void tipoA();
};

#endif // BOSS_JM_H
