#include "boss1.h"

boss1::boss1(int x, int y, int w, int h)
{
    x1=x;
    y1=y;
    w1=w;
    h1=h;

    QTimer * timer = new QTimer();

    connect(timer,SIGNAL(timeout()),this, SLOT(ataques()));

    timer->start(100);

}

QRectF boss1::boundingRect() const
{
    return QRect(x1,y1,w1,h1);
}

void boss1::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/Imagenes Proyecto final/proto_jefe.jpg");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

void boss1::ataques()
{
    tipo4 = 1;
    if(tipo4==0){
        //srand(time(NULL));
        tipo2 = 286+rand()% (287-510);
        tipo3 = 151+rand()% (151-950);
        tipo= rand()% 4;
        if(tipo==0){
            atack1 = new caida_libre(tipo3);
            scene()->addItem(atack1);
        }
        if(tipo==1){
            atack1_up= new ataque_Bas(2,tipo3,800,10,10);
            scene()->addItem(atack1_up);
        }
        if(tipo==2){
            atack1_lef = new ataque_Bas(0,1000,tipo2,10,10);
            scene()->addItem(atack1_lef);
        }
        if(tipo==3){
            atack1_rig = new ataque_Bas(1,100,tipo2,10,10);
            scene()->addItem(atack1_rig);
        }
    }
    if(tipo4 == 1){
        if(cont<500 and contro==0){
            cont+=5;
            if(cont<200 or cont>250){
                atack1 = new caida_libre(cont);
                scene()->addItem(atack1);
            }
            if(cont>=500){
                contro=1;
            }
        }
        if(contro==1 and cont>50){
            cont-=5;
            if(cont>400 or cont<350){
                atack1_5 = new caida_libre(cont);
                scene()->addItem(atack1_5);
            }
        }

    }
}
