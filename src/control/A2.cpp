#include "include/control/A2.h"
#include <QHeaderView>
#include <QLineEdit>
#include <QMouseEvent>
#include <QDebug>
#include <QMessageBox>
#include <string>
using namespace std;
A2::A2(QWidget *parent)
    : QMainWindow(parent), ui(new Ui_A2)
{
    ui->setupUi(this);
    setFixedSize(900, 580);
    ui->table->setColumnCount(4);

    QStringList headers;
    headers << "姓名"
            << "卡号"
            << "个人金额"
            << "总计使用金额";
    ui->table->setHorizontalHeaderLabels(headers);
    ui->table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->start->installEventFilter(this);
    ui->end->installEventFilter(this);
    this->installEventFilter(this); // 全局事件过滤器

    calendarWidgetStart = new QCalendarWidget(this);
    calendarWidgetStart->setGeometry(QRect(10, 10, 200, 200));
    calendarWidgetStart->hide();

    calendarWidgetEnd = new QCalendarWidget(this);
    calendarWidgetEnd->setGeometry(QRect(10, 10, 200, 200));
    calendarWidgetEnd->hide();

    connect(calendarWidgetStart, &QCalendarWidget::clicked, this, &A2::setStartDate);
    connect(calendarWidgetEnd, &QCalendarWidget::clicked, this, &A2::setEndDate);
}

bool A2::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *mouseEvent = dynamic_cast<QMouseEvent *>(event);
        if (!mouseEvent)
        {
            //qWarning() << "Failed to cast event to QMouseEvent, type:" << event->type();
            return QMainWindow::eventFilter(obj, event);
        }

        if (obj == ui->start && mouseEvent->button() == Qt::LeftButton)
        {
            showStartCalendar();
            //qDebug() << "ui->start clicked, showing start calendar";
            return true;
        }

        if (obj == ui->end && mouseEvent->button() == Qt::LeftButton)
        {
            showEndCalendar();
            //qDebug() << "ui->end clicked, showing end calendar";
            return true;
        }

        if (calendarWidgetStart->isVisible() || calendarWidgetEnd->isVisible())
        {
            QPoint globalPos = mouseEvent->globalPos();
            QPoint localPos = mapTo(this, globalPos);

            if (calendarWidgetStart->isVisible() &&
                !calendarWidgetStart->geometry().contains(localPos) &&
                obj != ui->start)
            {
                calendarWidgetStart->hide();
                //qDebug() << "Clicked outside start calendar and ui->start, hiding start calendar";
            }

            if (calendarWidgetEnd->isVisible() &&
                !calendarWidgetEnd->geometry().contains(localPos) &&
                obj != ui->end)
            {
                calendarWidgetEnd->hide();
                //qDebug() << "Clicked outside end calendar and ui->end, hiding end calendar";
            }

            return true;
        }
    }

    return QMainWindow::eventFilter(obj, event);
}

void A2::showStartCalendar()
{
    calendarWidgetEnd->hide();
    QPoint pos = ui->start->mapTo(this, QPoint(0, ui->start->height()));
    calendarWidgetStart->move(pos);
    calendarWidgetStart->show();
    qDebug() << "showStartCalendar() called";
}

void A2::showEndCalendar()
{
    calendarWidgetStart->hide();
    QPoint pos = ui->end->mapTo(this, QPoint(0, ui->end->height()));
    calendarWidgetEnd->move(pos);
    calendarWidgetEnd->show();
    qDebug() << "showEndCalendar() called";
}

void A2::setStartDate()
{
    QDate date = calendarWidgetStart->selectedDate();
    QString dateStr = date.toString("yyyy-MM-dd");
    ui->start->setText(dateStr);
    calendarWidgetStart->hide();
    qDebug() << "setStartDate() called, 开始日期:" << dateStr;
}

void A2::setEndDate()
{
    QDate date = calendarWidgetEnd->selectedDate();
    QString dateStr = date.toString("yyyy-MM-dd");
    ui->end->setText(dateStr);
    calendarWidgetEnd->hide();
    qDebug() << "setEndDate() called, 结束日期" << dateStr;
}

void A2::on_NO_clicked()
{
    this->close();
}

A2::~A2()
{
    delete calendarWidgetStart;
    delete calendarWidgetEnd;
    delete ui;
}

