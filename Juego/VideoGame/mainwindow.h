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
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QFile>
#include "obstaculos.h"
#include "moob.h"

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
    bool colision(moob *cuerpo);
    void leer_lvl(int lvl_);
    void path(int x_play,int y_play,moob *enemy);



private:
    QGraphicsScene *scene;
    Ui::MainWindow *ui;
    QTimer *time;
    QList <obstaculos*> lista_piedra;
    QList <moob*> enemigos;
    obstaculos *o1,*o2,*o3,*o4,*o5,*o6,*o7,*o8,*o9,*o10,*o11,*o12,*o13,*o14,*o15,*o16,*o17,*o18,*o19,*o20,*o21,*o22,*o23,*o24,*o25,*v1,*v2,*v3,*v4,*v5,*v6,*v7,*v8,*v9,*v10;
    obstaculos *m1,*m2,*m3,*m4,*m5,*m6,*m7,*m8,*m9,*m10;
    moob *e1;
    int cant_obj=0;




private slots:
    void Mover();
};
#endif // MAINWINDOW_H
