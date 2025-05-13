/********************************************************************************
** Form generated from reading UI file 'refund.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REFUND_H
#define UI_REFUND_H

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

class Ui_refund
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
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_3;
    QLineEdit *pwd;
    QSpacerItem *horizontalSpacer_8;
    QTableWidget *table;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_2;
    QTextEdit *ID;
    QSpacerItem *horizontalSpacer_6;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *OK;
    QPushButton *NO;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_9;
    QLabel *label_4;
    QLineEdit *money;
    QSpacerItem *horizontalSpacer_10;

    void setupUi(QMainWindow *refund)
    {
        if (refund->objectName().isEmpty())
            refund->setObjectName(QString::fromUtf8("refund"));
        refund->resize(428, 448);
        centralwidget = new QWidget(refund);
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
        widget_6 = new QWidget(widget_2);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        horizontalLayout_4 = new QHBoxLayout(widget_6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        label_3 = new QLabel(widget_6);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        label_3->setFont(font1);

        horizontalLayout_4->addWidget(label_3);

        pwd = new QLineEdit(widget_6);
        pwd->setObjectName(QString::fromUtf8("pwd"));
        pwd->setMinimumSize(QSize(300, 50));
        pwd->setEchoMode(QLineEdit::Password);

        horizontalLayout_4->addWidget(pwd);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);


        gridLayout->addWidget(widget_6, 1, 0, 1, 1);

        table = new QTableWidget(widget_2);
        table->setObjectName(QString::fromUtf8("table"));

        gridLayout->addWidget(table, 4, 0, 1, 1);

        widget_5 = new QWidget(widget_2);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout = new QHBoxLayout(widget_5);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        label_2 = new QLabel(widget_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        horizontalLayout->addWidget(label_2);

        ID = new QTextEdit(widget_5);
        ID->setObjectName(QString::fromUtf8("ID"));
        ID->setMinimumSize(QSize(300, 50));
        ID->setMaximumSize(QSize(200, 40));
        QFont font2;
        font2.setPointSize(20);
        ID->setFont(font2);

        horizontalLayout->addWidget(ID);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);


        gridLayout->addWidget(widget_5, 0, 0, 1, 1);

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
        QFont font3;
        font3.setPointSize(17);
        OK->setFont(font3);

        horizontalLayout_2->addWidget(OK);

        NO = new QPushButton(widget_3);
        NO->setObjectName(QString::fromUtf8("NO"));
        NO->setMinimumSize(QSize(100, 50));
        NO->setMaximumSize(QSize(70, 16777215));
        NO->setFont(font3);

        horizontalLayout_2->addWidget(NO);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        gridLayout->addWidget(widget_3, 3, 0, 1, 1);

        widget_7 = new QWidget(widget_2);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        horizontalLayout_5 = new QHBoxLayout(widget_7);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_9);

        label_4 = new QLabel(widget_7);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        horizontalLayout_5->addWidget(label_4);

        money = new QLineEdit(widget_7);
        money->setObjectName(QString::fromUtf8("money"));
        money->setMinimumSize(QSize(300, 50));
        money->setFont(font2);
        money->setEchoMode(QLineEdit::Normal);

        horizontalLayout_5->addWidget(money);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_10);


        gridLayout->addWidget(widget_7, 2, 0, 1, 1);


        verticalLayout->addWidget(widget_2);

        refund->setCentralWidget(centralwidget);

        retranslateUi(refund);

        QMetaObject::connectSlotsByName(refund);
    } // setupUi

    void retranslateUi(QMainWindow *refund)
    {
        refund->setWindowTitle(QCoreApplication::translate("refund", "refund", nullptr));
        label->setText(QCoreApplication::translate("refund", "\351\200\200\350\264\271~", nullptr));
        label_3->setText(QCoreApplication::translate("refund", "\345\257\206\347\240\201", nullptr));
        label_2->setText(QCoreApplication::translate("refund", "\345\215\241\345\217\267", nullptr));
        OK->setText(QCoreApplication::translate("refund", "\347\241\256\345\256\232", nullptr));
        NO->setText(QCoreApplication::translate("refund", "\345\217\226\346\266\210", nullptr));
        label_4->setText(QCoreApplication::translate("refund", "\351\207\221\351\242\235", nullptr));
    } // retranslateUi

};

namespace Ui {
    class refund: public Ui_refund {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REFUND_H
