#ifndef MUNECO_H
#define MUNECO_H


#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
class muneco: public QGraphicsItem,public QObject
{
    int r,x,y,w,h,columnas,vel_x=50,vel_y=50;
    QTimer *timer;
    QPixmap pixmap;
    double delta=0.1;
    QString Iiz,Ide,Ies;
public:
    muneco();
    muneco(int x_, int y_, int w_, int h_);
    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    int getX() const;
    void setX(int value);
    int getY() const;
    void setY(int value);

public slots:
    void Actualizacion();
};

#endif // MUNECO_H
