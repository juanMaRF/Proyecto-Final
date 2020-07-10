#ifndef ATAQUE_BAS_H
#define ATAQUE_BAS_H
#include <QGraphicsPixmapItem>

class ataque_Bas:public QObject, public QGraphicsPixmapItem
{
   Q_OBJECT
public:
    ataque_Bas(short tipo);
public slots:
    void move();
private:
    short ataque;

};

#endif // ATAQUE_BAS_H
