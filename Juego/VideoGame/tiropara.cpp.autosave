#include "tiropara.h"
#include "mainwindow.h"
#include "enemi_dis.h"

extern MainWindow * game;

tiropara::tiropara(int tipo,double x, double y, double v, double a,QGraphicsItem * parent): QObject(), QGraphicsPixmapItem()
{
    tipo1=tipo;
    posx=x;
    posy=y;
    vel=v;
    ang=a;
    r=10;
    
    //Imagen del tiro parabolico
    setPixmap(QPixmap(":/Imagenes Proyecto final/6 Deceased/Ball.png").scaled(20,20));

    QTimer * timer = new QTimer();

    connect(timer,SIGNAL(timeout()),this, SLOT(ActualizarPosicion()));

    timer->start(50);//velocidad del tiro
}

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
    //Almacenamos las colisiones en una QList
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; i++){
        //Comprobamos si colisiona contra una enemigo o jugador
        if(typeid(*(colliding_items[i])) == typeid (enemi_dis) or typeid(*(colliding_items[i])) == typeid (player) or typeid(*(colliding_items[i])) == typeid(moob)){
            //De ser asi eliminamos el tiro
            scene()->removeItem(this);
            delete this;
        }
    }

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

    if(getPosy()>pos_inicial+40){
        scene()->removeItem(this);
        delete this;
    }
}

void tiropara::ActualizarVelocidad()
{
    vel_x=vel*cos(ang);
    vel_y=vel*sin(ang)-g*delta;
    ang=atan2(vel_y,vel_x);
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

