#ifndef SLIME_H
#define SLIME_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPainter>


class slime:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:


    slime(int x, int y);
    int getX() const;
    void setX(int value);

    int getY() const;

    void setY(int value);

private:
    int X;
    int Y;
};

#endif // SLIME_H
