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
    string password = ui->Password->toPlainText().toStdString();

    int RES = Qlist->add(name, id, balance, password);
    if (RES == SUCCESS)
    {
        // 显示提示框
        QMessageBox::information(this, "提示", "成功添加卡片", QMessageBox::Ok);

        // 关闭窗口
        this->close();
    }
    else if (RES == EMPTY)
    {
        QMessageBox::warning(this, "警告", "输入不能为空");
    }
    else if (RES == REPEAT)
    {
        QMessageBox::warning(this, "警告", "姓名或卡号已存在");
    }
    else if (RES == LONG)
    {
        QMessageBox::warning(this, "警告", "输入超过长度或金额不合法！");
    }
}

void add::on_NO_clicked()
{
    this->close();
}