#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    time=new QTimer;
    connect(time,SIGNAL(timeout()),this,SLOT(Mover()));
    leer_lvl();
/*   niveles(0)*/;


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
//        scene->setSceneRect(0,0,1075,595);
//        scene->addRect(scene->sceneRect());
        scene->setBackgroundBrush(QBrush(QImage(":/Imagenes Proyecto final/WhatsApp Image 2020-07-08 at 6.48.30 PM.jpeg")));
        e1=new moob();scene->addItem(e1);enemigos.push_back(e1);

//        v1=new obstaculos(-50,-100,250,50);scene->addItem(v1);lista_piedra.push_back(v1);v1->imagen(valla1);
//        v2=new obstaculos(190,-100,250,50);scene->addItem(v2);lista_piedra.push_back(v2);v2->imagen(valla1);
//        v3=new obstaculos(440,-100,250,50);scene->addItem(v3);lista_piedra.push_back(v3);v3->imagen(valla1);    //muros para los niveles
//        v4=new obstaculos(690,-100,250,50);scene->addItem(v4);lista_piedra.push_back(v4);v4->imagen(valla1);
//        v5=new obstaculos(740,-100,250,50);scene->addItem(v5);lista_piedra.push_back(v5);v5->imagen(valla1);

//        o1=new obstaculos(0,10,50,50);scene->addItem(o1);lista_piedra.push_back(o1);o1->imagen(piedra1);
//        o2=new obstaculos(0,60,50,50);scene->addItem(o2);lista_piedra.push_back(o2);o2->imagen(piedra1);
//        o3=new obstaculos(0,110,50,50);scene->addItem(o3);lista_piedra.push_back(o3);o3->imagen(piedra1);
//        o4=new obstaculos(50,10,50,50);scene->addItem(o4);lista_piedra.push_back(o4);o4->imagen(piedra1);
//        o5=new obstaculos(100,10,50,50);scene->addItem(o5);lista_piedra.push_back(o5);o5->imagen(piedra1);

//        o6=new obstaculos(800,0,50,50);scene->addItem(o6);lista_piedra.push_back(o6);o6->imagen(piedra1);
//        o7=new obstaculos(850,0,50,50);scene->addItem(o7);lista_piedra.push_back(o7);o7->imagen(piedra1);
//        o8=new obstaculos(900,0,50,50);scene->addItem(o8);lista_piedra.push_back(o8);o8->imagen(piedra1);
//        o9=new obstaculos(900,50,50,50);scene->addItem(o9);lista_piedra.push_back(o9);o9->imagen(piedra1);
//        o10=new obstaculos(900,100,50,50);scene->addItem(o10);lista_piedra.push_back(o10);o10->imagen(piedra1);

//        o11=new obstaculos(5,300,50,50);scene->addItem(o11);lista_piedra.push_back(o11);o11->imagen(piedra1);
//        o12=new obstaculos(5,350,50,50);scene->addItem(o12);lista_piedra.push_back(o12);o12->imagen(piedra1);
//        o13=new obstaculos(5,400,50,50);scene->addItem(o13);lista_piedra.push_back(o13);o13->imagen(piedra1);
//        o14=new obstaculos(55,400,50,50);scene->addItem(o14);lista_piedra.push_back(o14);o14->imagen(piedra1);
//        o15=new obstaculos(105,400,50,50);scene->addItem(o15);lista_piedra.push_back(o15);o15->imagen(piedra1);

//        o16=new obstaculos(800,400,50,50);scene->addItem(o16);lista_piedra.push_back(o16);o16->imagen(piedra1);
//        o17=new obstaculos(850,400,50,50);scene->addItem(o17);lista_piedra.push_back(o17);o17->imagen(piedra1);
//        o18=new obstaculos(900,400,50,50);scene->addItem(o18);lista_piedra.push_back(o18);o18->imagen(piedra1);
//        o19=new obstaculos(900,350,50,50);scene->addItem(o19);lista_piedra.push_back(o19);o19->imagen(piedra1);
//        o20=new obstaculos(900,300,50,50);scene->addItem(o20);lista_piedra.push_back(o20);o20->imagen(piedra1);

