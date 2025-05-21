/********************************************************************************
** Form generated from reading UI file 'A3.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_A3_H
#define UI_A3_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_A3
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *A3)
    {
        if (A3->objectName().isEmpty())
            A3->setObjectName(QString::fromUtf8("A3"));
        A3->resize(800, 600);
        centralwidget = new QWidget(A3);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        A3->setCentralWidget(centralwidget);
        menubar = new QMenuBar(A3);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        A3->setMenuBar(menubar);
        statusbar = new QStatusBar(A3);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        A3->setStatusBar(statusbar);

        retranslateUi(A3);

        QMetaObject::connectSlotsByName(A3);
    } // setupUi

    void retranslateUi(QMainWindow *A3)
    {
        A3->setWindowTitle(QCoreApplication::translate("A3", "A3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class A3: public Ui_A3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_A3_H
