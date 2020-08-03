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



    int getVida() const;
    void setVida(int value);

private:
    int x,xi;       //propiedades del objeto
    int y,yi;
    int w;
    int h;
    int vida=30;
    float velx=25,vely=25,delta=0.1;
    float vel_tempx=velx,vel_tempy=vely;
    QPixmap pixmap;
    int columnas=0;
    QTimer *timer;
    QTimer *timepo=new QTimer;
    QString Ies;
    QString Ider=":/Imagenes Proyecto final/4 Vulture/Vulture_walk_der.png"; //sprites
    QString Iizq=":/Imagenes Proyecto final/4 Vulture/Vulture_walk.png";


private slots:
    void Actualizacion(); //funcion que va a estar actualizando el sprite
    void move();    //funcione que se encargan del movimiento
};
#endif // MOOB_H
