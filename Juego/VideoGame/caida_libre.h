#ifndef CAIDA_LIBRE_H
#define CAIDA_LIBRE_H
#include <QGraphicsPixmapItem>

class caida_libre:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    caida_libre();
    void actu_vel();
private slots:
    void move();
private:
    float PosY,Vel,delta=0.5;
};

#endif // CAIDA_LIBRE_H
