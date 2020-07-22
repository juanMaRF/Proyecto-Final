#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsView>
#include <windows.h>
#include <QTimer>
#include <QObject>
#include <QWidget>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "tiropara.h"
#include "ataque_bas.h"
#include "obstaculos.h"
#include "player.h"
#include "enemi_dis.h"
#include "boss1.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

//signals:
//    void keyCaught(QKeyEvent *e);

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QGraphicsScene *scene;
    void niveles(int tipo);
    bool colision();
    QList <obstaculos*> lista_piedra;

    //void keyPressEvent(QKeyEvent *event);
    obstaculos *recorrer();

private:
    short nivel1=0;
    tiropara *ataque_es;
    ataque_Bas *disparo;
    Ui::MainWindow *ui;
    int tipo=0;
    obstaculos *o1,*o2,*o3,*o4,*o5,*o6,*o7,*o8,*o9,*o10,*o11,*o12,*o13,*o14,*o15,*o16,*o17,*o18,*o19,*o20,*o21,*o22,*o23,*o24,*o25;
    player *jugador;
    enemi_dis *enemy_dis,*enemy_dis2,*enemy_dis3,*enemy_dis4;
    boss1 *B1;
};
#endif // MAINWINDOW_H
