#include "moob.h"
#include "mainwindow.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QDebug>

extern MainWindow * game;

moob::moob(int x_, int y_, int w_, int h_, QString img)
{
    x=x_;xi=x_;
    y=y_;yi=y_;
    w=w_;
    h=h_;
    //asigna variables
    if(img=="perro"){
        pixmap.load(":/Imagenes Proyecto final/4 Vulture/Vulture_walk.png");
    }else if(img=="sans"){
        pixmap.load(":/Imagenes Proyecto final/sans.png");
    }

    timer=new QTimer();
    timer->start(80);// modifica la velocidad en que itera entre las imagenes

    //conecta a la funcion de actualizacion
    connect(timer,SIGNAL(timeout()),this,SLOT(Actualizacion()));


    connect(timepo,SIGNAL(timeout()),this,SLOT(move()));
    timepo->start(30);

}


QRectF moob::boundingRect() const
{
    return QRectF(-w/2,-h/2,w,h);
}

void moob::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-h/2,-h/2,pixmap,columnas,0,w,h);
}

int moob::getVida() const
{
    return vida;
}

void moob::setVida(int value)
{
    vida = value;
}


void moob::move()
{
    //crea una lista con objetos que colicionen en ese instante
    QList<QGraphicsItem *> colliding_items = collidingItems();
    //recorre la lista
    for(int i = 0, n = colliding_items.size(); i < n; i++){
        //verifica si choca con las balas
        if(typeid (*colliding_items[i]) == typeid (ataque_Bas)){
            //le quita vida al moob
            this->setVida(this->getVida()-5);
            if(this->getVida()==0){
                //si su vida llega a 0 sube el score del jugador
                //y quita al moob de escena
                game->puntaje->setScore(game->puntaje->getScore()+1);
                qDebug()<<"SCORE: "<<game->puntaje->getScore();
                game->scene->removeItem(this);
                x=10000;
                setPos(x,y);
                timepo->stop();
                timer->stop();
                //verifica el puntaje para luego cambiar de nivel
                if(game->puntaje->getScore()==6){
                    game->cambio_mapas(1);
                }
                if(game->puntaje->getScore()==15){
                    game->cambio_mapas(3);
                }

            }
        }//verifica que halla colicionado con el jugador
            if(typeid (*colliding_items[i]) == typeid (player)){
                //le quita al jugador vida
                game->jugador->vida-=5;
                qDebug()<<game->jugador->vida;
                //y elimina a el objeto
                timepo->stop();
                colliding_items.clear();
                //termina el ciclo para evitar errores
                break;
            }

    }

    //se encarga de realizar el MRU y dependiendo en que direccion se mueva cambia de sprite
    obstaculos *puntero=nullptr;
    QString onjto=game->colision(this,puntero);
    if(onjto=="lat")
    {
        if(!this->collidesWithItem(puntero)){
            velx=velx*-1;
        }
    }else if(onjto=="valla"){
        if(!this->collidesWithItem(puntero)){
            vely=vely*-1;
        }
    }
    x=x+velx*delta;
    y=y+vely*delta;
    setPos(x,y);

    if(velx<0){
        pixmap.load(Iizq);
    }else{
        pixmap.load(Ider);
    }
}

void moob::Actualizacion()
{

    //el tamaño del sprite
    columnas +=50;
    if(columnas >=200)
    {
        columnas =0;
    }
    this->update(-w/2,-h/2,w,h);
}


