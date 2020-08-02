#ifndef MOOB_H
#define MOOB_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <math.h>

class moob: public QObject,public QGraphicsItem
{
   Q_OBJECT

public:
    moob(int x_, int y_, int w_, int h_,QString img); //constuctor
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);//funciones que lo dibujan en pantalla

    QPixmap *getPixmap() const;
    void setPixmap(QPixmap *value);

    void move_x();
    void move_y();
    void move();    //funcione que se encargan del movimiento
    float getVel_tempx() const;
    void setVel_tempx(float value);

    float getVel_tempy() const;
    void setVel_tempy(float value);

    float getVel_x() const;
    void setVel_x(float value);

    float getVel_y() const;
    void setVel_y(float value);

    int getVida() const;
    void setVida(int value);

    int getX() const;
    void setX(int value);

    int getY() const;
    void setY(int value);

private:
    int x,xi;       //propiedades del objeto
    int y,yi;
    int w;
    int h;
    int vida=30;
    float vel_x=25,vel_y=25,delta=0.1;
    float vel_tempx=vel_x,vel_tempy=vel_y;
    QPixmap pixmap;
    int columnas=0;
    QTimer *timer;
    QString Ies;
    QString Ider=":/Imagenes Proyecto final/4 Vulture/Vulture_walk_der.png"; //sprites
    QString Iizq=":/Imagenes Proyecto final/4 Vulture/Vulture_walk.png";


private slots:
    void Actualizacion(); //funcion que va a estar actualizando el sprite
};
#endif // MOOB_H
