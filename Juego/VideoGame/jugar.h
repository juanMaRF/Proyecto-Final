#ifndef JUGAR_H
#define JUGAR_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class jugar;
}

class jugar : public QDialog
{
    Q_OBJECT

public:
    explicit jugar(QWidget *parent = nullptr); //el constructor para el single player y el multiplayer
    ~jugar();

private slots:
    void on_pushButton_clicked(); //inicia el singleplayer

private:
    Ui::jugar *ui;
    MainWindow *w;

};

#endif // JUGAR_H
