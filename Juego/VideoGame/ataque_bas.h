#ifndef ATAQUE_BAS_H
#define ATAQUE_BAS_H
#include <QGraphicsPixmapItem>
#include "mainwindow.h"
#include "enemi_dis.h"


class ataque_Bas:public QObject, public QGraphicsPixmapItem
{
   Q_OBJECT
public:
    ataque_Bas(short nivel,short tipo,int x, int y, int h, int w);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);

    int getX1() const;
    void setX1(int value);

    int getY1() const;
    void setY1(int value);

    void muros();

private slots:
    void move();

private:
    enemi_dis *prueba;
    MainWindow *juego;
    int pos_inicial;
    short ataque,con=1,nivel1;
    int x1,y1,h1,w1;

};

#endif // ATAQUE_BAS_H
