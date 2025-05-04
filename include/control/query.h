#pragma once
#include "ui_query.h"
#include <QMainWindow>

class query : public QMainWindow {
    Q_OBJECT
    
public:
    query(QWidget* parent = nullptr);
    ~query();

public slots:
    void on_NO_clicked();
    void on_QUERY_clicked();

private:
    Ui_query* ui;
};