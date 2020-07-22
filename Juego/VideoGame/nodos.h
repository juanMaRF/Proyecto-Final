#ifndef NODOS_H
#define NODOS_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class nodos: public QGraphicsItem
{
    struct sNode{
        bool bObstacle = false;
        bool bVisited = false;
        float fGlobalGoal;
        float fLocalGoal;
        int x;
        int y;
        QVector <sNode*> vecNeighbours;
        sNode* parent;
    };
    sNode *nodes=nullptr;
    int nMapWidth=50;
    int nMapHeight=50;
public:
    nodos();
};

#endif // NODOS_H
