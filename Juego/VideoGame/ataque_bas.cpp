#include "ataque_bas.h"
#include "mainwindow.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QDebug>

extern MainWindow * game;

ataque_Bas::ataque_Bas(short tipo): QObject(), QGraphicsPixmapItem()
{

    setPixmap(QPixmap(":/n/Imagenes Proyecto final/6 Deceased/Ball.png"));
    ataque=tipo;
    QTimer * timer = new QTimer();

    connect(timer,SIGNAL(timeout()),this, SLOT(move()));

    timer->start(50);
}

void ataque_Bas::move()
{
    if(con==1){
        pos_inicial=pos().x();
        con=2;
    }

    if(ataque == 0){
        setPos(x()-10,y());
    }
    if(ataque == 1){
        setPos(x()+10,y());
    }

    if(pos_inicial+200<=pos().x() or pos_inicial-200>=pos().x()){
        scene()->removeItem(this);
        delete this;
    }


}
