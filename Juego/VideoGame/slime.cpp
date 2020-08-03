#include "slime.h"


slime::slime(int x, int y): QGraphicsPixmapItem()
{
    //Imagen del slime
    setPixmap(QPixmap(":/Imagenes Proyecto final/slime-verde.png").scaled(70,70));
    X=x;
    Y=y;
}

int slime::getX() const
{
    return X;
}

void slime::setX(int value)
{
    X = value;
}

int slime::getY() const
{
    return Y;
}

void slime::setY(int value)
{
    Y = value;
}
