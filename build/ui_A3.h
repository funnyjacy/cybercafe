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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_A3
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *QUERY;
    QPushButton *NO;
    QSpacerItem *horizontalSpacer_4;
    QTableWidget *table;

    void setupUi(QMainWindow *A3)
    {
        if (A3->objectName().isEmpty())
            A3->setObjectName(QString::fromUtf8("A3"));
        A3->resize(409, 318);
        centralwidget = new QWidget(A3);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        QFont font;
        font.setPointSize(12);
        widget->setFont(font);
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setPointSize(29);
        label->setFont(font1);

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget);

        widget_5 = new QWidget(centralwidget);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_5 = new QHBoxLayout(widget_5);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_10);

        QUERY = new QPushButton(widget_5);
        QUERY->setObjectName(QString::fromUtf8("QUERY"));
        QFont font2;
        font2.setPointSize(15);
        QUERY->setFont(font2);

        horizontalLayout_5->addWidget(QUERY);

        NO = new QPushButton(widget_5);
        NO->setObjectName(QString::fromUtf8("NO"));
        NO->setFont(font2);

        horizontalLayout_5->addWidget(NO);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);


        verticalLayout->addWidget(widget_5);

        table = new QTableWidget(centralwidget);
        table->setObjectName(QString::fromUtf8("table"));

        verticalLayout->addWidget(table);

        A3->setCentralWidget(centralwidget);

        retranslateUi(A3);

        QMetaObject::connectSlotsByName(A3);
    } // setupUi

    void retranslateUi(QMainWindow *A3)
    {
        A3->setWindowTitle(QCoreApplication::translate("A3", "A3", nullptr));
        label->setText(QCoreApplication::translate("A3", "\347\273\237\350\256\241\345\210\206\346\236\220Month", nullptr));
        QUERY->setText(QCoreApplication::translate("A3", "\345\210\206\346\236\220", nullptr));
        NO->setText(QCoreApplication::translate("A3", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class A3: public Ui_A3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_A3_H
