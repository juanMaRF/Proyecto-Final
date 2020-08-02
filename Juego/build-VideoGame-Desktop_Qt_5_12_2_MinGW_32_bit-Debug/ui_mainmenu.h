/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *un_pla;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName(QString::fromUtf8("Menu"));
        Menu->resize(400, 300);
        layoutWidget = new QWidget(Menu);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(70, 100, 251, 59));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        un_pla = new QPushButton(layoutWidget);
        un_pla->setObjectName(QString::fromUtf8("un_pla"));

        verticalLayout->addWidget(un_pla);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);


        retranslateUi(Menu);

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QDialog *Menu)
    {
        Menu->setWindowTitle(QApplication::translate("Menu", "Dialog", nullptr));
        un_pla->setText(QApplication::translate("Menu", "Iniciar sesion", nullptr));
        pushButton_2->setText(QApplication::translate("Menu", "registrarse", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
