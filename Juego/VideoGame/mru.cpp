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
            //le quita al jugador vida
            game->jugador->vida-=5;
            //y elimina a el objeto
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
