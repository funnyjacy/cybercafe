#pragma once
#include "ui_menu.h"
#include <QMainWindow>

class menu : public QMainWindow {
    Q_OBJECT
    
public:
    menu(QWidget* parent = nullptr);
    ~menu();

private:
    Ui_menu* ui;
};