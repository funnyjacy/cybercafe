#include "include/control/menu.h"

menu::menu(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui_menu)
{
    ui->setupUi(this);

    // 连接 Qadd 按钮的 clicked 信号到槽函数
    // 函数名已经自动连接connect(ui->Qadd, &QPushButton::clicked, this, &menu::on_Qadd_clicked);
}

menu::~menu()
{
    delete ui; 
}

void menu::on_Qadd_clicked()
{
    // 创建 add 窗口实例
    add *addWindow = new add(this); // 以 menu 作为父窗口
    addWindow->show();              // 显示 add 窗口
}