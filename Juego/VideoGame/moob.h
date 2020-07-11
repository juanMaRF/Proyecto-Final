#ifndef MOOB_H
#define MOOB_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class moob: public QGraphicsItem,public QObject
{
    int x;
    int y;
    int w;
    int h;
    float vel_x,vel_y,delta=0.1;
    float vel_tempx=vel_x,vel_tempy=vel_y;
    QPixmap pixmap;
    int columnas=0;
    QTimer *timer;
    QString Ider,Iizq,Ies;
public:
    moob();
    moob(int x_, int y_, int w_, int h_,QString img);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
    int getX() const;
    void setX(int value);
    int getY() const;
    void setY(int value);
    QPixmap *getPixmap() const;
    void setPixmap(QPixmap *value);

    void move_x();
    void move_y();
    float getVel_tempx() const;
    void setVel_tempx(float value);

    float getVel_tempy() const;
    void setVel_tempy(float value);

public slots:
    void Actualizacion();
};
#endif // MOOB_H
