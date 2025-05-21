#include "include/control/A3.h"

A3::A3(QWidget *parent)
    : QMainWindow(parent), ui(new Ui_A3)
{
    ui->setupUi(this);
}

A3::~A3()
{
    delete ui;
}