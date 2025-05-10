/********************************************************************************
** Form generated from reading UI file 'off.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OFF_H
#define UI_OFF_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
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

class Ui_off
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QTableWidget *table;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *OK;
    QPushButton *NO;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_2;
    QTextEdit *ID;
    QSpacerItem *horizontalSpacer_6;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_3;
    QLineEdit *pwd;
    QSpacerItem *horizontalSpacer_8;

    void setupUi(QMainWindow *off)
    {
        if (off->objectName().isEmpty())
            off->setObjectName(QString::fromUtf8("off"));
        off->resize(495, 464);
        centralwidget = new QWidget(off);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(25);
        label->setFont(font);

        horizontalLayout_3->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        table = new QTableWidget(widget_2);
        table->setObjectName(QString::fromUtf8("table"));

        gridLayout->addWidget(table, 3, 0, 1, 1);

        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        OK = new QPushButton(widget_3);
        OK->setObjectName(QString::fromUtf8("OK"));
        OK->setMinimumSize(QSize(100, 50));
        OK->setMaximumSize(QSize(100, 16777215));
        QFont font1;
        font1.setPointSize(17);
        OK->setFont(font1);

        horizontalLayout_2->addWidget(OK);

        NO = new QPushButton(widget_3);
        NO->setObjectName(QString::fromUtf8("NO"));
        NO->setMinimumSize(QSize(100, 50));
        NO->setMaximumSize(QSize(70, 16777215));
        NO->setFont(font1);

        horizontalLayout_2->addWidget(NO);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        gridLayout->addWidget(widget_3, 2, 0, 1, 1);

        widget_5 = new QWidget(widget_2);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout = new QHBoxLayout(widget_5);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        label_2 = new QLabel(widget_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font2;
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        label_2->setFont(font2);

        horizontalLayout->addWidget(label_2);

        ID = new QTextEdit(widget_5);
        ID->setObjectName(QString::fromUtf8("ID"));
        ID->setMinimumSize(QSize(300, 50));
        ID->setMaximumSize(QSize(200, 40));
        QFont font3;
        font3.setPointSize(20);
        ID->setFont(font3);

        horizontalLayout->addWidget(ID);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);


        gridLayout->addWidget(widget_5, 0, 0, 1, 1);

        widget_6 = new QWidget(widget_2);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        horizontalLayout_4 = new QHBoxLayout(widget_6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        label_3 = new QLabel(widget_6);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font2);

        horizontalLayout_4->addWidget(label_3);

        pwd = new QLineEdit(widget_6);
        pwd->setObjectName(QString::fromUtf8("pwd"));
        pwd->setMinimumSize(QSize(300, 50));
        pwd->setEchoMode(QLineEdit::Password);

        horizontalLayout_4->addWidget(pwd);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);


        gridLayout->addWidget(widget_6, 1, 0, 1, 1);


        verticalLayout->addWidget(widget_2);

        off->setCentralWidget(centralwidget);

        retranslateUi(off);

        QMetaObject::connectSlotsByName(off);
    } // setupUi

    void retranslateUi(QMainWindow *off)
    {
        off->setWindowTitle(QCoreApplication::translate("off", "off", nullptr));
        label->setText(QCoreApplication::translate("off", "\344\270\213\346\234\272\345\225\246", nullptr));
        OK->setText(QCoreApplication::translate("off", "\344\270\213\346\234\272", nullptr));
        NO->setText(QCoreApplication::translate("off", "\345\217\226\346\266\210", nullptr));
        label_2->setText(QCoreApplication::translate("off", "\345\215\241\345\217\267", nullptr));
        label_3->setText(QCoreApplication::translate("off", "\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class off: public Ui_off {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OFF_H
