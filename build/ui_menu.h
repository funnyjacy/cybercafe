/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_menu
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *Qon;
    QSpacerItem *horizontalSpacer_10;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *Qoff;
    QSpacerItem *horizontalSpacer_12;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *Qcharge;
    QSpacerItem *horizontalSpacer_6;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *Qadd;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_13;
    QPushButton *pushButton_6;
    QSpacerItem *horizontalSpacer_14;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *Qquery;
    QSpacerItem *horizontalSpacer_8;
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_17;
    QPushButton *pushButton_8;
    QSpacerItem *horizontalSpacer_18;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_15;
    QPushButton *pushButton_7;
    QSpacerItem *horizontalSpacer_16;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *menu)
    {
        if (menu->objectName().isEmpty())
            menu->setObjectName(QString::fromUtf8("menu"));
        menu->resize(304, 594);
        centralwidget = new QWidget(menu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(9, -1, -1, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(24);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(0);
        gridLayout->setContentsMargins(-1, 0, -1, 20);
        widget_7 = new QWidget(widget_2);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        horizontalLayout_7 = new QHBoxLayout(widget_7);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_9);

        Qon = new QPushButton(widget_7);
        Qon->setObjectName(QString::fromUtf8("Qon"));
        Qon->setMinimumSize(QSize(0, 50));
        QFont font1;
        font1.setPointSize(15);
        Qon->setFont(font1);

        horizontalLayout_7->addWidget(Qon);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_10);


        gridLayout->addWidget(widget_7, 2, 0, 1, 1);

        widget_8 = new QWidget(widget_2);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        horizontalLayout_8 = new QHBoxLayout(widget_8);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_11);

        Qoff = new QPushButton(widget_8);
        Qoff->setObjectName(QString::fromUtf8("Qoff"));
        Qoff->setMinimumSize(QSize(0, 50));
        Qoff->setFont(font1);
        Qoff->setIconSize(QSize(50, 50));

        horizontalLayout_8->addWidget(Qoff);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_12);


        gridLayout->addWidget(widget_8, 3, 0, 1, 1);

        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        Qcharge = new QPushButton(widget_4);
        Qcharge->setObjectName(QString::fromUtf8("Qcharge"));
        Qcharge->setMinimumSize(QSize(0, 50));
        Qcharge->setFont(font1);

        horizontalLayout_3->addWidget(Qcharge);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        gridLayout->addWidget(widget_4, 4, 0, 1, 1);

        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        Qadd = new QPushButton(widget_3);
        Qadd->setObjectName(QString::fromUtf8("Qadd"));
        Qadd->setMinimumSize(QSize(40, 50));
        Qadd->setFont(font1);
        Qadd->setAutoRepeatDelay(900);
        Qadd->setFlat(false);

        horizontalLayout_2->addWidget(Qadd);

        horizontalSpacer_3 = new QSpacerItem(60, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        gridLayout->addWidget(widget_3, 0, 0, 1, 1);

        widget_5 = new QWidget(widget_2);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_4 = new QHBoxLayout(widget_5);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_13);

        pushButton_6 = new QPushButton(widget_5);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(0, 50));
        pushButton_6->setFont(font1);

        horizontalLayout_4->addWidget(pushButton_6);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_14);


        gridLayout->addWidget(widget_5, 5, 0, 1, 1);

        widget_6 = new QWidget(widget_2);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        horizontalLayout_6 = new QHBoxLayout(widget_6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_7);

        Qquery = new QPushButton(widget_6);
        Qquery->setObjectName(QString::fromUtf8("Qquery"));
        Qquery->setMinimumSize(QSize(0, 50));
        Qquery->setFont(font1);

        horizontalLayout_6->addWidget(Qquery);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_8);


        gridLayout->addWidget(widget_6, 1, 0, 1, 1);

        widget_10 = new QWidget(widget_2);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        horizontalLayout_10 = new QHBoxLayout(widget_10);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(-1, 4, -1, -1);
        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_17);

        pushButton_8 = new QPushButton(widget_10);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setMinimumSize(QSize(0, 50));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe MDL2 Assets"));
        font2.setPointSize(15);
        pushButton_8->setFont(font2);

        horizontalLayout_10->addWidget(pushButton_8);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_18);


        gridLayout->addWidget(widget_10, 7, 0, 1, 1);

        widget_9 = new QWidget(widget_2);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        horizontalLayout_9 = new QHBoxLayout(widget_9);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(-1, 0, -1, 9);
        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_15);

        pushButton_7 = new QPushButton(widget_9);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setMinimumSize(QSize(0, 50));
        pushButton_7->setFont(font1);

        horizontalLayout_9->addWidget(pushButton_7);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_16);


        gridLayout->addWidget(widget_9, 6, 0, 1, 1);


        verticalLayout->addWidget(widget_2);

        menu->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(menu);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        menu->setStatusBar(statusbar);

        retranslateUi(menu);

        Qadd->setDefault(false);


        QMetaObject::connectSlotsByName(menu);
    } // setupUi

    void retranslateUi(QMainWindow *menu)
    {
        menu->setWindowTitle(QCoreApplication::translate("menu", "menu", nullptr));
        label->setText(QCoreApplication::translate("menu", "\347\275\221\345\220\247\350\256\241\350\264\271\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        Qon->setText(QCoreApplication::translate("menu", "\344\270\212\346\234\272", nullptr));
        Qoff->setText(QCoreApplication::translate("menu", "\344\270\213\346\234\272", nullptr));
        Qcharge->setText(QCoreApplication::translate("menu", "\345\205\205\345\200\274", nullptr));
        Qadd->setText(QCoreApplication::translate("menu", "\346\267\273\345\212\240\345\215\241", nullptr));
        pushButton_6->setText(QCoreApplication::translate("menu", "\351\200\200\350\264\271", nullptr));
        Qquery->setText(QCoreApplication::translate("menu", "\346\237\245\350\257\242\345\215\241", nullptr));
        pushButton_8->setText(QCoreApplication::translate("menu", "\346\263\250\351\224\200\345\215\241", nullptr));
        pushButton_7->setText(QCoreApplication::translate("menu", "\346\237\245\350\257\242\347\273\237\350\256\241", nullptr));
    } // retranslateUi

};

namespace Ui {
    class menu: public Ui_menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