//        o21=new obstaculos(450,200,50,50);scene->addItem(o21);lista_piedra.push_back(o21);o21->imagen(piedra1);
//        o22=new obstaculos(450,150,50,50);scene->addItem(o22);lista_piedra.push_back(o22);o22->imagen(piedra1);
//        o23=new obstaculos(450,250,50,50);scene->addItem(o23);lista_piedra.push_back(o23);o23->imagen(piedra1);
//        o24=new obstaculos(500,200,50,50);scene->addItem(o24);lista_piedra.push_back(o24);o24->imagen(piedra1);
//        o25=new obstaculos(400,200,50,50);scene->addItem(o25);lista_piedra.push_back(o25);o25->imagen(piedra1);

//        v6=new obstaculos(-50,500,250,50);scene->addItem(v6);lista_piedra.push_back(v6);v6->imagen(valla1);
//        v7=new obstaculos(190,500,250,50);scene->addItem(v7);lista_piedra.push_back(v7);v7->imagen(valla1);     //muros para los niveles
//        v8=new obstaculos(440,500,250,50);scene->addItem(v8);lista_piedra.push_back(v8);v8->imagen(valla1);
//        v9=new obstaculos(690,500,250,50);scene->addItem(v9);lista_piedra.push_back(v9);v9->imagen(valla1);
//        v10=new obstaculos(740,500,250,50);scene->addItem(v10);lista_piedra.push_back(v10);v10->imagen(valla1);

        time->start(20);

    }
    if(x==1){

        scene=new QGraphicsScene;
        ui->graphicsView->setScene(scene);
        scene->setSceneRect(0,0,1060,570);
        scene->addRect(scene->sceneRect());
        scene->setBackgroundBrush(QBrush(QImage(":/Imagenes Proyecto final/WhatsApp Image 2020-07-08 at 6.48.30 PM.jpeg")));

//        o1=new obstaculos(55,50,50,50);scene->addItem(o1);lista_piedra.push_back(o1);
//        o2=new obstaculos(915,50,50,50);scene->addItem(o2);lista_piedra.push_back(o2);
//        o3=new obstaculos(915,450,50,50);scene->addItem(o3);lista_piedra.push_back(o3);
//        o4=new obstaculos(55,450,50,50);scene->addItem(o4);lista_piedra.push_back(o4);
//        o5=new obstaculos(460,50,50,50);scene->addItem(o5);lista_piedra.push_back(o5);
//        o6=new obstaculos(460,450,50,50);scene->addItem(o6);lista_piedra.push_back(o6);
//        o7=new obstaculos(460,250,50,50);scene->addItem(o7);lista_piedra.push_back(o7);
//        o8=new obstaculos(55,250,50,50);scene->addItem(o8);lista_piedra.push_back(o8);
//        o9=new obstaculos(915,250,50,50);scene->addItem(o9);lista_piedra.push_back(o9);
    }
}

void MainWindow::leer_lvl()
{
    scene=new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    scene->setBackgroundBrush(QBrush(QImage(":/Imagenes Proyecto final/WhatsApp Image 2020-07-08 at 6.48.30 PM.jpeg")));
    e1=new moob();scene->addItem(e1);enemigos.push_back(e1);
    QString lvl_1="E:/Desktop/Proyecto-Final/Juego/VideoGame/lvl_1.TXT";
    QFile file(lvl_1);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"Title","File not open");
    }
    QTextStream in(&file);
    QString text=in.readAll(),textura,temp,nomb;
    file.close();
    int comas=0,coordx=0,nom=0,coordy=0,w_=0,h_=0,tempint;
    for (int i=0;i<text.size();i++) {
        if(text.at(i)=="\n"){
            cant_obj+=1;
            nomb=cant_obj;
            textura=temp;
            temp.clear();
            //crear los objetos y luego agregar a la lista
            scene->addItem(new obstaculos(coordx,coordy,w_,h_,textura));
            lista_piedra.push_back(new obstaculos(coordx,coordy,w_,h_,textura));
            comas=0;

        }
        if(text.at(i)==","){
            if(comas==0){
                tempint=temp.toInt();
                coordx=tempint;
                temp.clear();
            }else if(comas==1){
                tempint=temp.toInt();
                coordy=tempint;
                temp.clear();
            }else if(comas==2){
                tempint=temp.toInt();
                w_=tempint;
                temp.clear();
            }else if(comas==3){
                tempint=temp.toInt();
                h_=tempint;
                temp.clear();
            }
            comas+=1;
            i++;
        }


        temp.append(text.at(i));
    }
    time->start(20);
}

void MainWindow::Mover()
{
    for(QList <moob*>::iterator it=enemigos.begin();it!=enemigos.end();it++){
        //(*it)->actualizar_x();
    }
}
