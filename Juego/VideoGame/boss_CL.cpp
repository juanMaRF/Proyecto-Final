#include "boss_CL.h"

boss_CL::boss_CL(int x, int y, int w, int h)
{
    x1=x;
    y1=y;
    w1=w;
    h1=h;

    QTimer * timer = new QTimer();

    connect(timer,SIGNAL(timeout()),this, SLOT(ataques()));

    timer->start(100); //Velocidad de los ataques

}

QRectF boss_CL::boundingRect() const
{
    return QRect(x1,y1,w1,h1);
}

void boss_CL::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //Fondo del jefe
    QPixmap pixmap;
    pixmap.load(":/Imagenes Proyecto final/proto_jefe.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

void boss_CL::ataques()
{
    //Se escoge el ataque del jefe
    tipo4 = 0;

    //ataque 1 del jefe
    if(tipo4==0){
        //se elige al azar la posicion de los ataques para el jefe
        tipo2 = 286+rand()% (287-510);
        tipo3 = 151+rand()% (151-950);
        //se elige al azar direccion del ataque
        tipo= rand()% 4;
        //ataque del jefe con caida libre (direccion: abajo)
        if(tipo==0){
            atack1 = new caida_libre(tipo3);
            scene()->addItem(atack1);
        }
        //ataque del jefe direccion: arriba
        if(tipo==1){
            atack1_up= new ataque_Bas(1,2);
            scene()->addItem(atack1_up);
            atack1_up->setPos(tipo3,510);
        }
        //ataque del jefe direccion: izquierda
        if(tipo==2){
            atack1_lef = new ataque_Bas(1,0);
            scene()->addItem(atack1_lef);
            atack1_lef->setPos(950,tipo2);
        }
        //ataque del jefe direccion: derecha
        if(tipo==3){
            atack1_rig = new ataque_Bas(1,1);
            scene()->addItem(atack1_rig);
            atack1_rig->setPos(150,tipo2);
        }
    }

    //ataque 2 del jefe
    if(tipo4 == 1){
        //Ataque de izquierda a derecha
        if(cont<1000 and contro==0){
            cont+=5;
            if(cont<200 or cont>250){
                atack1 = new caida_libre(cont);
                scene()->addItem(atack1);
            }
            //Se cambia la direccion
            if(cont>=1000){
                contro=1;
            }
        }
        //Ataque de derecha a izquierda
        if(contro==1 and cont>50){
            cont-=5;
            if(cont>800 or cont<750){
                atack1_5 = new caida_libre(cont);
                scene()->addItem(atack1_5);
            }
        }
    }


}
