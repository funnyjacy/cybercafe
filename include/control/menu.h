#pragma once
#include "ui_menu.h"
#include <QMainWindow>

#include "add.h" // add 类的头文件
#include "query.h"
#include "on.h"
#include "off.h"
#include "charge.h"
#include "refund.h"
#include "logout.h"
#include "analyze.h"

class menu : public QMainWindow
{
    Q_OBJECT

public:
    menu(QWidget *parent = nullptr);
    ~menu();

    // public:
    //     add *addWindow = nullptr; // 保存 add 窗口指针

private slots:
    void on_Qadd_clicked(); // 槽函数声明
    void on_Qquery_clicked();
    void on_Qon_clicked();
    void on_Qoff_clicked();
    void on_Qcharge_clicked();
    void on_Qrefund_clicked();
    void on_Qlogout_clicked();
    void on_Qanalyze_clicked();
private:
    Ui_menu *ui;
};