#include "include/control/A1.h"
#include <QHeaderView>
#include <QLineEdit>
#include <QMouseEvent>
#include <QDebug>
#include <QMessageBox>
#include <string>
using namespace std;

A1::A1(QWidget *parent) : QMainWindow(parent), ui(new Ui::A1)
{
    ui->setupUi(this);
    setFixedSize(900, 580);
    ui->table->setColumnCount(5);

    QStringList headers;
    headers << "姓名"
            << "卡号"
            << "使用金额"
            << "起始时间"
            << "结束时间";
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

    connect(calendarWidgetStart, &QCalendarWidget::clicked, this, &A1::setStartDate);
    connect(calendarWidgetEnd, &QCalendarWidget::clicked, this, &A1::setEndDate);
}

bool A1::eventFilter(QObject *obj, QEvent *event)
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

void A1::showStartCalendar()
{
    calendarWidgetEnd->hide();
    QPoint pos = ui->start->mapTo(this, QPoint(0, ui->start->height()));
    calendarWidgetStart->move(pos);
    calendarWidgetStart->show();
    //qDebug() << "showStartCalendar() called";
}

void A1::showEndCalendar()
{
    calendarWidgetStart->hide();
    QPoint pos = ui->end->mapTo(this, QPoint(0, ui->end->height()));
    calendarWidgetEnd->move(pos);
    calendarWidgetEnd->show();
    //qDebug() << "showEndCalendar() called";
}

void A1::setStartDate()
{
    QDate date = calendarWidgetStart->selectedDate();
    QString dateStr = date.toString("yyyy-MM-dd");
    ui->start->setText(dateStr);
    calendarWidgetStart->hide();
    //qDebug() << "setStartDate() called, date set to:" << dateStr;
}

void A1::setEndDate()
{
    QDate date = calendarWidgetEnd->selectedDate();
    QString dateStr = date.toString("yyyy-MM-dd");
    ui->end->setText(dateStr);
    calendarWidgetEnd->hide();
    //qDebug() << "setEndDate() called, date set to:" << dateStr;
}

void A1::on_NO_clicked()
{
    this->close();
}

A1::~A1()
{
    delete calendarWidgetStart;
    delete calendarWidgetEnd;
    delete ui;
}

void A1::on_QUERY_clicked()
{ 
    string ID = ui->ID->toPlainText().toStdString();
    QString startDateStr = ui->start->text();
    QString endDateStr = ui->end->text();
    if (startDateStr.isEmpty() || endDateStr.isEmpty())
    {
        QMessageBox::warning(this, "错误", "请选择起始日期和结束日期");
        return;
    }
    
    QDate startDate = QDate::fromString(startDateStr, "yyyy-MM-dd");
    QDate endDate = QDate::fromString(endDateStr, "yyyy-MM-dd");
    if (startDate > endDate) {
        QMessageBox::warning(this, "错误", "起始日期不能晚于结束日期");
        return;
    }

    QFile file("E:/A_codes/VS_code/cybercafe/src/datas/billings.asm");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "错误", "无法打开账单文件：" + file.errorString());
        return;
    }

    QTextStream in(&file);
    in.setCodec("UTF-8");
    int row = 0;
    while (!in.atEnd()) {
        QString line = in.readLine();
        string lineStr = line.toStdString();
        QStringList fields = line.split("##");
        if (fields.size() != 7) {
            //qWarning() << "Invalid record format in line:" << line;
            continue;
        }

        QString name = fields[0];
        QString id = fields[1];
        QString balance = fields[2];
        QString startTimeStr = fields[3]; // Format: yyyy-MM-dd HH:mm:ss
        QString endTimeStr = fields[4];   // Format: yyyy-MM-dd HH:mm:ss
        QString amount = fields[5];
        QString status = fields[6];

        QDate recordStartDate = QDateTime::fromString(startTimeStr, "yyyy-MM-dd HH:mm:ss").date();
        QDate recordEndDate = QDateTime::fromString(endTimeStr, "yyyy-MM-dd HH:mm:ss").date();

        if (recordStartDate >= startDate && recordEndDate <= endDate && id.toStdString() == ID) {
            ui->table->insertRow(row);
            //ui->table->setItem(row, 0, new QTableWidgetItem(QString::number(row + 1))); // 序号
            ui->table->setItem(row, 0, new QTableWidgetItem(name));                    // 姓名
            ui->table->setItem(row, 1, new QTableWidgetItem(id));                      // 卡号
            ui->table->setItem(row, 2, new QTableWidgetItem(amount));                  // 使用金额
            ui->table->setItem(row, 3, new QTableWidgetItem(startTimeStr));            // 起始时间
            ui->table->setItem(row, 4, new QTableWidgetItem(endTimeStr));              // 结束时间
            row++;
        }
    }

    file.close();
    if (row == 0) {
        QMessageBox::information(this, "提示", "在选定日期范围内没有找到账单记录");
    } else {
        qDebug() << "加载" << row << "records into table";
    }
}