#pragma once
#include "ui_off.h"
#include <QMainWindow>
#include "../model/Card.h"

class off : public QMainWindow
{
    Q_OBJECT

public:
    off(QWidget *parent = nullptr);
    ~off();

private:
    Ui_off *ui;

private:
    int process_billing(card &currentCard);

public slots:
    void on_OK_clicked(); // 槽函数声明
    void on_NO_clicked();
};