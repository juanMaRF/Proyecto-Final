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
        if(typeid(*(colliding_items[i])) == typeid (player)){
                    if(this->collidesWithItem(game->jugador)){
                        game->jugador->setVida(game->jugador->getVida()-1);
                        qDebug()<<"VIDA JUGADOR 1: "<<game->jugador->getVida();
                    }
                    if(this->collidesWithItem(game->jugador2)){
                        game->jugador2->setVida(game->jugador2->getVida()-1);
                        qDebug()<<"VIDA JUGADOR 2: "<<game->jugador2->getVida();
                    }
                    game->scene->removeItem(this);
                    timepo->stop();
                    timepo1->stop();
                    colliding_items.clear();
                    //termina el ciclo para evitar errores
                    break;
                }

                if(game->multi==1){
                    if(game->jugador->getVida()==0){
                        game->jugador->setX1(2000);
                        game->jugador->setY1(2000);
                        game->jugador->setVida(1);
                        game->cambio_mapas(4);
                    }
                }

                if(game->multi==2){
                    if(game->jugador->getVida()<=0 && game->jugador2->getVida()<=0 ){
                        game->jugador->setX1(2000);
                        game->jugador->setY1(2000);
                        game->cambio_mapas(4);
                    }
                    if(game->jugador->getVida()<=0 && game->jugador->bre==false){
                        game->jugador->setX1(2000);
                        game->jugador->setY1(2000);
                        game->jugador->bre=true;
                        scene()->removeItem(game->jugador);
                    }
                    if(game->jugador2->getVida()<=0 && game->jugador2->bre==false){
                        game->jugador->setX1(2000);
                        game->jugador->setY1(2000);
                        game->jugador2->bre=true;
                        scene()->removeItem(game->jugador2);
                    }
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
