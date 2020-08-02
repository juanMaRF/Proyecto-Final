/********************************************************************************
** Form generated from reading UI file 'inicio.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INICIO_H
#define UI_INICIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_inicio
{
public:
    QPushButton *pushButton;
    QLineEdit *user;
    QLineEdit *pass;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *inicio)
    {
        if (inicio->objectName().isEmpty())
            inicio->setObjectName(QString::fromUtf8("inicio"));
        inicio->resize(400, 300);
        pushButton = new QPushButton(inicio);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(150, 240, 80, 25));
        user = new QLineEdit(inicio);
        user->setObjectName(QString::fromUtf8("user"));
        user->setGeometry(QRect(140, 80, 113, 24));
        pass = new QLineEdit(inicio);
        pass->setObjectName(QString::fromUtf8("pass"));
        pass->setGeometry(QRect(140, 160, 113, 24));
        label = new QLabel(inicio);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(140, 50, 111, 16));
        label_2 = new QLabel(inicio);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(140, 130, 55, 16));

        retranslateUi(inicio);

        QMetaObject::connectSlotsByName(inicio);
    } // setupUi

    void retranslateUi(QDialog *inicio)
    {
        inicio->setWindowTitle(QApplication::translate("inicio", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("inicio", "Iniciar", nullptr));
        label->setText(QApplication::translate("inicio", "Usuario", nullptr));
        label_2->setText(QApplication::translate("inicio", "Clave", nullptr));
    } // retranslateUi

};

namespace Ui {
    class inicio: public Ui_inicio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INICIO_H
