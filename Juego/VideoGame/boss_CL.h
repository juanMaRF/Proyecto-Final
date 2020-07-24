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

class boss_CL:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    boss_CL(int x, int y, int w , int h);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
private slots:
    void ataques();
private:
    int tipo,tipo2,tipo3,tipo4, cont=50, contro=0;
    int x1,y1,w1,h1;
    caida_libre *atack1, *atack1_5;
    ataque_Bas *atack1_lef,*atack1_up,*atack1_rig;
};

#endif // BOSS1_H
