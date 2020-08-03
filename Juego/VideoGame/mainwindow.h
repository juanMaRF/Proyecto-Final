#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsView>
#include <QTimer>
#include <QPainter>
#include <QRectF>
#include <QObject>
#include <QDebug>
#include <QWidget>
#include <QMainWindow>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QFile>
#include "obstaculos.h"
#include "moob.h"
#include <QLabel>
#include <QMovie>
#include "boss.h"
#include "enemi_dis.h"
#include "player.h"
#include "boss_CL.h"
#include "boss_jm.h"
#include "ataque_bas.h"
#include "tiropara.h"
#include "score.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(int tipo,QWidget *parent = nullptr);
    ~MainWindow();

    void cambio_mapas(int x);
    void niveles(int tipo);
    QString colision(moob *cuerpo,obstaculos *que);
    void leer_lvl(int lvl_);
    void path(int x_play,int y_play,moob *enemy);
    void leer_atks(int lvl_);
    obstaculos& colision_player();
    void rozamiento(short n);
    void keyPressEvent(QKeyEvent *event);
    QList <player *> rects;
    QList <enemi_dis*> mru;
    player *jugador,*jugador2;
    Score *puntaje;
    QTimer * timer;
private:
    short animacion;
    int multi;

    double R1=1.666,R2=2;
    int fuerzaT,ayuda;
    short tipo,nivel1,imagen=2,imagen2=2;

    enemi_dis *enemy_dis,*enemy_dis2,*enemy_dis3,*enemy_dis4;
    boss_CL *Jefe1;
    QGraphicsScene *scene= new QGraphicsScene(this);
    QGraphicsView * view = new QGraphicsView(this);
    Ui::MainWindow *ui;
    QTimer *time;
    QList <obstaculos*> lista_piedra,paredes_lateral,paredes_sup,p_boss;
    QList <moob*> enemigos;
    QList <ataque_Bas*> balas;
    moob *e1,*e2,*e3,*e4,*e5;
    obstaculos *pared1,*pared2,*pared3,*pared4;
    int cant_obj=0;
    int turn=1,direc;
    QList<slime *> lentitud;
    ataque_Bas *disparo;
    tiropara *ataque_es;
    boss_jm *gf;


signals:
    void keyCaught(QKeyEvent *e);

public slots:
    void Mover();
};

#endif // MAINWINDOW_H
