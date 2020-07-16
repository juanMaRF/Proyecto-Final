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
#include "corazon.h"
#include "boss.h"

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
    QString colision(moob *cuerpo);
    void leer_lvl(int lvl_);
    void path(int x_play,int y_play,moob *enemy);
    void leer_ene(int lvl_,QGraphicsScene *scene);
    void Boss_1();
    void keyPressEvent(QKeyEvent *evento);



private:
    QGraphicsScene *scene;
    Ui::MainWindow *ui;
    QTimer *time;
    QList <obstaculos*> lista_piedra,paredes_lateral,paredes_sup;
    QList <moob*> enemigos;
    moob *e1,*e2,*e3,*e4;
    moob *boss1;
    int cant_obj=0;
    int turn=1;
    corazon *p1;
    boss *b1,*b2,*b3,*b4,*b5,*b6,*b7,*b8,*b9,*b10,*b11,*b12,*b13,*b14,*b15,*b16,*b17;
    QList <boss*> atks;




signals:
    void keyCaught(QKeyEvent *e);

private slots:
    void Mover();
    void on_pushButton_clicked();
    void atk_1();
    void atk_2();
};
#endif // MAINWINDOW_H
