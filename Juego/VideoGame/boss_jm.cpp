#include "boss_jm.h"

boss_jm::boss_jm(int x_,int y_,int w_, int h_)
{
    x=x_;
    y=y_;
    w=w_;
    h=h_;

    connect(timepo,SIGNAL(timeout()),this,SLOT(ataques()));
    timepo->start(150);

    connect(timepo1,SIGNAL(timeout()),this,SLOT(tipoA()));
    timepo1->start(25000);
}

QRectF boss_jm::boundingRect() const
{
   return QRectF(x,y,w,h);
}

void boss_jm::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/Imagenes Proyecto final/sans.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

void boss_jm::ataques()
{
    if(tipo==0) {
       alea=169+rand()%(170-950);
       caida=new mru(alea,300);
       scene()->addItem(caida);
//       caida=new mru(170,300);scene()->addItem(caida);
//       caida1=new mru(230,300);scene()->addItem(caida1);
//       caida2=new mru(290,300);scene()->addItem(caida2);
//       caida3=new mru(350,300);scene()->addItem(caida3);
//       caida4=new mru(410,300);scene()->addItem(caida4);
//       caida5=new mru(470,300);scene()->addItem(caida5);
//       caida6=new mru(530,300);scene()->addItem(caida6);
//       caida7=new mru(590,300);scene()->addItem(caida7);
//       caida8=new mru(650,300);scene()->addItem(caida8);
//       caida9=new mru(710,300);scene()->addItem(caida9);
//       caida10=new mru(770,300);scene()->addItem(caida10);
//       caida11=new mru(830,300);scene()->addItem(caida11);
//       caida12=new mru(890,300);scene()->addItem(caida12);
//       caida13=new mru(950,300);scene()->addItem(caida13);
//       tipo=3;
   }
   if(tipo==1){
       //y 400 a 490
       //x 130 a 970
       alea=129+rand()%(130-970);
       alea1=399+rand()%(400-490);
       b=new mcu(alea,alea1);
       scene()->addItem(b);
   }
}

void boss_jm::tipoA()
{
    ayuda1=rand()%101;

    if(ayuda1<=80){
        vida-=5;
    }

    if(ayuda==0){
        tipo=1;
        ayuda=1;
    }
    else if(ayuda==1){
        tipo=0;
        ayuda=0;
    }

    if(vida<=0){
        timepo->stop();
        timepo1->stop();
    }
}
