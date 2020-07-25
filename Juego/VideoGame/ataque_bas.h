#ifndef ATAQUE_BAS_H
#define ATAQUE_BAS_H
#include <QGraphicsPixmapItem>

class ataque_Bas:public QObject, public QGraphicsPixmapItem
{
   Q_OBJECT
public:
    ataque_Bas(short nivel,short tipo,QGraphicsItem * parent=0);

    int getX1() const;
    void setX1(int value);

    int getY1() const;
    void setY1(int value);

    void muros();

private slots:
    void move();

private:
    int pos_inicial;
    short ataque,con=1,nivel1;

};

#endif // ATAQUE_BAS_H
