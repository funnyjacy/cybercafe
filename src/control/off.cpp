#include "include/control/off.h"
#include "include/model/Card.h"
#include <QMessageBox>
#include "include/global.h"
#include <QTableWidget> // 添加头文件（通常ui头文件已自动包含）

off::off(QWidget *parent)
    : QMainWindow(parent), ui(new Ui_off)
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

off::~off()
{
    delete ui;
}

void off::on_OK_clicked()
{
    string id = ui->ID->toPlainText().toStdString();
    string pwd = ui->pwd->text().toStdString();
    vector<card> res;
    int RES = Qlist->query_off(id, pwd, res);
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
    else if (RES == AL_OFF)
    {
        QMessageBox::information(this, "提示", "该用户已下机!");
    }
    else if (RES == NO_PWD)
    {
        QMessageBox::information(this, "提示", "密码输入错误");
    }

    if (RES == SUCCESS)
    {
        int flag = process_billing(res[0]);
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
            ui->table->setItem(i, 4, new QTableWidgetItem("已下机"));
            ui->table->item(i, 4)->setTextAlignment(Qt::AlignCenter);
            if (flag == SUCCESS)
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
int off::process_billing(card &currentCard)
{
    FILE *file = fopen("E:\\A_codes\\VS_code\\cybercafe\\src\\datas\\billings.asm", "r");
    if (file == NULL)
    {
        QMessageBox::warning(this, "错误", "无法打开账单文件！");
        return NOT_FOUND;
    }

    vector<string> otherRecords;
    char line[256];
    bool found = false;
    QDateTime currentTime = QDateTime::currentDateTime();

    while (fgets(line, sizeof(line), file))
    {
        string record(line);
        if (!record.empty() && record.back() == '\n')
            record.pop_back();

        // Split the record by '##'
        // fields存放信息组
        vector<string> fields;
        size_t pos = 0;
        string token;
        // [0]姓名##[1]卡号##[2]余额##[3]上机时间##[4]下机时间##[5]消费金额##[6]结账状态
        while ((pos = record.find("##")) != string::npos)
        {
            token = record.substr(0, pos);
            fields.push_back(token);
            record.erase(0, pos + 2);
        }
        fields.push_back(record); 

        if (fields.size() != 7)
        {
            otherRecords.push_back(string(line)); 
            continue;
        }

        if (fields[1] == currentCard.id && fields[6] == "0")
        {
            found = true;
            QDateTime time_last = QDateTime::fromString(QString::fromStdString(fields[3]), "yyyy-MM-dd hh:mm:ss");
            if (!time_last.isValid())
            {
                QMessageBox::warning(this, "错误", "账单时间格式错误！");
                otherRecords.push_back(string(line)); 
                continue;
            }

            qint64 seconds = time_last.secsTo(currentTime);
            if (seconds < 0)
            {
                QMessageBox::warning(this, "错误", "时间异常！");
                otherRecords.push_back(string(line)); 
                continue;
            }

            double cost = seconds * 0.01;
            // 更新消费金额
            fields[5] = to_string(cost);

            double balance = stod(fields[2]);
            if (balance < cost)
            {
                QMessageBox::warning(this, "提示", "余额不足，无法结账！");
                fclose(file);
                return BUGOU;
            }
            else
            {
                // 更新余额和消费状态
                fields[2] = to_string(balance - cost);
                fields[6] = "1";
                QDateTime offTime = QDateTime::currentDateTime();
                fields[4] = offTime.toString("yyyy-MM-dd hh:mm:ss").toStdString();
            }

            // 更新卡片余额
            currentCard.balance = balance - cost;
            currentCard.time_last = currentTime;
            currentCard.Status = OFF; // OFF
            currentCard.Pay = PAY_ED; // Mark as paid

            // 在链表更新卡片余额
            card *current = Qlist->head;
            while (current != NULL)
            {
                if (current->id == currentCard.id)
                {
                    current->balance = currentCard.balance;
                    current->time_last = currentCard.time_last;
                    current->Status = currentCard.Status;
                    current->Pay = currentCard.Pay;
                    break;
                }
                current = current->next;
            }

            QString message = QString("上机时长: %1秒\n费用: %2元\n剩余余额: %3元")
                                  .arg(seconds)
                                  .arg(cost, 0, 'f', 2)
                                  .arg(currentCard.balance, 0, 'f', 2);
            QMessageBox::information(this, "结账成功", message);
            // 重新组合 fields 为字符串
            string updatedRecord = fields[0];
            for (size_t i = 1; i < fields.size(); ++i)
            {
                updatedRecord += "##" + fields[i];
            }
            updatedRecord += "\n";
            otherRecords.push_back(updatedRecord);
        }
        else
        {
            otherRecords.push_back(string(line));
        }
    }

    fclose(file);

    if (!found)
    {
        QMessageBox::warning(this, "提示", "未找到匹配的账单记录！");
        return NOT_FOUND;
    }

    file = fopen("E:\\A_codes\\VS_code\\cybercafe\\src\\datas\\billings.asm", "w");
    if (file == NULL)
    {
        QMessageBox::warning(this, "错误", "无法写入账单文件！");
        return NOT_FOUND;
    }

    for (const auto &record : otherRecords)
    {
        fprintf(file, "%s", record.c_str());
    }

    fclose(file);
    return SUCCESS;
}

void off::on_NO_clicked()
{
    close();
}