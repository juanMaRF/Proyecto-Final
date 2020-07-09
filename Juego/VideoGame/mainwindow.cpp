#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFocusFrame>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    time=new QTimer;
    connect(time,SIGNAL(timeout()),this,SLOT(Mover()));

   niveles(0);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::niveles(int x)
{
    if(x==0){
        scene=new QGraphicsScene;
        ui->graphicsView->setScene(scene);
        scene->setSceneRect(0,0,1075,595);
        scene->addRect(scene->sceneRect());
        scene->setBackgroundBrush(QBrush(QImage(":/Imagenes Proyecto final/WhatsApp Image 2020-07-08 at 6.48.30 PM.jpeg")));
        e1=new moob(0,0,50,50);scene->addItem(e1);enemigos.push_back(e1);

        v1=new obstaculos(-10,-50,250,50);scene->addItem(v1);lista_piedra.push_back(v1);v1->imagen(valla1);
        v2=new obstaculos(240,-50,250,50);scene->addItem(v2);lista_piedra.push_back(v2);v2->imagen(valla1);
        v3=new obstaculos(490,-50,250,50);scene->addItem(v3);lista_piedra.push_back(v3);v3->imagen(valla1);
        v4=new obstaculos(740,-50,250,50);scene->addItem(v4);lista_piedra.push_back(v4);v4->imagen(valla1);

        o1=new obstaculos(55,50,50,50);scene->addItem(o1);lista_piedra.push_back(o1);o1->imagen(piedra1);
        o2=new obstaculos(55,100,50,50);scene->addItem(o2);lista_piedra.push_back(o2);o2->imagen(piedra1);
        o3=new obstaculos(55,150,50,50);scene->addItem(o3);lista_piedra.push_back(o3);o3->imagen(piedra1);
        o4=new obstaculos(105,50,50,50);scene->addItem(o4);lista_piedra.push_back(o4);o4->imagen(piedra1);
        o5=new obstaculos(155,50,50,50);scene->addItem(o5);lista_piedra.push_back(o5);o5->imagen(piedra1);

        o6=new obstaculos(850,50,50,50);scene->addItem(o6);lista_piedra.push_back(o6);o6->imagen(piedra1);
        o7=new obstaculos(900,50,50,50);scene->addItem(o7);lista_piedra.push_back(o7);o7->imagen(piedra1);
        o8=new obstaculos(950,50,50,50);scene->addItem(o8);lista_piedra.push_back(o8);o8->imagen(piedra1);
        o9=new obstaculos(950,100,50,50);scene->addItem(o9);lista_piedra.push_back(o9);o9->imagen(piedra1);
        o10=new obstaculos(950,150,50,50);scene->addItem(o10);lista_piedra.push_back(o10);o10->imagen(piedra1);

        o11=new obstaculos(55,350,50,50);scene->addItem(o11);lista_piedra.push_back(o11);o11->imagen(piedra1);
        o12=new obstaculos(55,400,50,50);scene->addItem(o12);lista_piedra.push_back(o12);o12->imagen(piedra1);
        o13=new obstaculos(55,450,50,50);scene->addItem(o13);lista_piedra.push_back(o13);o13->imagen(piedra1);
        o14=new obstaculos(105,450,50,50);scene->addItem(o14);lista_piedra.push_back(o14);o14->imagen(piedra1);
        o15=new obstaculos(155,450,50,50);scene->addItem(o15);lista_piedra.push_back(o15);o15->imagen(piedra1);

        o16=new obstaculos(850,450,50,50);scene->addItem(o16);lista_piedra.push_back(o16);o16->imagen(piedra1);
        o17=new obstaculos(900,450,50,50);scene->addItem(o17);lista_piedra.push_back(o17);o17->imagen(piedra1);
        o18=new obstaculos(950,450,50,50);scene->addItem(o18);lista_piedra.push_back(o18);o18->imagen(piedra1);
        o19=new obstaculos(950,400,50,50);scene->addItem(o19);lista_piedra.push_back(o19);o19->imagen(piedra1);
        o20=new obstaculos(950,350,50,50);scene->addItem(o20);lista_piedra.push_back(o20);o20->imagen(piedra1);

        o21=new obstaculos(500,250,50,50);scene->addItem(o21);lista_piedra.push_back(o21);o21->imagen(piedra1);
        o22=new obstaculos(500,200,50,50);scene->addItem(o22);lista_piedra.push_back(o22);o22->imagen(piedra1);
        o23=new obstaculos(500,300,50,50);scene->addItem(o23);lista_piedra.push_back(o23);o23->imagen(piedra1);
        o24=new obstaculos(550,250,50,50);scene->addItem(o24);lista_piedra.push_back(o24);o24->imagen(piedra1);
        o25=new obstaculos(450,250,50,50);scene->addItem(o25);lista_piedra.push_back(o25);o25->imagen(piedra1);
        time->start(20);

    }
    if(x==1){

        scene=new QGraphicsScene;
        ui->graphicsView->setScene(scene);
        scene->setSceneRect(0,0,1060,570);
        scene->addRect(scene->sceneRect());
        scene->setBackgroundBrush(QBrush(QImage(":/Imagenes Proyecto final/WhatsApp Image 2020-07-08 at 6.48.30 PM.jpeg")));

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

void MainWindow::Mover()
{
    for(QList <moob*>::iterator it=enemigos.begin();it!=enemigos.end();it++){
        (*it)->actualizar_x();
    }
}
