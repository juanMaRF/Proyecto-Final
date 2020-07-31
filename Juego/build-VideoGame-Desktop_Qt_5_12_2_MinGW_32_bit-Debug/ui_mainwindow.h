/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *Solo;
    QPushButton *Cop;
    QPushButton *pushButton_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
<<<<<<< Updated upstream
        MainWindow->resize(1722, 900);
=======
        MainWindow->resize(1562, 769);
        MainWindow->setCursor(QCursor(Qt::CrossCursor));
>>>>>>> Stashed changes
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 1121, 650));
        graphicsView->setSceneRect(QRectF(0, 0, 0, 0));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
<<<<<<< Updated upstream
        layoutWidget->setGeometry(QRect(1120, 10, 301, 221));
=======
        layoutWidget->setGeometry(QRect(1140, 0, 311, 221));
>>>>>>> Stashed changes
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Solo = new QPushButton(layoutWidget);
        Solo->setObjectName(QString::fromUtf8("Solo"));

        verticalLayout->addWidget(Solo);

        Cop = new QPushButton(layoutWidget);
        Cop->setObjectName(QString::fromUtf8("Cop"));

        verticalLayout->addWidget(Cop);

        pushButton_5 = new QPushButton(layoutWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        verticalLayout->addWidget(pushButton_5);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
<<<<<<< Updated upstream
        menubar->setGeometry(QRect(0, 0, 1722, 20));
=======
        menubar->setGeometry(QRect(0, 0, 1562, 20));
>>>>>>> Stashed changes
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        Solo->setText(QApplication::translate("MainWindow", "Un Jugador", nullptr));
        Cop->setText(QApplication::translate("MainWindow", "Dos Jugadores", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "Guardar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
