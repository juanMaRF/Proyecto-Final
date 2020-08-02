#include "jugar.h"
#include "ui_jugar.h"


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
    w=new MainWindow();
    w->show();
}
