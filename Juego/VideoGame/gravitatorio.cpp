#include "gravitatorio.h"

QRectF gravitatorio::boundingRect() const
{
    return (QRectF(-radio,-radio,2*radio,2*radio));
}

void gravitatorio::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::red);
    painter->drawEllipse(boundingRect());
}

gravitatorio::gravitatorio(double pos_x, double pos_y, double vel_x, double vel_y, double _masa, double _radio)
{
    this-> posx=pos_x;
    this->posy= pos_y;
    this->velx= vel_x;
    this->vely= vel_y;
    this->masa=_masa;
    this->radio= _radio;
}

void gravitatorio::setPosx(double value)
{
    posx = value;
}

void gravitatorio::setPosy(double value)
{
    posy = value;
}

void gravitatorio::setVelx(double value)
{
    velx = value;
}

void gravitatorio::setVely(double value)
{
    vely = value;
}

void gravitatorio::setAcelx(double value)
{
    acelx = value;
}

void gravitatorio::setAcely(double value)
{
    acely = value;
}

void gravitatorio::setMasa(double value)
{
    masa = value;
}

void gravitatorio::setRadio(double value)
{
    radio = value;
}

double gravitatorio::getPosx() const
{
    return posx;
}

double gravitatorio::getPosy() const
{
    return posy;
}

double gravitatorio::getVelx() const
{
    return velx;
}

double gravitatorio::getVely() const
{
    return vely;
}

double gravitatorio::getAcelx() const
{
    return acelx;
}

double gravitatorio::getAcely() const
{
    return acely;
}

double gravitatorio::getMasa() const
{
    return masa;
}

double gravitatorio::getRadio() const
{
    return radio;
}

void gravitatorio::Posicion()
{
    posx=posx+velx+1/2*acelx;
    posy=posy+vely+1/2*acely;
    setPos(posx,posy);
    velx= velx+acelx;
    vely=vely+acely;
    vel=sqrt(velx*velx+ vely*vely);
}

double gravitatorio::distancia(double posxi, double posyi)
{
    double Dist;
    Dist=pow((posxi-posx),2)+pow((posyi-posy),2);
    return Dist;
}

double gravitatorio::angulo(double posxi, double posyi)
{
    double Angulo=0;
    Angulo=atan2((posyi-posy),(posxi-posx));
    return Angulo;
}

void gravitatorio::aceleracion(gravitatorio &interacion)
{
    double Distancia,Aceleracion,Angulo;
    Distancia=distancia(interacion.getPosx() ,interacion.getPosy());
    Angulo=angulo(interacion.getPosx(),interacion.getPosy());
    Aceleracion=interacion.getMasa()/Distancia;
    acelx+=Aceleracion*cos(Angulo);
    acely+=Aceleracion*sin(Angulo);
}
