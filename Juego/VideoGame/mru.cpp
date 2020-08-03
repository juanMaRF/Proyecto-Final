#include "mru.h"
#include "player.h"
#include "mainwindow.h"

extern MainWindow * game;

mru::mru(int x_, int y_):QObject(), QGraphicsPixmapItem()
{
    x=x_;
    y=y_;
    xi=x_;
    yi=y_;
    setPos(x,y);
    //asigan la posicion del objeto y le asigna la imagen del circulo
    setPixmap(QPixmap(":/Imagenes Proyecto final/6 Deceased/bola.png").scaled(15,15));
    //luego lo conecta con la funcion encargada de su movimiento
    connect(timepo,SIGNAL(timeout()),this,SLOT(move_y()));
    timepo->start(50);
}

void mru::move_y()
{
    //crea una lista con objetos que colicionen en ese instante
    QList<QGraphicsItem *> colliding_items = collidingItems();
    //recorre la lista
    for(int i=0,n=colliding_items.size();i<n;i++){
        //verifica que halla colicionado con el jugador
        if(typeid (*colliding_items[i]) == typeid (player)){


            //Quita vida a los jugadores
            if(this->collidesWithItem(game->jugador)){
                game->jugador->setVida(game->jugador->getVida()-1);
                qDebug()<<"VIDA JUGADOR 1: "<<game->jugador->getVida();
            }
            if(this->collidesWithItem(game->jugador2)){
                game->jugador2->setVida(game->jugador2->getVida()-1);
                qDebug()<<"VIDA JUGADOR 2: "<<game->jugador2->getVida();
            }

            if(game->multi==1){
                if(game->jugador->getVida()==0){
                    game->cambio_mapas(4);
                }
            }

            if(game->multi==2){
                if(game->jugador->getVida()<=0 && game->jugador2->getVida()<=0 ){
                    game->puntaje->setScore(0);
                    game->cambio_mapas(4);
                }
                if(game->jugador->getVida()<=0){
                    scene()->removeItem(game->jugador);
                }
                if(game->jugador2->getVida()<=0){
                    scene()->removeItem(game->jugador2);
                }
            }

            //y elimina a el objeto
            timepo->stop();
            scene()->removeItem(this);
            delete this;
            colliding_items.clear();
            break;
        }
    }

    //se encarga de eliminar el objeto cuando llega a una posicion especifica en y
    if(yi+300==y){
        delete this;
    }
    //realiza el MRU con esa forma especifica de zigzag
    y=y+vely*delta;
    if((xi+30==x) || (xi-30==x)){
        velx=velx*-1;
    }
    x=x+velx*delta;
    setPos(x,y);
}
