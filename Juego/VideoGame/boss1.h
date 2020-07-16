#ifndef BOSS1_H
#define BOSS1_H
#include <QGraphicsPixmapItem>

class boss1:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    boss1(QPainter *painter);
    QRectF boundingRect() const;
private:
    int x1,y1,w1,h1;
};

#endif // BOSS1_H
