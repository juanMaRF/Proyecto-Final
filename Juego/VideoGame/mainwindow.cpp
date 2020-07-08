#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::niveles()
{

    if(x==0){
        scene= new QGraphicsScene();
        ui->graphicsView->setScene(scene);
        ui->centralwidget->adjustSize();
        scene->setSceneRect(0,0,500,1500);
        scene->setBackgroundBrush(QBrush(QImage(":/Imagenes Proyecto final/06c80d40aaf4af88df5cb9638ab738a4.jpg")));
    }
    if(x==1){

    }
    if(x==2){

    }
    if(x==3){

    }
}
