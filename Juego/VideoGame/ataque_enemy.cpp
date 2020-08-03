#include "ataque_enemy.h"
#include "mainwindow.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QDebug>
#include "enemi_dis.h"

extern MainWindow * game;

ataque_enemy::ataque_enemy(short nivel, short tipo,QGraphicsItem * parent): QObject(), QGraphicsPixmapItem()
{
    nivel1=nivel;
    ataque=tipo;

    setPixmap(QPixmap(":/Imagenes Proyecto final/6 Deceased/Ball.png").scaled(10,10));

    QTimer * timer = new QTimer();

    connect(timer,SIGNAL(timeout()),this, SLOT(move()));

    timer->start(50);
}

void ataque_enemy::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for(int i = 0, n = colliding_items.size(); i < n; i++){
        if(typeid(*(colliding_items[i])) == typeid(obstaculos)){

            //scene()->removeItem(colliding_items[i]);
            if(this->isVisible()){
                scene()->removeItem(this);
                //delete colliding_items[i];
                delete this;
                colliding_items.clear();
                break;
            }

        } //verifica que halla colicionado con el jugador
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

    if(nivel1==0){
        if(con==1){
            pos_inicial=pos().x();
            con=2;
        }

        if(ataque == 0){
            setPos(x()-10,y());
        }
        if(ataque == 1){
            setPos(x()+10,y());
        }

        if(pos_inicial+400<=pos().x() or pos_inicial-400>=pos().x()){
            scene()->removeItem(this);
            delete this;
        }
    }
    if(nivel1==1){
        if(ataque == 0){
            setPos(x()-30,y());
        }
        if(ataque == 1){
            setPos(x()+30,y());
        }
        if(ataque == 2){
            setPos(x(),y()-30);
        }
    }

//    if(pos_inicial+1000000<=pos().x() || pos_inicial-1000000>=pos().x() || pos_inicial-100000>=pos().y()){
//        scene()->removeItem(this);
//        delete this;
//    }

}
