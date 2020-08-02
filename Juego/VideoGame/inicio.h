#ifndef INICIO_H
#define INICIO_H

#include <QDialog>

namespace Ui {
class inicio;
}

class inicio : public QDialog
{
    Q_OBJECT

public:
    explicit inicio(QWidget *parent = nullptr);
    ~inicio();
    bool iniciar(QString nom_, QString cla_);

private slots:
    void on_pushButton_clicked();

private:
    Ui::inicio *ui;
    QString nom,pass;
};

#endif // INICIO_H
