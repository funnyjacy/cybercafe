/********************************************************************************
** Form generated from reading UI file 'analyze.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANALYZE_H
#define UI_ANALYZE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_analyze
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *analyze)
    {
        if (analyze->objectName().isEmpty())
            analyze->setObjectName(QString::fromUtf8("analyze"));
        analyze->resize(800, 600);
        centralwidget = new QWidget(analyze);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        analyze->setCentralWidget(centralwidget);
        menubar = new QMenuBar(analyze);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        analyze->setMenuBar(menubar);
        statusbar = new QStatusBar(analyze);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        analyze->setStatusBar(statusbar);

        retranslateUi(analyze);

        QMetaObject::connectSlotsByName(analyze);
    } // setupUi

    void retranslateUi(QMainWindow *analyze)
    {
        analyze->setWindowTitle(QCoreApplication::translate("analyze", "analyze", nullptr));
    } // retranslateUi

};

namespace Ui {
    class analyze: public Ui_analyze {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANALYZE_H
