#pragma once
#include "ui_add.h"
#include <QMainWindow>

class add : public QMainWindow {
    Q_OBJECT
    
public:
    add(QWidget* parent = nullptr);
    ~add();

private:
    Ui_add* ui;
};