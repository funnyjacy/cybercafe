#include "include/control/query.h"
#include <string>
#include <iostream>
#include "include/global.h"
#include <QMessageBox>
using namespace std;

query::query(QWidget *parent)
    : QMainWindow(parent), ui(new Ui_query)
{
    ui->setupUi(this);
    setFixedSize(950, 500);
    ui->table->setColumnCount(5);
    ui->table->setRowCount(2);

    QStringList headers;
    headers << "姓名"
            << "卡号"
            << "状态"
            << "余额"
            << "上次使用时间";
    ui->table->setHorizontalHeaderLabels(headers);
}

query::~query()
{
    delete ui;
}

void query::on_QUERY_clicked()
{
    string name = ui->Name->toPlainText().toStdString();
    string id = ui->ID->toPlainText().toStdString();

    card res;
    int RES = Qlist->query(name, id, res);
    if (RES == EMPTY)
    {
        QMessageBox::information(this, "提示", "请输入查询信息!");
    }
    else if (RES == NOT_FOUND)
    {
        QMessageBox::information(this, "提示", "没有找到哦!");
    }

    else if (RES == SUCCESS)
    {
        string status;
        switch (res.Status)
        {
        case ON:
            status = "上机";
            break;
        case OFF:
            status = "下机";
            break;
        default:
            status = "空闲";
            break;
        }
        ui->table->setItem(0, 0, new QTableWidgetItem(QString::fromStdString(res.name)));
        ui->table->setItem(0, 1, new QTableWidgetItem(QString::fromStdString(res.id)));
        ui->table->setItem(0, 2, new QTableWidgetItem(QString::fromStdString(status)));
        ui->table->setItem(0, 3, new QTableWidgetItem(QString::number(res.balance, 'f', 2)));
        QString dt = res.time_last.toString("yyyy-MM-dd hh:mm:ss");
        ui->table->setItem(0, 4, new QTableWidgetItem(dt));
        // ui->table->setItem(0, 3, new QTableWidgetItem(RES.time_in));
        // ui->table->setItem(0, 4, new QTableWidgetItem(RES.time_out));
    }
}
void query::on_NO_clicked()
{
    this->close();
}