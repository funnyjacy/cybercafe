#include "include/control/A3.h"
#include <QHeaderView>
#include <QLineEdit>
#include <QMouseEvent>
#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <string>
#include <vector>
#include <map>
#include <set>
A3::A3(QWidget *parent)
    : QMainWindow(parent), ui(new Ui_A3)
{
    ui->setupUi(this);
    setFixedSize(900, 580);
    ui->table->setColumnCount(12);
    ui->table->setRowCount(2);

    QStringList headers;
    headers << "January"
            << "February"
            << "March"
            << "April"
            << "May"
            << "June"
            << "July"
            << "August"
            << "September"
            << "October"
            << "November"
            << "December";
    ui->table->setHorizontalHeaderLabels(headers);
}

void A3::on_NO_clicked()
{
    this->close();
}

A3::~A3()
{
    delete ui;
}

void A3::on_QUERY_clicked()
{
    ui->table->clearContents();

    QFile file("E:/A_codes/VS_code/cybercafe/src/datas/billings.asm");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "Error", "Cannot open billings.asm file!");
        return;
    }

    std::vector<double> monthlyTotals(12, 0.0);      
    std::vector<std::set<QString>> monthlyNames(12); 

    QTextStream in(&file);
    in.setCodec("UTF-8");
    while (!in.atEnd())
    {
        QString line = in.readLine().trimmed();
        qDebug() << "读取到信息：" << line;
        if (line.isEmpty())
            continue;

        QStringList fields = line.split("##");
        if (fields.size() != 7)
        {
            qDebug() << "数据格式不对" << line;
            continue;
        }

        QString name = fields[0];
        QString startTime = fields[3];
        double usedAmount = fields[5].toDouble();

        QDateTime dateTime = QDateTime::fromString(startTime, "yyyy-MM-dd hh:mm:ss");
        if (!dateTime.isValid())
        {
            qDebug() << "不合理数据" << line;
            continue;
        }
        int month = dateTime.date().month() - 1; 

        monthlyTotals[month] += usedAmount;
        monthlyNames[month].insert(name);
    }
    file.close();

    for (int month = 0; month < 12; ++month)
    {
        if (monthlyTotals[month] > 0.0)
        {
            ui->table->setItem(0, month, new QTableWidgetItem(QString::number(monthlyTotals[month], 'f', 2)));
        }
        else
        {
            ui->table->setItem(0, month, new QTableWidgetItem("-"));
        }

        if (!monthlyNames[month].empty())
        {
            QString names = QStringList(monthlyNames[month].begin(), monthlyNames[month].end()).join(", ");
            ui->table->setItem(1, month, new QTableWidgetItem(names));
        }
        else
        {
            ui->table->setItem(1, month, new QTableWidgetItem("-"));
        }
    }
}
