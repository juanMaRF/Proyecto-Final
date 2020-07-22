#ifndef CAIDA_LIBRE_H
#define CAIDA_LIBRE_H
#include <QGraphicsPixmapItem>

class caida_libre:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);

    caida_libre(int x);
    void actu_vel();

private slots:
    void move();
private:
    short con=0;
    double pos_inicial;
    double g= 9.8;
    double PosY,PosX, h, w,Vel,delta=0.5;
};

#endif // CAIDA_LIBRE_H
