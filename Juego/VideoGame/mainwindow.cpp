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
        scene=new QGraphicsScene;
        ui->graphicsView->setScene(scene);
        scene->setSceneRect(0,0,1060,570);
        scene->addRect(scene->sceneRect());

        o1=new obstaculos(55,50,50,50);scene->addItem(o1);lista_piedra.push_back(o1);
        o2=new obstaculos(55,100,50,50);scene->addItem(o2);lista_piedra.push_back(o2);
        o3=new obstaculos(55,150,50,50);scene->addItem(o3);lista_piedra.push_back(o3);
        o4=new obstaculos(105,50,50,50);scene->addItem(o4);lista_piedra.push_back(o4);
        o5=new obstaculos(155,50,50,50);scene->addItem(o5);lista_piedra.push_back(o5);

        o6=new obstaculos(850,50,50,50);scene->addItem(o6);lista_piedra.push_back(o6);
        o7=new obstaculos(900,50,50,50);scene->addItem(o7);lista_piedra.push_back(o7);
        o8=new obstaculos(950,50,50,50);scene->addItem(o8);lista_piedra.push_back(o8);
        o9=new obstaculos(950,100,50,50);scene->addItem(o9);lista_piedra.push_back(o9);
        o10=new obstaculos(950,150,50,50);scene->addItem(o10);lista_piedra.push_back(o10);

        o11=new obstaculos(55,350,50,50);scene->addItem(o11);lista_piedra.push_back(o11);
        o12=new obstaculos(55,400,50,50);scene->addItem(o12);lista_piedra.push_back(o12);
        o13=new obstaculos(55,450,50,50);scene->addItem(o13);lista_piedra.push_back(o13);
        o14=new obstaculos(105,450,50,50);scene->addItem(o14);lista_piedra.push_back(o14);
        o15=new obstaculos(155,450,50,50);scene->addItem(o15);lista_piedra.push_back(o15);

        o16=new obstaculos(850,450,50,50);scene->addItem(o16);lista_piedra.push_back(o16);
        o17=new obstaculos(900,450,50,50);scene->addItem(o17);lista_piedra.push_back(o17);
        o18=new obstaculos(950,450,50,50);scene->addItem(o18);lista_piedra.push_back(o18);
        o19=new obstaculos(950,400,50,50);scene->addItem(o19);lista_piedra.push_back(o19);
        o20=new obstaculos(950,350,50,50);scene->addItem(o20);lista_piedra.push_back(o20);

        o21=new obstaculos(500,250,50,50);scene->addItem(o21);lista_piedra.push_back(o21);
        o22=new obstaculos(500,200,50,50);scene->addItem(o22);lista_piedra.push_back(o22);
        o23=new obstaculos(500,300,50,50);scene->addItem(o23);lista_piedra.push_back(o23);
        o24=new obstaculos(550,250,50,50);scene->addItem(o24);lista_piedra.push_back(o24);
        o25=new obstaculos(450,250,50,50);scene->addItem(o25);lista_piedra.push_back(o25);
//        scene->setBackgroundBrush(QBrush(QImage(":/Imagenes Proyecto final/06c80d40aaf4af88df5cb9638ab738a4.jpg")));
    }
    if(x==1){

        scene=new QGraphicsScene;
        ui->graphicsView->setScene(scene);
        scene->setSceneRect(0,0,1060,570);
        scene->addRect(scene->sceneRect());

        o1=new obstaculos(55,50,50,50);scene->addItem(o1);lista_piedra.push_back(o1);
        o2=new obstaculos(915,50,50,50);scene->addItem(o2);lista_piedra.push_back(o2);
        o3=new obstaculos(915,450,50,50);scene->addItem(o3);lista_piedra.push_back(o3);
        o4=new obstaculos(55,450,50,50);scene->addItem(o4);lista_piedra.push_back(o4);
        o5=new obstaculos(460,50,50,50);scene->addItem(o5);lista_piedra.push_back(o5);
        o6=new obstaculos(460,450,50,50);scene->addItem(o6);lista_piedra.push_back(o6);
        o7=new obstaculos(460,250,50,50);scene->addItem(o7);lista_piedra.push_back(o7);
        o8=new obstaculos(55,250,50,50);scene->addItem(o8);lista_piedra.push_back(o8);
        o9=new obstaculos(915,250,50,50);scene->addItem(o9);lista_piedra.push_back(o9);
    }
}
