#include "include/control/analyze.h"
#include "include/model/Card.h"
#include <QMessageBox>
#include "include/global.h"
#include <QTableWidget> // 添加头文件（通常ui头文件已自动包含）
#include <QDebug>
analyze::analyze(QWidget *parent)
    : QMainWindow(parent), ui(new Ui_analyze)
{
    ui->setupUi(this);

    // 初始化 QStackedWidget
    stackedWidget = new QStackedWidget(this);
    setCentralWidget(stackedWidget); // 设置为主窗口的中心部件

    // 初始化 A1.ui 页面
    pageA1 = new A1(this);

    // 初始化 A2.ui 页面
    pageA2 = new A2(this);

    // 初始化 A3.ui 页面
    pageA3 = new A3(this);

    // 将页面添加到 QStackedWidget
    stackedWidget->addWidget(pageA1);
    stackedWidget->addWidget(pageA2);
    stackedWidget->addWidget(pageA3);

    // 菜单栏设计与实现
    QMenuBar *pMenuBar = menuBar();
    QMenu *pMenuChoose = pMenuBar->addMenu(tr("选择(&F)"));

    // 创建三个菜单项
    QAction *actionQueryConsumption = new QAction(tr("消费记录查询"), this);
    QAction *actionTotalRevenue = new QAction(tr("统计营业总额"), this);
    QAction *actionMonthlyRevenue = new QAction(tr("统计月营业额"), this);

    // 添加到“选择”菜单
    pMenuChoose->addAction(actionQueryConsumption);
    pMenuChoose->addAction(actionTotalRevenue);
    pMenuChoose->addAction(actionMonthlyRevenue);

    // 连接信号和槽函数，用于页面切换
    connect(actionQueryConsumption, &QAction::triggered, this, &analyze::onQueryConsumption);
    connect(actionTotalRevenue, &QAction::triggered, this, &analyze::onTotalRevenue);
    connect(actionMonthlyRevenue, &QAction::triggered, this, &analyze::onMonthlyRevenue);

    // 默认显示 A1.ui 页面
    stackedWidget->setCurrentIndex(0);
}

analyze::~analyze()
{
    delete uiA1;
    delete uiA2;
    delete uiA3;
    delete ui;
}

void analyze::onQueryConsumption()
{
    stackedWidget->setCurrentWidget(pageA1);
    qDebug() << "切换到消费记录查询页面 (A1.ui)";
}

void analyze::onTotalRevenue()
{
    stackedWidget->setCurrentWidget(pageA2);
    qDebug() << "切换到统计营业总额页面 (A2.ui)";
}

void analyze::onMonthlyRevenue()
{
    stackedWidget->setCurrentWidget(pageA3);
    qDebug() << "切换到统计月营业额页面 (A3.ui)";
}