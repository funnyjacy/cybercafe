#pragma once
#include "ui_logout.h"
#include <QMainWindow>

class logout : public QMainWindow
{
    Q_OBJECT

public:
    logout(QWidget *parent = nullptr);
    ~logout();

private:
    Ui_logout *ui;

public slots:
    void on_OK_clicked(); // 槽函数声明
    void on_NO_clicked();
};