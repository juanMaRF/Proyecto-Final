#include "player.h"
#include "mainwindow.h"
#include "mru.h"
#include "mcu.h"
#include "moob.h"
#include <QDebug>
//extern MainWindow * game;

int player::getX1() const
{
    return x1;
}

void player::setX1(int value)
{
    x1 = value;
}

int player::getY1() const
{
    return y1;
}

void player::setY1(int value)
{
    y1 = value;
}

int player::getW1() const
{
    return w1;
}

void player::setW1(int value)
{
    w1 = value;
}

int player::getH1() const
{
    return h1;
}

void player::setH1(int value)
{
    h1 = value;
}

int player::getVida() const
{
    return vida;
}

void player::setVida(int value)
{
    vida = value;
}

void player::choque()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    
    for(int i = 0, n = colliding_items.size(); i < n; i++){
        if(typeid (colliding_items[i]) == typeid (ataque_Bas) || typeid (colliding_items[i]) == typeid (mru) || typeid (colliding_items[i]) == typeid (mcu) || typeid (colliding_items[i]) == typeid (moob)){
            qDebug()<<vida;
            vida-=5;
        }
    }
}

player::player(short nivel,int x_, int y_, int w_, int h_,QGraphicsItem * parent): QObject(), QGraphicsPixmapItem()
{
    nivel1=nivel;
    x1=x_;
    y1=y_;
    w1=w_;
    h1=h_;
    setPos(x1,y1);

    connect(timepo,SIGNAL(timeout()),this,SLOT(choque()));
    timepo->start(100);

    setPixmap(QPixmap(":/Imagenes Proyecto final/6 Deceased/Caminar_Player/Deceased_walk6.png").scaled(w1,h1));

    if(nivel1==0){
          if(tipo==1){
              setPixmap(QPixmap(":/Imagenes Proyecto final/6 Deceased/Caminar_Player_Der/Deceased_walk6Der.png").scaled(w1,h1));
           }
          else{
              setPixmap(QPixmap(":/Imagenes Proyecto final/6 Deceased/Caminar_Player/Deceased_walk6.png").scaled(w1,h1));
          }
    }
    if(nivel1==1){
        setPixmap(QPixmap(":/Imagenes Proyecto final/playerproto.png").scaled(w1,h1));
    }
}
