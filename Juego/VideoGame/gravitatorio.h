#ifndef GRAVITATORIO_H
#define GRAVITATORIO_H


#include <math.h>
#include <QGraphicsItem>
#include <QPainter>

using namespace std;

class gravitatorio : public QGraphicsItem
{
private:
    double posx, posy;
    double velx, vely,vel;
    double acelx, acely;
    double masa, radio;
    int r;

public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    gravitatorio(double pos_x,double pos_y,double vel_x,double vel_y, double _masa,double _radio);
    void setPosx(double value);
    void setPosy(double value);
    void setVelx(double value);
    void setVely(double value);
    void setAcelx(double value);
    void setAcely(double value);
    void setMasa(double value);
    void setRadio(double value);
    double getPosx() const;
    double getPosy() const;
    double getVelx() const;
    double getVely() const;
    double getAcelx() const;
    double getAcely() const;
    double getMasa() const;
    double getRadio() const;


    void Posicion();
    double distancia(double posxi,double posyi);
    double angulo(double posxi,double posyi);
    void aceleracion(gravitatorio &interacion);

};

#endif // GRAVITATORIO_H
