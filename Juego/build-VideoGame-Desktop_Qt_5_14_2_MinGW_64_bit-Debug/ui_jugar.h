/********************************************************************************
** Form generated from reading UI file 'jugar.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JUGAR_H
#define UI_JUGAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_jugar
{
public:
    QWidget *widget;
    QFormLayout *formLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *jugar)
    {
        if (jugar->objectName().isEmpty())
            jugar->setObjectName(QString::fromUtf8("jugar"));
        jugar->resize(400, 300);
        widget = new QWidget(jugar);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(100, 110, 191, 61));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        formLayout->setWidget(0, QFormLayout::SpanningRole, pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        formLayout->setWidget(1, QFormLayout::SpanningRole, pushButton_2);


        retranslateUi(jugar);

        QMetaObject::connectSlotsByName(jugar);
    } // setupUi

    void retranslateUi(QDialog *jugar)
    {
        jugar->setWindowTitle(QCoreApplication::translate("jugar", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("jugar", "1 Jugador", nullptr));
        pushButton_2->setText(QCoreApplication::translate("jugar", "2 Jugadores", nullptr));
    } // retranslateUi

};

namespace Ui {
    class jugar: public Ui_jugar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JUGAR_H
