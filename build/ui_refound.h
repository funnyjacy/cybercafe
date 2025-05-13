/********************************************************************************
** Form generated from reading UI file 'refound.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REFOUND_H
#define UI_REFOUND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_refound
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *refound)
    {
        if (refound->objectName().isEmpty())
            refound->setObjectName(QString::fromUtf8("refound"));
        refound->resize(800, 600);
        centralwidget = new QWidget(refound);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        refound->setCentralWidget(centralwidget);
        menubar = new QMenuBar(refound);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        refound->setMenuBar(menubar);
        statusbar = new QStatusBar(refound);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        refound->setStatusBar(statusbar);

        retranslateUi(refound);

        QMetaObject::connectSlotsByName(refound);
    } // setupUi

    void retranslateUi(QMainWindow *refound)
    {
        refound->setWindowTitle(QCoreApplication::translate("refound", "refound", nullptr));
    } // retranslateUi

};

namespace Ui {
    class refound: public Ui_refound {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REFOUND_H
