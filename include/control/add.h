#pragma once
#include "ui_add.h"
#include <QMainWindow>

class add : public QMainWindow {
    Q_OBJECT
    
public:
    add(QWidget* parent = nullptr);
    ~add();

public slots:
    void on_OK_clicked(); // 槽函数声明

private:
    Ui_add* ui;
};