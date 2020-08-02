#ifndef INICIO_H
#define INICIO_H

#include <QDialog>
#include "jugar.h"

namespace Ui {
class inicio;
}

class inicio : public QDialog
{
    Q_OBJECT

public:
    //constructor de la intefaz de inicio de sesion
    explicit inicio(QWidget *parent = nullptr);
    ~inicio();
    //verifica si el usuario y la clave son correctas
    bool iniciar(QString nom_, QString cla_);

private slots:
    //llama a la funcion iniciar
    void on_pushButton_clicked();

private:
    Ui::inicio *ui;
    QString nom,pass;
    jugar * play;
};

#endif // INICIO_H
