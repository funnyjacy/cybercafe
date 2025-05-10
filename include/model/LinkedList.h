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
    // 最后把链表的东西写进去
    ~LinkedList();
    // 加载本地数据
    void init(string name, string id, string balance, string password, string time_last, string status, string del, string pay);
    // 获取节点数量
    int getSize();
    // 添加节点
    int add(string name, string id, string balance, string password);
    // 查询节点
    int query(string id, vector<card> &res);
    // 上机查询
    int query_on(string id, string pwd, vector<card> &res);
    // 下机查询
    int query_off(string id, string pwd, vector<card> &res);
};

#endif // !LINKEDLIST_H