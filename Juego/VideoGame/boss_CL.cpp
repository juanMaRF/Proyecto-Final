#include "boss_CL.h"
#include "mainwindow.h"

extern MainWindow * game;

boss_CL::boss_CL(int x, int y, int w, int h)
{
    x1=x;
    y1=y;
    w1=w;
    h1=h;

    connect(timer,SIGNAL(timeout()),this, SLOT(ataques()));

    timer->start(100); //Velocidad de los ataques


    connect(time,SIGNAL(timeout()),this, SLOT(tipoA()));

    time->start(25000); //Cambio de Ataques
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

void boss_CL::tipoA()
{
    ayuda1=rand()%101;
    qDebug()<<"INDICADOR: "<<ayuda1;

    if(ayuda1<=80){
        setVida(getVida()-5);
        qDebug()<<"Daño Jefe: "<<getVida();
    }

    //Se cambia el ataque del jefe
    if(ayuda==0){
        tipo4=1;
        ayuda=1;
        //Reiniciamos variables
        cont=50;
        contro=0;
    }
    else if(ayuda==1){
        tipo4=0;
        ayuda=0;
    }

    if(getVida()<=0){
        game->puntaje->setScore(game->puntaje->getScore()+1);
        qDebug()<<"SCORE: "<<game->puntaje->getScore();
        qDebug()<<"MUERTE BOSS";
//        for(QList<caida_libre*>::iterator it=b1.begin();it!=b1.end();it++){
//            scene()->removeItem((*it));
//            b1.removeOne((*it));
//            delete (*it);
//        }
//        for(QList<ataque_Bas*>::iterator it=b2.begin();it!=b2.end();it++){
//            scene()->removeItem((*it));
//            b2.removeOne((*it));
//            delete (*it);
//        }
        game->cambio_mapas(2);
        timer->stop();
        time->stop();
    }
}

int boss_CL::getVida() const
{
    return vida;
}

void boss_CL::setVida(int value)
{
    vida = value;
}

void boss_CL::ataques()
{

    //ataque 1 del jefe
    if(tipo4==0){
        //se elige al azar la posicion de los ataques para el jefe
        tipo2 = 286+rand()% (287-510);
        tipo3 = 151+rand()% (151-950);
        //se elige al azar direccion del ataque
        tipo= rand()% 4;
        //ataque del jefe con caida libre (direccion: abajo)
        if(tipo==0){
            atack1 = new caida_libre(tipo3);b1.push_back(atack1);
            scene()->addItem(atack1);
        }
        //ataque del jefe direccion: arriba
        if(tipo==1){
            atack1_up= new ataque_Bas(1,2);b2.push_back(atack1_up);
            scene()->addItem(atack1_up);
            atack1_up->setPos(tipo3,510);
        }
        //ataque del jefe direccion: izquierda
        if(tipo==2){
            atack1_lef = new ataque_Bas(1,0);b2.push_back(atack1_lef);
            scene()->addItem(atack1_lef);
            atack1_lef->setPos(950,tipo2);
        }
        //ataque del jefe direccion: derecha
        if(tipo==3){
            atack1_rig = new ataque_Bas(1,1);b2.push_back(atack1_rig);
            scene()->addItem(atack1_rig);
            atack1_rig->setPos(150,tipo2);
        }
    }

    //ataque 2 del jefe
    if(tipo4 == 1){
        //Ataque de izquierda a derecha
        if(cont<1000 and contro==0){
            cont+=10;
            if(cont<200 or cont>250){
                atack1 = new caida_libre(cont);b1.push_back(atack1);
                scene()->addItem(atack1);
            }
            //Se cambia la direccion
            if(cont>=1000){
                contro=1;
            }
        }
        //Ataque de derecha a izquierda
        if(contro==1 and cont>50){
            cont-=10;
            if(cont>800 or cont<750){
                atack1_5 = new caida_libre(cont);b1.push_back(atack1_5);
                scene()->addItem(atack1_5);
            }
        }
    }

}
