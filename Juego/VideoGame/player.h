#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class player:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
signals:
    void keyCaught(QKeyEvent *e);
public:
    player(int x_, int y_, int w_, int h_);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
    void keyPressEvent(QKeyEvent *event);
    int getX() const;
    void setX(int value);

    int getY() const;
    void setY(int value);


private:
    int x,y,h,w;
};

#endif // PLAYER_H
