#include "include/control/add.h"
#include <QMessageBox> // 用于显示提示框
#include <iostream>
#include <string>
#include "include/global.h"
using namespace std;
add::add(QWidget *parent)
    : QMainWindow(parent), ui(new Ui_add)
{
    ui->setupUi(this);
}

add::~add()
{
    delete ui;
}

void add::on_OK_clicked()
{
    string name = ui->Name->toPlainText().toStdString();
    string id = ui->ID->toPlainText().toStdString();
    string balance = ui->Balance->toPlainText().toStdString();
    if (Qlist->add(name, id, balance) == SUCCESS)
    {
        // 显示提示框
        QMessageBox::information(this, "提示", "成功添加卡片", QMessageBox::Ok);

        // 关闭窗口
        this->close();
    }
    else
    {
        // QMessageBox::warning(this, "警告", "添加失败");
    }
}