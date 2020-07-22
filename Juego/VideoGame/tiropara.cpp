#include "tiropara.h"
<<<<<<< HEAD
=======
#include "mainwindow.h"

extern MainWindow * game;

tiropara::tiropara(int tipo,double x, double y, double v, double a)
{
    tipo1=tipo;
    posx=x;
    posy=y;
    vel=v;
    ang=a;
    r=10;
    QTimer * timer = new QTimer();

    connect(timer,SIGNAL(timeout()),this, SLOT(ActualizarPosicion()));

    timer->start(50);
}
>>>>>>> 678c660a3798067593ccfe052bd985a8d1a75be7

double tiropara::getPosy() const
{
    return posy;
}

double tiropara::getPosx() const
{
    return posx;
}

void tiropara::ActualizarPosicion()
{
<<<<<<< HEAD
    posx=posx+vel_x*delta;
    posy=posy+vel_y*delta-(0.5*g*delta*delta);
    setPos(posx,-posy);
    setPos(posx,-posy);
=======
    if(con==0){
        pos_inicial=posy;
        con=1;
    }

    ActualizarVelocidad();


    //Direccion del Ataque especial: (Derecha)
    if(tipo1==1){
        setPosx(getPosx()+vel_x*delta);
    }
    //Direccion del Ataque especial: (Izquierda)
    if(tipo1==0){
        setPosx(getPosx()-vel_x*delta);
    }


    setPosy(getPosy()+vel_y*delta-(0.5*g*delta*delta));
    setPos(getPosx(),getPosy());
>>>>>>> 678c660a3798067593ccfe052bd985a8d1a75be7

}

void tiropara::ActualizarVelocidad()
{
    vel_x=vel*cos(ang);
    vel_y=vel*sin(ang)-g*delta;
    ang=atan2(vel_y,vel_x);
<<<<<<< HEAD
    vel= sqrt(vel_x*vel_x+ vel_y*vel_y);
    setPos(posx,-posy);
}

QRectF tiropara::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);

}

void tiropara::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::green);
    painter->drawEllipse(boundingRect());
}

tiropara::tiropara()
{

}

tiropara::tiropara(double x, double y, double v, double a)
{
    posx=x;
    posy=y;
    vel=v;
    ang=a;
    r=10;
    setPos(posx,-posy);
}
=======
    vel= sqrt((vel_x*vel_x) + (vel_y*vel_y));

}

void tiropara::setPosy(double value)
{
    posy = value;
}

void tiropara::setPosx(double value)
{
    posx = value;
}

QRectF tiropara::boundingRect() const
{
    return QRectF(posx,posy,2*r,2*r);

}

void tiropara::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;

    pixmap.load(":/n/Imagenes Proyecto final/6 Deceased/Ball.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}



>>>>>>> 678c660a3798067593ccfe052bd985a8d1a75be7
