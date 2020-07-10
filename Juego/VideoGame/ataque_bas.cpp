#include "ataque_bas.h"
#include "mainwindow.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsItem>

extern MainWindow * game;

ataque_Bas::ataque_Bas(short tipo): QObject(), QGraphicsPixmapItem()
{

    setPixmap(QPixmap(":/n/Imagenes Proyecto final/6 Deceased/Ball.png"));
    ataque=tipo;
    QTimer * timer = new QTimer();
    setPos(x(),y());
    connect(timer,SIGNAL(timeout()),this, SLOT(move()));

    timer->start(50);
}

void ataque_Bas::move()
{
    if(ataque == 0){
        setPos(x()-10,y());
    }
    if(ataque == 1){
        setPos(x()+10,y());
    }
    if(ataque == 2){
        setPos(x(),y()-10);
    }
    if(ataque == 3){
        setPos(x(),y()+10);
    }
}
