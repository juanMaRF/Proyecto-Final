#ifndef BOSS1_H
#define BOSS1_H
#include <time.h>
#include <cstdlib>
#include <vector>
#include <stdlib.h>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <QDebug>
#include "caida_libre.h"
#include "ataque_bas.h"
#include "ataque_enemy.h"

class boss_CL:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    QTimer * timer = new QTimer();
    QTimer * time = new QTimer();
    QTimer * tim = new QTimer();
    boss_CL(int x, int y, int w , int h);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);

    int getVida() const;
    void setVida(int value);

private slots:
    void ataques();
    void tipoA();
    void carga();
private:
    int vida=20,ayuda=0,ayuda1;
    int tipo,tipo2,tipo3,tipo4=0, cont=50, contro=0;
    int x1,y1,w1,h1;
    caida_libre *atack1, *atack1_5;
    ataque_enemy *atack1_lef,*atack1_up,*atack1_rig;
};

#endif // BOSS1_H
