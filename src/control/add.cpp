#include "include/control/add.h"

add::add(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui_add)
{
    ui->setupUi(this);
}

add::~add()
{
    delete ui; 
}