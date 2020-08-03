/********************************************************************************
** Form generated from reading UI file 'jugar.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
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
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *jugar)
    {
        if (jugar->objectName().isEmpty())
            jugar->setObjectName(QString::fromUtf8("jugar"));
        jugar->resize(400, 300);
        layoutWidget = new QWidget(jugar);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(100, 110, 191, 61));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        formLayout->setWidget(0, QFormLayout::SpanningRole, pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        formLayout->setWidget(1, QFormLayout::SpanningRole, pushButton_2);

        pushButton_3 = new QPushButton(jugar);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(100, 180, 191, 25));

        retranslateUi(jugar);

        QMetaObject::connectSlotsByName(jugar);
    } // setupUi

    void retranslateUi(QDialog *jugar)
    {
        jugar->setWindowTitle(QApplication::translate("jugar", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("jugar", "1 Jugador", nullptr));
        pushButton_2->setText(QApplication::translate("jugar", "2 Jugadores", nullptr));
        pushButton_3->setText(QApplication::translate("jugar", "Cargar Partida", nullptr));
    } // retranslateUi

};

namespace Ui {
    class jugar: public Ui_jugar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JUGAR_H
