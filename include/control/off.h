#pragma once
#include "ui_off.h"
#include <QMainWindow>

class off : public QMainWindow
{
    Q_OBJECT

public:
    off(QWidget *parent = nullptr);
    ~off();

private:
    Ui_off *ui;

public slots:
    void on_OK_clicked(); // 槽函数声明
    void on_NO_clicked();
};