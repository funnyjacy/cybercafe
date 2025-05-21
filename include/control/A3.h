#pragma once
#include "ui_A3.h"
#include <QMainWindow>
#include <QMainWindow>
#include <QMainWindow>
#include <QCalendarWidget>

class A3 : public QMainWindow
{
    Q_OBJECT

public:
    A3(QWidget *parent = nullptr);
    ~A3();

private:
    Ui_A3 *ui;

private slots:
    void on_NO_clicked();
    void on_QUERY_clicked();
};