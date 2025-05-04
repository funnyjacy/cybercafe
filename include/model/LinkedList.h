#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Card.h"

class LinkedList
{
private:
    int size;

public:
    card *head;
    card *tail;

public:
    // 初始化头尾节点
    LinkedList();
    // 获取节点数量
    int getSize();
    // 添加节点
    int add(string name, string id, string balance, string password);
    // 查询节点
    int query(string name, string id, card &res);
};

#endif // !LINKEDLIST_H