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
    explicit jugar(QWidget *parent = nullptr);
    ~jugar();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::jugar *ui;
    MainWindow *w;

};

#endif // JUGAR_H
