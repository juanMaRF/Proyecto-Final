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
    //propiedades del objetos y del el tipo de movimiento, y sus timers
    int x,y,r=8;
    double W=30,R=80,Vt=100,xc,yc,delta=0.1;
    QTimer *timepo=new QTimer, *timepo1=new QTimer;
public:
    mcu();
    mcu(int x_,int y_); //el cnostructor
private slots:
    void move();    //se encarga de mover el objeto
    void borra();   //se encarga de borrar el objeto despues de un tiempo para evitar "sobrepoblacion"
};

#endif // MCU_H
