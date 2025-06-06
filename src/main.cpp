//#include "include/view/test1.h"
#include "include/global.h"
#include "include/model/LinkedList.h"
#include "include/control/menu.h"
#include "include/json.h"
#include <QApplication>
#pragma comment(lib, "user32.lib")
#include "config.h"
int main(int argc, char *argv[])
{
    read_txt();
    extern LinkedList *Qlist;
    //read_json();
    QApplication a(argc, argv);
    menu w;
    w.show();
    w.setWindowTitle("菜单");
    int result = a.exec();
    delete Qlist; // 触发析构函数，调用 save_all_json
    Qlist = nullptr;
    return result;
    // (Qlist->head, Qlist->tail);
}
