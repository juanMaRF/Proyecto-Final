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

    QTimer *timepo=new QTimer,*timepo1=new QTimer;          //temporizadores para los ataques
    int vida=20,tipo,ayuda=0,ayuda1,alea,alea1,x,y,w,h;     //propiedades
    mru *caida;                                             //ataque del 1 tipo
    mcu *b;                                                 //ataque del 2 tipo
public:
    boss_jm(int x_,int y_,int w_, int h_);                  //constructor
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);

private slots:
    void ataques();                                         //funciones conectadas a los temporizadores
    void tipoA();
};

#endif // BOSS_JM_H
