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
    // Clear the table before populating
    ui->table->clearContents();

    // Open the billings.asm file
    QFile file("E:/A_codes/VS_code/cmake_test/src/datas/billings.asm");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "Error", "Cannot open billings.asm file!");
        return;
    }

    // Data structures to store totals and names per month
    std::vector<double> monthlyTotals(12, 0.0);      // Sum of used_amount per month
    std::vector<std::set<QString>> monthlyNames(12); // Unique names per month

    QTextStream in(&file);
    in.setCodec("UTF-8");
    while (!in.atEnd())
    {
        QString line = in.readLine().trimmed();
        qDebug() << "Read line:" << line;
        if (line.isEmpty())
            continue;

        // Split the line by '##'
        QStringList fields = line.split("##");
        if (fields.size() != 7)
        {
            qDebug() << "Skipping malformed line:" << line;
            continue;
        }

        // Parse fields
        QString name = fields[0];
        QString startTime = fields[3];
        double usedAmount = fields[5].toDouble();

        // Extract month from startTime (yyyy-MM-dd hh:mm:ss)
        QDateTime dateTime = QDateTime::fromString(startTime, "yyyy-MM-dd hh:mm:ss");
        if (!dateTime.isValid())
        {
            qDebug() << "Invalid date in line:" << line;
            continue;
        }
        int month = dateTime.date().month() - 1; // 0-based index for months

        // Update totals and names
        monthlyTotals[month] += usedAmount;
        monthlyNames[month].insert(name);
    }
    file.close();

    // Populate the table
    for (int month = 0; month < 12; ++month)
    {
        // Row 0: Total amount
        if (monthlyTotals[month] > 0.0)
        {
            ui->table->setItem(0, month, new QTableWidgetItem(QString::number(monthlyTotals[month], 'f', 2)));
        }
        else
        {
            ui->table->setItem(0, month, new QTableWidgetItem("-"));
        }

        // Row 1: Names
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
