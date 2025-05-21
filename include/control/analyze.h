#pragma once
#include "ui_analyze.h"
#include <QMainWindow>
#include <QStackedWidget>
#include <QWidget>
#include <QDebug>
#include "A1.h"
#include "A2.h"
#include "A3.h"

class analyze : public QMainWindow {
    Q_OBJECT
    
public:
    analyze(QWidget* parent = nullptr);
    ~analyze();

private slots:
    void onQueryConsumption();    // 切换到 A1.ui 页面
    void onTotalRevenue();        // 切换到 A2.ui 页面
    void onMonthlyRevenue();      // 切换到 A3.ui 页面

private:
    // Ui::analyze *ui;
    QStackedWidget *stackedWidget; // 用于管理多个页面
    QMainWindow *pageA1;  // 原为QWidget*
    QMainWindow *pageA2;
    QMainWindow *pageA3;
    Ui::A1 *uiA1;                  // A1.ui 的 UI 对象
    Ui::A2 *uiA2;                  // A2.ui 的 UI 对象
    Ui::A3 *uiA3;                  // A3.ui 的 UI 对象

private:
    Ui_analyze* ui;
};