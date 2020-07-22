#ifndef TIROPARA_H
#define TIROPARA_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <math.h>

class tiropara: public QGraphicsItem,public QObject
{
    double g= 9.8;
    double delta =0.1;
    double posy,posx, ang, vel, vel_x, vel_y;
    int r;
public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
    tiropara();
    tiropara(double x, double y, double v, double a);
    double getPosy() const;
    double getPosx() const;
    void ActualizarPosicion();
    void ActualizarVelocidad();

};

#endif // TIROPARA_H
