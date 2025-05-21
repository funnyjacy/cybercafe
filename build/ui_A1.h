/********************************************************************************
** Form generated from reading UI file 'A1.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_A1_H
#define UI_A1_H

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
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_A1
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_3;
    QTextEdit *ID;
    QSpacerItem *horizontalSpacer_8;
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

    void setupUi(QMainWindow *A1)
    {
        if (A1->objectName().isEmpty())
            A1->setObjectName(QString::fromUtf8("A1"));
        A1->resize(434, 358);
        centralwidget = new QWidget(A1);
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

        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        label_3 = new QLabel(widget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(100, 16777215));
        QFont font2;
        font2.setPointSize(20);
        label_3->setFont(font2);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_3);

        ID = new QTextEdit(widget_3);
        ID->setObjectName(QString::fromUtf8("ID"));
        ID->setMaximumSize(QSize(250, 60));
        QFont font3;
        font3.setPointSize(28);
        ID->setFont(font3);
        ID->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        ID->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_3->addWidget(ID);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);


        verticalLayout->addWidget(widget_3);

        widget_6 = new QWidget(centralwidget);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        horizontalLayout_6 = new QHBoxLayout(widget_6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_11);

        label_4 = new QLabel(widget_6);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font4;
        font4.setPointSize(11);
        label_4->setFont(font4);

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
        QFont font5;
        font5.setPointSize(15);
        QUERY->setFont(font5);

        horizontalLayout_5->addWidget(QUERY);

        NO = new QPushButton(widget_5);
        NO->setObjectName(QString::fromUtf8("NO"));
        NO->setFont(font5);

        horizontalLayout_5->addWidget(NO);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);


        verticalLayout->addWidget(widget_5);

        table = new QTableWidget(centralwidget);
        table->setObjectName(QString::fromUtf8("table"));

        verticalLayout->addWidget(table);

        A1->setCentralWidget(centralwidget);

        retranslateUi(A1);

        QMetaObject::connectSlotsByName(A1);
    } // setupUi

    void retranslateUi(QMainWindow *A1)
    {
        A1->setWindowTitle(QCoreApplication::translate("A1", "A1", nullptr));
        label->setText(QCoreApplication::translate("A1", "\346\266\210\350\264\271\350\256\260\345\275\225\346\237\245\350\257\242", nullptr));
        label_3->setText(QCoreApplication::translate("A1", "\345\215\241\345\217\267", nullptr));
        label_4->setText(QCoreApplication::translate("A1", "\351\200\211\346\213\251\346\227\266\351\227\264\346\256\265", nullptr));
        QUERY->setText(QCoreApplication::translate("A1", "\346\237\245\350\257\242", nullptr));
        NO->setText(QCoreApplication::translate("A1", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class A1: public Ui_A1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_A1_H
