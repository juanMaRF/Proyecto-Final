/********************************************************************************
** Form generated from reading UI file 'registro.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRO_H
#define UI_REGISTRO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Registro
{
public:
    QLineEdit *user;
    QLineEdit *pass;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;

    void setupUi(QDialog *Registro)
    {
        if (Registro->objectName().isEmpty())
            Registro->setObjectName(QString::fromUtf8("Registro"));
        Registro->resize(400, 300);
        user = new QLineEdit(Registro);
        user->setObjectName(QString::fromUtf8("user"));
        user->setGeometry(QRect(130, 70, 113, 24));
        pass = new QLineEdit(Registro);
        pass->setObjectName(QString::fromUtf8("pass"));
        pass->setGeometry(QRect(130, 140, 113, 24));
        label = new QLabel(Registro);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 40, 131, 16));
        label_2 = new QLabel(Registro);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(130, 110, 131, 16));
        pushButton = new QPushButton(Registro);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(150, 200, 80, 25));

        retranslateUi(Registro);

        QMetaObject::connectSlotsByName(Registro);
    } // setupUi

    void retranslateUi(QDialog *Registro)
    {
        Registro->setWindowTitle(QCoreApplication::translate("Registro", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Registro", "Ingrese el usuario", nullptr));
        label_2->setText(QCoreApplication::translate("Registro", "Ingrese la clave", nullptr));
        pushButton->setText(QCoreApplication::translate("Registro", "Registrarse", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Registro: public Ui_Registro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRO_H
