#include "enemi_dis.h"
#include "ataque_bas.h"
#include "mainwindow.h"

extern MainWindow *game;

enemi_dis::enemi_dis(int nivel, int tipo,int x, int y,QGraphicsItem * parent): QObject(), QGraphicsPixmapItem()
{
    tipo1=tipo;
    nivel1=nivel;
    x1=x;
    y1=y;
    setPos(x1,y1);

    if(tipo1==1){
        setPixmap(QPixmap(":/Imagenes Proyecto final/3 Scorpio/Enemy_dis_der/Scorpio_walk1_der.png").scaled(80,60));
    }
    if(tipo1==0){
        setPixmap(QPixmap(":/Imagenes Proyecto final/3 Scorpio/Enemy_dis_izq/Scorpio_walk1.png").scaled(80,60));
    }


    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(60);

}

void enemi_dis::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; i++){
        if(typeid (*colliding_items[i]) == typeid (ataque_Bas)){
            if(this->getVida()==0){
                game->puntaje->setScore(game->puntaje->getScore()+1);
                qDebug()<<"SCORE: "<<game->puntaje->getScore();
                this->setX1(10000);
                this->setPos(getX1(),getY1());
                if(game->puntaje->getScore()==6){
                    game->cambio_mapas(1);
                }
                if(game->puntaje->getScore()==15){
                    game->cambio_mapas(3);
                }
            }
            this->setVida(this->getVida()-5);
            break;
        }else if(typeid (*colliding_items[i]) == typeid (tiropara)){
            if(this->getVida()==0){
                game->puntaje->setScore(game->puntaje->getScore()+1);
                qDebug()<<"SCORE: "<<game->puntaje->getScore();
                this->setX1(10000);
                this->setPos(getX1(),getY1());
                if(game->puntaje->getScore()==6){
                    game->cambio_mapas(1);
                }
                if(game->puntaje->getScore()==15){
                    game->cambio_mapas(3);
                }
            }
            this->setVida(this->getVida()-5);
            break;
        }

    }

    if(tipo1==1){
        if(imagen==0){
            imagen=1;
            setPixmap(QPixmap(":/Imagenes Proyecto final/3 Scorpio/Enemy_dis_der/Scorpio_walk2_der.png").scaled(80,60));
        }
        else if(imagen==1){
            imagen=2;
            setPixmap(QPixmap(":/Imagenes Proyecto final/3 Scorpio/Enemy_dis_der/Scorpio_walk3_der.png").scaled(80,60));
        }
        else if(imagen==2){
            imagen=0;
            setPixmap(QPixmap(":/Imagenes Proyecto final/3 Scorpio/Enemy_dis_der/Scorpio_walk4_der.png").scaled(80,60));
        }
    }

    if(tipo1==0){
        if(imagen==0){
            imagen=1;
            setPixmap(QPixmap(":/Imagenes Proyecto final/3 Scorpio/Enemy_dis_izq/Scorpio_walk2.png").scaled(80,60));
        }
        else if(imagen==1){
            imagen=2;
            setPixmap(QPixmap(":/Imagenes Proyecto final/3 Scorpio/Enemy_dis_izq/Scorpio_walk3.png").scaled(80,60));
        }
        else if(imagen==2){
            imagen=0;
            setPixmap(QPixmap(":/Imagenes Proyecto final/3 Scorpio/Enemy_dis_izq/Scorpio_walk4.png").scaled(80,60));
        }
    }

    if(con==0){
        pos_inicial=this->getY1();
        con=1;
    }

    if(nivel1==0){

        if(this->getY1()<pos_inicial+40 && col==0){
            this->setY1(this->getY1()+2);
            this->setPos(x1,this->getY1());
            if(this->getY1()==pos_inicial+40 or this->getY1()==pos_inicial+20){

            if(tipo1==0){
                SED = new ataque_enemy(0,0);
                SED->setPos(x1,y1);
                scene()->addItem(SED);
            }
            if(tipo1==1){
                SED = new ataque_enemy(0,1);
                SED->setPos(x1+50,y1);
                scene()->addItem(SED);
            }
            if(this->getY1()==pos_inicial+40){
               col=1;
            }

            }
        }
        if(this->getY1()>pos_inicial && col==1){
            this->setY1(this->getY1()-2);
            this->setPos(x1,this->getY1());
            if(this->getY1()==pos_inicial or this->getY1()==pos_inicial+20){

                if(tipo1==0){
                    SED=new ataque_enemy(0,0);
                    SED->setPos(x1,y1);
                    scene()->addItem(SED);
                }
                if(tipo1==1){
                    SED= new ataque_enemy(0,1);
                    SED->setPos(x1+50,y1);
                    scene()->addItem(SED);
                }
                if(this->getY1()==pos_inicial){
                   col=0;
                }
            }
        }
    }

}

int enemi_dis::getVida() const
{
    return vida;
}

void enemi_dis::setVida(int value)
{
    vida = value;
}

int enemi_dis::getX1() const
{
    return x1;
}

void enemi_dis::setX1(int value)
{
    x1 = value;
}

int enemi_dis::getY1() const
{
    return y1;
}

void enemi_dis::setY1(int value)
{
    y1 = value;
}


