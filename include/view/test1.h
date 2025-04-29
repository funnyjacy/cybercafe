#pragma once
#include "ui_test1.h"
#include <QMainWindow>

class test1 : public QMainWindow {
    Q_OBJECT
    
public:
    test1(QWidget* parent = nullptr);
    ~test1();

private:
    Ui_test1* ui;
};