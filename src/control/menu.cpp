#include "include/control/menu.h"

menu::menu(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui_menu)
{
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui; 
}