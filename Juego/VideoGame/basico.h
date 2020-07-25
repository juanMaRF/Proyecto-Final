#ifndef BASICO_H
#define BASICO_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <math.h>

class basico: public QGraphicsItem,public QObject
{
    int x;
    int y;
    int w;
    int h;
    int direccion;
    float vel_x=25,vel_y=25,delta=0.1;
    QPixmap pixmap;
    QTimer *timer;
public:
    basico();
    basico(int x_, int y_, int w_, int h_,int direc);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
    void movex();
    void movey();
    int getX() const;
    void setX(int value);
    int getY() const;
    void setY(int value);
    float getVel_x() const;
    void setVel_x(float value);
    float getVel_y() const;
    void setVel_y(float value);
    int getDireccion() const;
    void setDireccion(int value);
};
#endif // BASICO_H
