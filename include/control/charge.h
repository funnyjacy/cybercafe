#pragma once
#include "ui_charge.h"
#include <QMainWindow>

class charge : public QMainWindow
{
    Q_OBJECT

public:
    charge(QWidget *parent = nullptr);
    ~charge();

private:
    Ui_charge *ui;

public slots:
    void on_OK_clicked(); // 槽函数声明
    void on_NO_clicked();
};