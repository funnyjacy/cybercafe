#pragma once
#include "ui_on.h"
#include <QMainWindow>
#include "../model/Card.h"

class on : public QMainWindow
{
    Q_OBJECT

public:
    on(QWidget *parent = nullptr);
    ~on();

private:
    Ui_on *ui;

private:
    void write_billings(card newCard);

public slots:
    void on_OK_clicked(); // 槽函数声明
    void on_NO_clicked();
};