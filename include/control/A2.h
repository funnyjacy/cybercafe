#pragma once
#include "ui_A2.h"
#include <QMainWindow>
#include <QMainWindow>
#include <QCalendarWidget>

class A2 : public QMainWindow {
    Q_OBJECT
    
public:
    A2(QWidget* parent = nullptr);
    ~A2();

protected:
    bool eventFilter(QObject *obj, QEvent *event); // 添加事件过滤器

private:
    Ui_A2* ui;
    QCalendarWidget *calendarWidgetStart; // Calendar for ui->start
    QCalendarWidget *calendarWidgetEnd;   // Calendar for ui->end

private slots:
    void showStartCalendar();
    void showEndCalendar();
    void setStartDate();
    void setEndDate();
    void on_NO_clicked();
    void on_QUERY_clicked();
};