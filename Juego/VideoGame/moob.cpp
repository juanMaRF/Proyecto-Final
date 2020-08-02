#include "moob.h"
#include "mainwindow.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QDebug>

extern MainWindow * game;

float moob::getVel_tempx() const
{
    return vel_tempx;
}

void moob::setVel_tempx(float value)
{
    vel_tempx = value;
}

float moob::getVel_tempy() const
{
    return vel_tempy;
}

void moob::setVel_tempy(float value)
{
    vel_tempy = value;
}

float moob::getVel_x() const
{
    return vel_x;
}

void moob::setVel_x(float value)
{
    vel_x = value;
}

float moob::getVel_y() const
{
    return vel_y;
}

void moob::setVel_y(float value)
{
    vel_y = value;
}

int moob::getVida() const
{
    return vida;
}

void moob::setVida(int value)
{
    vida = value;
}

int moob::getX() const
{
    return x;
}

void moob::setX(int value)
{
    x = value;
}

int moob::getY() const
{
    return y;
}

void moob::setY(int value)
{
    y = value;
}

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
}


QRectF moob::boundingRect() const
{
    return QRectF(-w/2,-h/2,w,h);
}

void moob::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-h/2,-h/2,pixmap,columnas,0,w,h);
}


void moob::move()
{
    //se encarga de realizar el MRU y dependiendo en que direccion se mueva cambia de sprite
    this->setX(this->getX()+vel_x*delta);
    y=y+vel_y*delta;
    this->setPos(this->getX(),y);

    if(vel_x<0){
        pixmap.load(Iizq);
    }else{
        pixmap.load(Ider);
    }
}

void moob::Actualizacion()
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
                this->setX(100000);
                this->setPos(getX(),y);
                //verifica el puntaje para luego cambiar de nivel
                if(game->puntaje->getScore()==6){
                    game->cambio_mapas(1);
                }
                if(game->puntaje->getScore()==15){
                    game->cambio_mapas(3);
                }

            }
        }else if(typeid (*colliding_items[i]) == typeid (tiropara)){
            //le quita vida al moob
            this->setVida(this->getVida()-10);
            qDebug()<<this->getVida();
            if(this->getVida()==0){
                //si su vida llega a 0 sube el score del jugador
                //y quita al moob de escena
                game->puntaje->setScore(game->puntaje->getScore()+1);
                qDebug()<<"SCORE: "<<game->puntaje->getScore();
                this->setX(100000);
                this->setPos(getX(),y);
                //verifica el puntaje para luego cambiar de nivel
                if(game->puntaje->getScore()==6){
                    game->cambio_mapas(1);
                }
                if(game->puntaje->getScore()==15){
                    game->cambio_mapas(3);
                }
            }

        }
        colliding_items.clear();
        break;
    }
    //el tamaño del sprite
    columnas +=50;
    if(columnas >=200)
    {
        columnas =0;
    }
    this->update(-w/2,-h/2,w,h);
}


