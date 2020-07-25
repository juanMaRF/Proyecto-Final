#include "health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    //inicializar score en 0
    health = 10;

    //draw the text
    setPlainText(QString("Health: ")+QString::number(health));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Health::decrease()
{
    health--;
    setPlainText(QString("Health: ")+QString::number(health));
}

int Health::getHealth()
{
    return health;
}

