#include "jugar.h"
#include "ui_jugar.h"

extern MainWindow *game;

jugar::jugar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::jugar)
{
    ui->setupUi(this);
}

jugar::~jugar()
{
    delete ui;
}

void jugar::on_pushButton_clicked()
{
    close();
    game = new MainWindow(1);
    //w=new MainWindow();
    game->show();
}

void jugar::on_pushButton_2_clicked()
{
    close();
    game = new MainWindow(2);
    game->show();
}
