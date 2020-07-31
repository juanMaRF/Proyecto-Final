#ifndef TIROPARA_H
#define TIROPARA_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <math.h>
#include <QDebug>

class tiropara:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    double pos_inicial;
    double g= -9.8;
    double delta =0.1;
    double posy,posx, ang=50, vel, vel_x=15, vel_y=15;
    int r,con=0,tipo1;
public:
<<<<<<< Updated upstream
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
    tiropara(int tipo,double x, double y, double v, double a);
=======
    tiropara(int tipo,double x, double y, double v, double a,QGraphicsItem * parent=0);
>>>>>>> Stashed changes
    double getPosy() const;
    double getPosx() const;

    void ActualizarVelocidad();
    void setPosy(double value);

    void setPosx(double value);

private slots:
    void ActualizarPosicion();

};

#endif // TIROPARA_H
