//#include "include/view/test1.h"
#include "include/global.h"
#include "include/model/LinkedList.h"
#include "include/control/menu.h"
#include "include/json.h"
#include <QApplication>
#pragma comment(lib, "user32.lib")

int main(int argc, char *argv[])
{
    read_json();
    extern LinkedList *Qlist;
    QApplication a(argc, argv);
    menu w;
    w.show();
    w.setWindowTitle("菜单");
    return a.exec();
}
