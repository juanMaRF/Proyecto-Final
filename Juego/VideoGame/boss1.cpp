#include "boss1.h"

boss1::boss1(QPainter *painter)
{
    QPixmap pixmap;

    pixmap.load(":/enemy_dis_der/Imagenes Proyecto final/3 Scorpio/Enemy_dis_der/Scorpio_walk1_der.png");

}

QRectF boss1::boundingRect() const
{
    return QRect(x1,y1,w1,h1);
}
