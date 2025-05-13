#pragma once
#include "ui_refund.h"
#include <QMainWindow>

class refund : public QMainWindow
{
    Q_OBJECT

public:
    refund(QWidget *parent = nullptr);
    ~refund();

private slots:
    void on_NO_clicked();
    void on_OK_clicked();

private:
    Ui_refund *ui;
};