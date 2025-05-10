#include "include/control/on.h"
#include "include/model/Card.h"
#include <QMessageBox>
#include "include/global.h"
#include <QTableWidget> // 添加头文件（通常ui头文件已自动包含）
using namespace std;
on::on(QWidget *parent)
    : QMainWindow(parent), ui(new Ui_on)
{
    ui->setupUi(this);
    setFixedSize(950, 500);

    ui->table->setColumnCount(6);
    // ui->table->setRowCount(2);
    QStringList headers;
    headers << "姓名"
            << "卡号"
            << "余额"
            << "上机时间"
            << "状态"
            << "结账状态";
    ui->table->setHorizontalHeaderLabels(headers);
    ui->table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // 表头自适应宽度
}

on::~on()
{
}

void on::on_OK_clicked()
{
    string id = ui->ID->toPlainText().toStdString();
    string pwd = ui->pwd->text().toStdString();
    vector<card> res;
    int RES = Qlist->query_on(id, pwd, res);
    if (RES == EMPTY)
    {
        QMessageBox::information(this, "提示", "请输入查询信息!");
    }
    else if (RES == LONG)
    {
        QMessageBox::information(this, "提示", "卡号不合法");
    }
    else if (RES == NOT_FOUND)
    {
        QMessageBox::information(this, "提示", "没有找到哦!");
    }
    else if (RES == AL_ON)
    {
        QMessageBox::information(this, "提示", "该用户已上机!");
    }
    else if (RES == NO_PWD)
    {
        QMessageBox::information(this, "提示", "密码输入错误");
    }

    if (RES == SUCCESS)
    {
        ui->table->setRowCount(res.size());
        for (int i = 0; i < res.size(); i++)
        {
            string status;
            ui->table->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(res[i].name)));
            ui->table->item(i, 0)->setTextAlignment(Qt::AlignCenter);
            ui->table->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(res[i].id)));
            ui->table->item(i, 1)->setTextAlignment(Qt::AlignCenter);
            ui->table->setItem(i, 2, new QTableWidgetItem(QString::number(res[i].balance, 'f', 2)));
            ui->table->item(i, 2)->setTextAlignment(Qt::AlignCenter);
            QString dt = res[i].time_last.toString("yyyy-MM-dd hh:mm:ss");
            ui->table->setItem(i, 3, new QTableWidgetItem(dt));
            ui->table->item(i, 3)->setTextAlignment(Qt::AlignCenter);
            ui->table->setItem(i, 4, new QTableWidgetItem("上机中"));
            ui->table->item(i, 4)->setTextAlignment(Qt::AlignCenter);
            if (res[i].Pay == PAY_ED)
            {
                ui->table->setItem(i, 5, new QTableWidgetItem("已结账"));
                ui->table->item(i, 5)->setTextAlignment(Qt::AlignCenter);
            }
            else
            {
                ui->table->setItem(i, 5, new QTableWidgetItem("未结账"));
                ui->table->item(i, 5)->setTextAlignment(Qt::AlignCenter);
            }
        }
    }
    delete ui;
}
void on::on_NO_clicked()
{
    close();
}