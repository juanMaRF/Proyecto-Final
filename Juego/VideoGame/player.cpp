#include "player.h"
#include <QDebug>

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

void player::rozamiento(short n)
{
    if(n==0){
        fuerzaT=15-R1*6;
    }
    if(n==1){
        fuerzaT=15-R2*6;
    }
}

void player::slime1()
{
    lentitud.push_back(new slime(200,200));
    lentitud.push_back(new slime(300,400));
    lentitud.push_back(new slime(800,250));
    lentitud.push_back(new slime(600,350));
    for(int i=0;i<lentitud.size();i++){
        lentitud[i]->setPos(lentitud[i]->getX(),lentitud[i]->getY());
        scene()->addItem(lentitud[i]);
    }
}

player::player(short nivel,int x_, int y_, int w_, int h_)
{
    nivel1=nivel;
    x1=x_;
    y1=y_;
    w1=w_;
    h1=h_;
}

QRectF player::boundingRect() const
{
    return QRect(x1,y1,w1,h1);
}

void player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;

    if(nivel1==0){

        if(tipo==0){

            //Animacion caminar player (direccion: Izquierda)
            if(imagen==0){
                imagen=2;

                pixmap.load(":/n/Imagenes Proyecto final/6 Deceased/Caminar_Player/Deceased_walk6.png");
                painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
            }
            else if(imagen==2){
                imagen=3;
                pixmap.load(":/n/Imagenes Proyecto final/6 Deceased/Caminar_Player/Deceased_walk5.png");
                painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
            }
            else if(imagen==3){
                imagen=4;
                pixmap.load(":/n/Imagenes Proyecto final/6 Deceased/Caminar_Player/Deceased_walk4.png");
                painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
            }
            else if(imagen==4){
                imagen=5;
                pixmap.load(":/n/Imagenes Proyecto final/6 Deceased/Caminar_Player/Deceased_walk3.png");
                painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
            }
            else if(imagen==5){
                imagen=6;
                pixmap.load(":/n/Imagenes Proyecto final/6 Deceased/Caminar_Player/Deceased_walk2.png");
                painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
            }
            else if(imagen==6){
                imagen=0;
                pixmap.load(":/n/Imagenes Proyecto final/6 Deceased/Caminar_Player/Deceased_walk.png");
                painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
            }
        }


        //Animacion caminar player (direccion: Derecha)
        if(tipo==1){

            if(imagen==0){
                imagen=2;

                pixmap.load(":/caminader/Imagenes Proyecto final/6 Deceased/Caminar_Player_Der/Deceased_walk6Der.png");
                painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
            }
            else if(imagen==2){
                imagen=3;
                pixmap.load(":/caminader/Imagenes Proyecto final/6 Deceased/Caminar_Player_Der/Deceased_walk5Der.png");
                painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
            }
            else if(imagen==3){
                imagen=4;
                pixmap.load(":/caminader/Imagenes Proyecto final/6 Deceased/Caminar_Player_Der/Deceased_walk4Der.png");
                painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
            }
            else if(imagen==4){
                imagen=5;
                pixmap.load(":/caminader/Imagenes Proyecto final/6 Deceased/Caminar_Player_Der/Deceased_walk3Der.png");
                painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
            }
            else if(imagen==5){
                imagen=6;
                pixmap.load(":/caminader/Imagenes Proyecto final/6 Deceased/Caminar_Player_Der/Deceased_walk2Der.png");
                painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
            }
            else if(imagen==6){
                imagen=0;
                pixmap.load(":/caminader/Imagenes Proyecto final/6 Deceased/Caminar_Player_Der/Deceased_walk1Der.png");
                painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
            }

        }
    }
    if(nivel1==1){
        pixmap.load(":/Imagenes Proyecto final/playerproto.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
}

void player::keyPressEvent(QKeyEvent *event)
{
    //Key Event's de movimiento del jugador
    if(event->key()==Qt::Key_Left){
        for(int i=0;i<lentitud.size();i++){
            if(this->collidesWithItem(lentitud.at(i))){
                rozamiento(1);
            }
            else{
                rozamiento(0);
            }
        }
        setPos(getX1()-fuerzaT,getY1());
        setX1(getX1()-fuerzaT);
        tipo=0;

    }
    else if (event->key() == Qt::Key_Right){
        for(int i=0;i<lentitud.size();i++){
            if(this->collidesWithItem(lentitud.at(i))){
                rozamiento(1);
            }
            else{
                rozamiento(0);
            }
        }
        setPos(getX1()+fuerzaT,getY1());
        setX1(getX1()+fuerzaT);
        tipo=1;

    }
    else if(event->key()== Qt::Key_Up){
        for(int i=0;i<lentitud.size();i++){
            if(this->collidesWithItem(lentitud.at(i))){
                rozamiento(1);
            }
            else{
                rozamiento(0);
            }
        }
        setPos(getX1(),getY1()-fuerzaT);
        setY1(getY1()-fuerzaT);


    }
    else if(event->key()== Qt::Key_Down){
        for(int i=0;i<lentitud.size();i++){
            if(this->collidesWithItem(lentitud.at(i))){
                rozamiento(1);
            }
            else{
                rozamiento(0);
            }
        }
        setPos(getX1(),getY1()+fuerzaT);
        setY1(getY1()+fuerzaT);

    }

    //Ataque basico
    else if(event->key()== Qt::Key_Space){
        if(nivel1==0){
            if(tipo==1){
                disparo = new ataque_Bas(0,tipo,x()+50,y()+20,10,10);
            }
            if(tipo==0){
                disparo = new ataque_Bas(0,tipo,x()-10,y()+20,10,10);
            }

            disparo->setPos(x1,y1);
            scene()->addItem(disparo);
        }
    }

    //Ataque especial (Mov Parabolico)
    else if(event->key()==0x43){
        if(nivel1==0){
           if(tipo==1){
                ataque_es = new tiropara(1,getX1(),getY1(),20,-45);
                scene()->addItem(ataque_es);
           }
           if(tipo==0){
               ataque_es = new tiropara(0,getX1(),getY1(),20,-45);
               scene()->addItem(ataque_es);
           }
        }
    }
}
