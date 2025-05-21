/********************************************************************************
** Form generated from reading UI file 'A2.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_A2_H
#define UI_A2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_A2
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_11;
    QLabel *label_4;
    QLineEdit *start;
    QLineEdit *end;
    QSpacerItem *horizontalSpacer_5;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *QUERY;
    QPushButton *NO;
    QSpacerItem *horizontalSpacer_4;
    QTableWidget *table;

    void setupUi(QMainWindow *A2)
    {
        if (A2->objectName().isEmpty())
            A2->setObjectName(QString::fromUtf8("A2"));
        A2->resize(423, 283);
        centralwidget = new QWidget(A2);
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

        widget_6 = new QWidget(centralwidget);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        horizontalLayout_6 = new QHBoxLayout(widget_6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_11);

        label_4 = new QLabel(widget_6);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font2;
        font2.setPointSize(11);
        label_4->setFont(font2);

        horizontalLayout_6->addWidget(label_4);

        start = new QLineEdit(widget_6);
        start->setObjectName(QString::fromUtf8("start"));

        horizontalLayout_6->addWidget(start);

        end = new QLineEdit(widget_6);
        end->setObjectName(QString::fromUtf8("end"));

        horizontalLayout_6->addWidget(end);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);


        verticalLayout->addWidget(widget_6);

        widget_5 = new QWidget(centralwidget);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_5 = new QHBoxLayout(widget_5);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_10);

        QUERY = new QPushButton(widget_5);
        QUERY->setObjectName(QString::fromUtf8("QUERY"));
        QFont font3;
        font3.setPointSize(15);
        QUERY->setFont(font3);

        horizontalLayout_5->addWidget(QUERY);

        NO = new QPushButton(widget_5);
        NO->setObjectName(QString::fromUtf8("NO"));
        NO->setFont(font3);

        horizontalLayout_5->addWidget(NO);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);


        verticalLayout->addWidget(widget_5);

        table = new QTableWidget(centralwidget);
        table->setObjectName(QString::fromUtf8("table"));

        verticalLayout->addWidget(table);

        A2->setCentralWidget(centralwidget);

        retranslateUi(A2);

        QMetaObject::connectSlotsByName(A2);
    } // setupUi

    void retranslateUi(QMainWindow *A2)
    {
        A2->setWindowTitle(QCoreApplication::translate("A2", "A2", nullptr));
        label->setText(QCoreApplication::translate("A2", "\347\273\237\350\256\241\345\210\206\346\236\220", nullptr));
        label_4->setText(QCoreApplication::translate("A2", "\351\200\211\346\213\251\346\227\266\351\227\264\346\256\265", nullptr));
        QUERY->setText(QCoreApplication::translate("A2", "\345\210\206\346\236\220", nullptr));
        NO->setText(QCoreApplication::translate("A2", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class A2: public Ui_A2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_A2_H
