#include "include/control/menu.h"

menu::menu(QWidget *parent)
    : QMainWindow(parent), ui(new Ui_menu)
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

void menu::on_Qquery_clicked()
{
    // 创建 add 窗口实例
    query *queryWindow = new query(this); // 以 menu 作为父窗口
    queryWindow->show();                  // 显示 add 窗口
}

void menu::on_Qon_clicked()
{
    // 创建 上机 窗口实例
    on *onWindow = new on(this); // 以 menu 作为父窗口
    onWindow->show();            // 显示 上机 窗口
}

void menu::on_Qoff_clicked()
{
    // 创建 上机 窗口实例
    off *offWindow = new off(this); // 以 menu 作为父窗口
    offWindow->show();              // 显示 上机 窗口
}
void menu::on_Qcharge_clicked()
{
    // 创建 上机 窗口实例
    charge *chargeWindow = new charge(this); // 以 menu 作为父窗口
    chargeWindow->show();                    // 显示 上机 窗口
}