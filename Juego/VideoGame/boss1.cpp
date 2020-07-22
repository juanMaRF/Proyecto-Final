#include "boss1.h"

boss1::boss1(int x, int y, int w, int h)
{
    x1=x;
    y1=y;
    w1=w;
    h1=h;

    QTimer * timer = new QTimer();

    connect(timer,SIGNAL(timeout()),this, SLOT(ataques()));

    timer->start(100); //Velocidad de los ataques

}

QRectF boss1::boundingRect() const
{
    return QRect(x1,y1,w1,h1);
}

void boss1::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //Fondo del jefe
    QPixmap pixmap;
    pixmap.load(":/Imagenes Proyecto final/proto_jefe.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

void boss1::ataques()
{
    //Se escoge el ataque del jefe
    tipo4 = 1;

    //ataque 1 del jefe
    if(tipo4==0){
        //se elige al azar la posicion de los ataques para el jefe
        tipo2 = 286+rand()% (287-510);
        tipo3 = 151+rand()% (151-950);
        //se elige al azar direccion del ataque
        tipo= rand()% 4;
        //ataque del jefe con caida libre (direccion: abajo)
        if(tipo==0){
            if(tipo3<500 and tipo3>150){
                atack1 = new caida_libre(tipo3);
                scene()->addItem(atack1);
            }
        }
        //ataque del jefe direccion: arriba
        if(tipo==1){
            atack1_up= new ataque_Bas(1,2,tipo3,800,10,10);
            scene()->addItem(atack1_up);
        }
        //ataque del jefe direccion: izquierda
        if(tipo==2){
            atack1_lef = new ataque_Bas(1,0,1000,tipo2,10,10);
            scene()->addItem(atack1_lef);
        }
        //ataque del jefe direccion: derecha
        if(tipo==3){
            atack1_rig = new ataque_Bas(1,1,100,tipo2,10,10);
            scene()->addItem(atack1_rig);
        }
    }

    //ataque 2 del jefe
    if(tipo4 == 1){
        //Ataque de izquierda a derecha
        if(cont<500 and contro==0){
            cont+=5;
            if(cont<200 or cont>250){
                atack1 = new caida_libre(cont);
                scene()->addItem(atack1);
            }
            //Se cambia la direccion
            if(cont>=500){
                contro=1;
            }
        }
        //Ataque de derecha a izquierda
        if(contro==1 and cont>50){
            cont-=5;
            if(cont>400 or cont<350){
                atack1_5 = new caida_libre(cont);
                scene()->addItem(atack1_5);
            }
        }
    }


}