void A2::on_QUERY_clicked()
{
    QString startDateStr = ui->start->text();
    QString endDateStr = ui->end->text();
    if (startDateStr.isEmpty() || endDateStr.isEmpty())
    {
        QMessageBox::warning(this, "错误", "请选择起始日期和结束日期");
        return;
    }

    QDate startDate = QDate::fromString(startDateStr, "yyyy-MM-dd");
    QDate endDate = QDate::fromString(endDateStr, "yyyy-MM-dd");
    if (!startDate.isValid() || !endDate.isValid())
    {
        QMessageBox::warning(this, "错误", "请输入有效的起始和结束日期（格式：yyyy-MM-dd）");
        return;
    }
    if (startDate > endDate)
    {
        QMessageBox::warning(this, "错误", "起始日期不能晚于结束日期");
        return;
    }

    QFile file("E:/A_codes/VS_code/cybercafe/src/datas/billings.asm");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "错误", "无法打开账单文件：" + file.errorString());
        return;
    }

    ui->table->setRowCount(0);

    QTextStream in(&file);
    in.setCodec("UTF-8");

    std::map<QString, std::pair<double, QList<QString>>> userStats;
    double grandTotal = 0.0; 

    while (!in.atEnd())
    {
        QString line = in.readLine();
        qDebug() << "Read line:" << line;

        QStringList fields = line.split("##", Qt::SkipEmptyParts);
        if (fields.size() != 7)
        {
            qWarning() << "Invalid record format in line:" << line << "| Expected 7 fields, got:" << fields.size();
            qDebug() << "Fields:" << fields;
            continue;
        }

        QString name = fields[0].trimmed();
        QString id = fields[1].trimmed();
        QString startTimeStr = fields[3].trimmed();
        QString endTimeStr = fields[4].trimmed();
        QString amountStr = fields[5].trimmed();

        amountStr.replace(QRegExp("[^0-9.]"), "");
        bool ok;
        double amount = amountStr.toDouble(&ok);
        if (!ok)
        {
            qWarning() << "Invalid amount in line:" << line;
            continue;
        }

        QDateTime recordStartDateTime = QDateTime::fromString(startTimeStr, "yyyy-MM-dd HH:mm:ss");
        QDateTime recordEndDateTime = QDateTime::fromString(endTimeStr, "yyyy-MM-dd HH:mm:ss");
        if (!recordStartDateTime.isValid() || !recordEndDateTime.isValid())
        {
            qWarning() << "Invalid date format in line:" << line;
            continue;
        }

        QDate recordStartDate = recordStartDateTime.date();
        QDate recordEndDate = recordEndDateTime.date();

        if (recordStartDate >= startDate && recordEndDate <= endDate)
        {
            QString userKey = name + "_" + id;
            if (userStats.find(userKey) == userStats.end())
            {
                userStats[userKey] = {0.0, QList<QString>()};
            }
            userStats[userKey].first += amount;                                
            userStats[userKey].second.append(QString::number(amount, 'f', 2)); 
            grandTotal += amount;                                            
        }
    }

    file.close();

    int row = 0;
    for (const auto &entry : userStats)
    {
        QString userKey = entry.first;
        double totalAmount = entry.second.first;
        QList<QString> amounts = entry.second.second;

        QStringList userInfo = userKey.split("_");
        QString name = userInfo[0];
        QString id = userInfo[1];

        ui->table->insertRow(row);
        ui->table->setItem(row, 0, new QTableWidgetItem(name));                                 // 姓名
        ui->table->setItem(row, 1, new QTableWidgetItem(id));                                   // 卡号
        ui->table->setItem(row, 2, new QTableWidgetItem(amounts.join(", ")));                   // 个人金额 (comma-separated)
        ui->table->setItem(row, 3, new QTableWidgetItem(QString::number(totalAmount, 'f', 2))); // 总计使用金额
        row++;
    }

    if (row > 0)
    {
        ui->table->insertRow(row);
        ui->table->setItem(row, 0, new QTableWidgetItem("总计"));
        ui->table->setItem(row, 1, new QTableWidgetItem(""));
        ui->table->setItem(row, 2, new QTableWidgetItem(""));
        ui->table->setItem(row, 3, new QTableWidgetItem(QString::number(grandTotal, 'f', 2))); // 全部人的使用金额
        qDebug() << "Loaded" << row << "users into table, grand total:" << grandTotal;
    }
    else
    {
        QMessageBox::information(this, "提示", "在选定日期范围内没有找到账单记录");
    }
}
