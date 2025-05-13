#include "include/control/charge.h"
#include "include/control/off.h"
#include "include/model/Card.h"
#include <QMessageBox>
#include "include/global.h"
#include <QTableWidget> // 添加头文件（通常ui头文件已自动包含）
charge::charge(QWidget *parent)
    : QMainWindow(parent), ui(new Ui_charge)
{
    ui->setupUi(this);
    setFixedSize(900, 580);

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

charge::~charge()
{
    delete ui;
}

void charge::on_OK_clicked()
{
    string id = ui->ID->toPlainText().toStdString();
    string pwd = ui->pwd->text().toStdString();
    string money = ui->money->text().toStdString();

    vector<card> res;
    int RES = Qlist->query_charge(id, res, money);
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

    else if (RES == SUCCESS)
    {
        // 动态设置行数
        ui->table->setRowCount(res.size());
        for (int i = 0; i < res.size(); i++)
        {
            string status;
            switch (res[i].Status)
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
            ui->table->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(res[i].name)));
            ui->table->item(i, 0)->setTextAlignment(Qt::AlignCenter);
            ui->table->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(res[i].id)));
            ui->table->item(i, 1)->setTextAlignment(Qt::AlignCenter);
            ui->table->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(status)));
            ui->table->item(i, 2)->setTextAlignment(Qt::AlignCenter);
            ui->table->setItem(i, 3, new QTableWidgetItem(QString::number(res[i].balance, 'f', 2)));
            ui->table->item(i, 3)->setTextAlignment(Qt::AlignCenter);
            QString dt = res[i].time_last.toString("yyyy-MM-dd hh:mm:ss");
            ui->table->setItem(i, 4, new QTableWidgetItem(dt));
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

        // ui->table->setItem(0, 3, new QTableWidgetItem(RES.time_in));
        // ui->table->setItem(0, 4, new QTableWidgetItem(RES.time_out));
    }
}

void charge::on_NO_clicked()
{
    close();
}