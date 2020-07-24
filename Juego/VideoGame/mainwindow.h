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
#include "ataque_bas.h"
#include "tiropara.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void niveles(int tipo);
    QString colision(moob *cuerpo,obstaculos *que);
    void leer_lvl(int lvl_);
    void path(int x_play,int y_play,moob *enemy);
    void leer_atks(int lvl_);
    void Boss_2();
    obstaculos* colision_player();
    void keyPressEvent(QKeyEvent *event);

private:
    short tipo,nivel1;
    player *jugador;
    enemi_dis *enemy_dis,*enemy_dis2,*enemy_dis3,*enemy_dis4;
    boss_CL *Jefe1;
    QGraphicsScene *scene;
    Ui::MainWindow *ui;
    QTimer *time;
    QList <obstaculos*> lista_piedra,paredes_lateral,paredes_sup;
    QList <moob*> enemigos;
    QList <ataque_Bas*> balas;
    moob *e1,*e2,*e3,*e4;
    moob *boss1;
    int cant_obj=0;
    int turn=1;
    QList <boss*> atks;
    ataque_Bas *disparo;
    tiropara *ataque_es;


signals:
    void keyCaught(QKeyEvent *e);

private slots:
    void Mover();
    void atk_1();
    void atk_2();
};
#endif // MAINWINDOW_H
