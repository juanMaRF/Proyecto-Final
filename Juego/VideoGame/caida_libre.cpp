#include "caida_libre.h"
#include "mainwindow.h"
#include <QDebug>
#include <QTimer>

extern MainWindow * game;


caida_libre::caida_libre(int x, QGraphicsItem * parent): QObject(), QGraphicsPixmapItem()
{
    PosX= x;
    PosY=70;
    Vel=0;
    w=10;
    h=10;

    setPixmap(QPixmap(":/Imagenes Proyecto final/6 Deceased/Ball.png").scaled(w,h));


    connect(timer,SIGNAL(timeout()),this, SLOT(move()));
    timer->start(50);
}

void caida_libre::actu_vel()
{
   Vel=Vel-g*delta;
}

void caida_libre::move()
{
    if(PosY==700){
        scene()->removeItem(this);
        timer->stop();
        delete this;
    }
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; i++){
        if(typeid(*(colliding_items[i])) == typeid (player)){
                    if(this->collidesWithItem(game->jugador)){
                        game->jugador->setVida(game->jugador->getVida()-1);
                        qDebug()<<"VIDA JUGADOR 1: "<<game->jugador->getVida();
                    }
                    if(this->collidesWithItem(game->jugador2)){
                        game->jugador2->setVida(game->jugador2->getVida()-1);
                        qDebug()<<"VIDA JUGADOR 2: "<<game->jugador2->getVida();
                    }
                    scene()->removeItem(this);
                    delete this;
                    colliding_items.clear();
                    //termina el ciclo para evitar errores
                    break;
                }

        if(game->multi==1){
            if(game->jugador->getVida()==0 && game->jugador->fin==false){
                game->jugador->setX1(2000);
                game->jugador->setY1(2000);
                game->jugador->fin=true;
//                        game->cambio_mapas(4);
                game->final();
            }
        }

                if(game->multi==2){
                    if(game->jugador->getVida()<=0 && game->jugador2->getVida()<=0 ){
                        game->jugador->setX1(2000);
                        game->jugador->setY1(2000);
                        game->final();
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

    if(con==0){
        pos_inicial=PosY;
        con=2;
    }
    PosY=PosY-(0.5*Vel*delta);
    setPos(PosX,PosY);
    actu_vel();

}
