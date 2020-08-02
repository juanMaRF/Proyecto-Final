#ifndef REGISTRO_H
#define REGISTRO_H

#include <QDialog>

namespace Ui {
class Registro;
}

class Registro : public QDialog
{
    Q_OBJECT

public:
    explicit Registro(QWidget *parent = nullptr);//el constructor
    ~Registro();
    void registrar(QString nombre, QString pass);//funcion para escribir en el archivo de texto
    bool verificar(QString nombre, QString pass);//la uso para ver si esta cuenta ya esta registrada

private slots:
    void on_pushButton_clicked();

private:
    Ui::Registro *ui;
    QString nombre,clave;
};

#endif // REGISTRO_H
