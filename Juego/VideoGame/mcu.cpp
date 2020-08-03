#include "mcu.h"
#include "player.h"
#include "mainwindow.h"

extern MainWindow * game;

mcu::mcu(int x_, int y_):QObject(), QGraphicsPixmapItem()
{
    x=x_;
    y=y_;
    //asiga la posicion del objeto
    setPos(x,y);
    //carga la imagen del circulo
    setPixmap(QPixmap(":/Imagenes Proyecto final/6 Deceased/bola.png").scaled(15,15));
    //conecta un timer al movimiento para que este se repita cada cierto tiempo y se vea fluido
    connect(timepo,SIGNAL(timeout()),this,SLOT(move()));
    timepo->start(50);
    //conecta un timer para matar a los objetos
    connect(timepo1,SIGNAL(timeout()),this,SLOT(borra()));
    timepo1->start(5000);
}

void mcu::move()
{
    //crea una lista con objetos que colicionen en ese instante
    QList<QGraphicsItem *> colliding_items = collidingItems();
    //recorre la lista
    for(int i=0,n=colliding_items.size();i<n;i++){
        //verifica que halla colicionado con el jugador
        if(typeid (*colliding_items[i]) == typeid (player)){
            //le quita al jugador vida
            game->jugador->vida-=5;
            qDebug()<<game->jugador->vida;
            //y elimina a el objeto
            timepo->stop();
            timepo1->stop();
            colliding_items.clear();
            //termina el ciclo para evitar errores
            break;
        }
    }
    //reliza el MCU
    xc=x+(R*cos((Vt/R)*delta));
    yc=y+(R*sin((Vt/R)*delta));
    setPos(xc,yc);
    delta+=0.1;
}

void mcu::borra()
{
    //borra al objeto y detiene sus timers
    delete this;
    this->timepo1->stop();
    this->timepo->stop();
}
