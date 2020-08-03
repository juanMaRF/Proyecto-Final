#include "boss_jm.h"
#include "mainwindow.h"

extern MainWindow * game;

boss_jm::boss_jm(int x_,int y_,int w_, int h_)      //constructor
{
    //Damos valores a las propiedades
    x=x_;
    y=y_;
    w=w_;
    h=h_;

    //se conecta el temporizador al priimer ataque
    connect(timepo,SIGNAL(timeout()),this,SLOT(ataques()));
    timepo->start(150);
    //se conecta para realizar el cambio al segundo ataque
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
   //primer ataque
   if(tipo==0) {
       //se escoge una posicion aleatoria en x, luego se crea con
       //esa posicion en x y una establecida en y, luego se añade a la escena
       alea=169+rand()%(170-950);
       caida=new mru(alea,300);
       scene()->addItem(caida);
   }
   //segundo ataque
   if(tipo==1){
       // limites en X y Y
       //y 400 a 490
       //x 130 a 970
       //luego se escogen aleatoriamente y se crean
       //y se añaden a la escena
       alea=129+rand()%(130-970);
       alea1=399+rand()%(400-490);
       b=new mcu(alea,alea1);
       scene()->addItem(b);
   }
}

void boss_jm::tipoA()
{
    ayuda1=rand()%101;
    //se escoge la probabilidad de hacer daño al boss

    if(ayuda1<=80){
        vida-=5;
    }
    //Se cambia de ataque
    if(ayuda==0){
        tipo=1;
        ayuda=1;
    }
    else if(ayuda==1){
        tipo=0;
        ayuda=0;
    }
    //Se detienen los timers cuando el boss muere
    if(vida<=0){
        game->puntaje->setScore(game->puntaje->getScore()+1);
        qDebug()<<"SCORE: "<<game->puntaje->getScore();
        qDebug()<<"MUERTE BOSS";
        game->cambio_mapas(4);
        timepo->stop();
        timepo1->stop();
    }
}
