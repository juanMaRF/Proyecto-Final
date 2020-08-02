#include "score.h"
#include <QFont>
#include <QDebug>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{

    score = 0;
    setPlainText(QString("Score: ")+QString::number(score));
    setDefaultTextColor(Qt::darkBlue);
    setFont(QFont("times",16));
}

void Score::increase()
{
    score++;
    qDebug()<<score;
    QString guardar = QString::number(score);
    qDebug()<<guardar;
    setPlainText(QString("Score: " + guardar));
}

int Score::getScore()
{
    return score;
}

void Score::setScore(int value)
{
    score = value;
}
