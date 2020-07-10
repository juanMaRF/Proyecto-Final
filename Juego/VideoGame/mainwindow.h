#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include <QWidget>
#include <QMainWindow>
#include <QGraphicsScene>
#include "obstaculos.h"
#include "player.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QGraphicsScene *scene;
    void niveles(int tipo);
    void colision();

private:
    Ui::MainWindow *ui;
    QList <obstaculos*> lista_piedra;
    obstaculos *o1,*o2,*o3,*o4,*o5,*o6,*o7,*o8,*o9,*o10,*o11,*o12,*o13,*o14,*o15,*o16,*o17,*o18,*o19,*o20,*o21,*o22,*o23,*o24,*o25;
    player *jugador;
};
#endif // MAINWINDOW_H
