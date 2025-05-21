#pragma once
#include "ui_A1.h"
#include <QMainWindow>
#include <QCalendarWidget>

class A1 : public QMainWindow {
    Q_OBJECT
    
public:
    A1(QWidget* parent = nullptr);
    ~A1();

protected:
    bool eventFilter(QObject *obj, QEvent *event); // 添加事件过滤器

public:
    void setDate();
    void showtime();
private:
    Ui_A1* ui;
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