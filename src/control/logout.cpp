#include "include/control/logout.h"
#include "include/control/refund.h"
#include "include/control/off.h"
#include "include/model/Card.h"
#include <QMessageBox>
#include "include/global.h"
#include <QTableWidget> // 添加头文件（通常ui头文件已自动包含）
logout::logout(QWidget *parent)
    : QMainWindow(parent), ui(new Ui_logout)
{
    ui->setupUi(this);
    setFixedSize(900, 580);

    ui->table->setColumnCount(4);
    // ui->table->setRowCount(2);
    QStringList headers;
    headers << "姓名"
            << "卡号"
            << "卡状态"
            << "注销时间";
    ui->table->setHorizontalHeaderLabels(headers);
    ui->table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // 表头自适应宽度
}

void logout::on_OK_clicked()
{
    string id = ui->ID->toPlainText().toStdString();
    string pwd = ui->pwd->text().toStdString();

    vector<card> res;
    int RES = Qlist->query(id, res, JINGQUE);
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
    { // Create a confirmation dialog
        QMessageBox confirmationDialog;
        confirmationDialog.setWindowTitle("确认注销");
        confirmationDialog.setText("确定要注销吗？");
        confirmationDialog.setIcon(QMessageBox::Question);

        // Add custom buttons
        QPushButton *thinkAgainButton = confirmationDialog.addButton("再想想", QMessageBox::RejectRole);
        QPushButton *confirmButton = confirmationDialog.addButton("确定", QMessageBox::AcceptRole);

        // Execute the dialog and check the user's choice
        confirmationDialog.exec();

        if (confirmationDialog.clickedButton() == confirmButton)
        {
            // User confirmed logout, proceed with table population
            card *current = Qlist->head;
            while (current != NULL)
            {
                if (current->id == id)
                {
                    current->Del = USE_NO;
                    break;
                }
                current = current->next;
            }
            ui->table->setRowCount(res.size());
            for (int i = 0; i < res.size(); i++)
            {
                ui->table->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(res[i].name)));
                ui->table->item(i, 0)->setTextAlignment(Qt::AlignCenter);
                ui->table->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(res[i].id)));
                ui->table->item(i, 1)->setTextAlignment(Qt::AlignCenter);
                ui->table->setItem(i, 2, new QTableWidgetItem(QString::fromStdString("已注销")));
                ui->table->item(i, 2)->setTextAlignment(Qt::AlignCenter);
                ui->table->setItem(i, 3, new QTableWidgetItem(QString::number(res[i].balance, 'f', 2)));
                ui->table->item(i, 3)->setTextAlignment(Qt::AlignCenter);
                QString dt = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
                ui->table->setItem(i, 4, new QTableWidgetItem(dt));
                // ui->table->item(i, 4)->setTextAlignment(Qt::AlignCenter); // Align time column
            }
            QMessageBox::information(this, "提示", "注销成功!");
        }
        else
        {
            QMessageBox::information(this, "提示", "注销已取消");
        }
    }
}
void logout::on_NO_clicked()
{
    close();
}
logout::~logout()
{
    delete ui;
}