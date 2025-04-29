#include "include/view/test1.h"

test1::test1(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui_test1)
{
    ui->setupUi(this);
}

test1::~test1()
{
    delete ui; 
}
