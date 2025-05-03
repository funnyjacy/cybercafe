//#include "include/view/test1.h"
#include "include/control/menu.h"
#include <QApplication>
#pragma comment(lib, "user32.lib")

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    menu w;
    w.show();
    w.setWindowTitle("菜单");
    return a.exec();
}
