#ifndef MOOB_H
#define MOOB_H
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class moob : public QGraphicsItem
{
    //double g= 9.8;
    double delta =0.1;
    double y,x, vel, vel_x, vel_y;
    int w,h;
public:
    moob();
    moob(int x_,int y_,int w_,int h_);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void actualizar_y(int posx_per);
    void actualizar_x(int posx_per);


    double getX() const;
    void setX(double value);
    double getY() const;
    void setY(double value);
};
#endif // MOOB_H
