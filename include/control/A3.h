#pragma once
#include "ui_A3.h"
#include <QMainWindow>

class A3 : public QMainWindow {
    Q_OBJECT
    
public:
    A3(QWidget* parent = nullptr);
    ~A3();

private:
    Ui_A3* ui;
};