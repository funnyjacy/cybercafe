#include "include/model/LinkedList.h"
#include "include/model/Card.h"
#include "include/control/add.h"
#include <QMessageBox>
#include "include/global.h"
#include "include/json.h"
#include <QFile>
#include <QDebug>
#include <QJsonDocument>
#include <QDateTime>
#include <QJsonArray>
#include <QJsonObject>

LinkedList::LinkedList()
{
    card *newCard = new card;
    newCard->next = NULL;
    head = newCard;
    tail = newCard;
    size = 0;
}

LinkedList::~LinkedList()
{
    save_all_fson(head, tail);
    save_all_txt(head, tail);
}
void LinkedList::init(string name, string id, string balance, string password, string time_last)
{

    card *newCard = new card;
    newCard->name = name;
    newCard->id = id;
    double Balance = stod(balance);
    newCard->balance = Balance;
    newCard->password = password;

    QString qDateTimeStr = QString::fromStdString(time_last);
    QDateTime dateTime = QDateTime::fromString(qDateTimeStr, "yyyy-MM-dd hh:mm:ss");
    newCard->time_last = dateTime;
    newCard->Status = OFF;
    newCard->next = NULL;
    // write_json(newCard);

    tail->next = newCard;
    tail = newCard;
    size++;
}
int LinkedList::add(string name, string id, string balance, string password)
{
    if (name == "" || id == "" || balance == "" || password == "")
    {
        return EMPTY;
    }

    Card *first = Qlist->head;
    while (first != NULL)
    {
        if (first->id == id || first->name == name)
        {
            return REPEAT;
        }
        first = first->next;
    }

    int num = stoi(balance);
    if (name.size() > 10 || id.size() > 7 || num < 0 || password.size() > 7)
    {
        return LONG;
    }
    else
    {
        card *newCard = new card;
        newCard->name = name;
        newCard->id = id;
        double Balance = stod(balance);
        newCard->balance = Balance;
        newCard->password = password;

        newCard->time_last = QDateTime::currentDateTime();
        newCard->Status = OFF;
        newCard->next = NULL;
        write_json(newCard);
        write_txt(newCard);
        write_dat(newCard);

        tail->next = newCard;
        tail = newCard;
        size++;

        return SUCCESS;
    }
}

// 查询节点
int LinkedList::query(string id, vector<card> &res)
{
    if (id.size() > 7)
    {
        return LONG;
    }

    if (id == "")
    {
        return EMPTY;
    }
    if (id != "")
    {
        card *first = Qlist->head;
        while (first != NULL)
        {
            int idx = first->id.find(id);
            if (idx != string::npos)
            {
                card res1;
                res1.id = first->id;
                res1.name = first->name;
                res1.balance = first->balance;
                res1.Status = first->Status;
                res1.time_last = first->time_last;
                res.push_back(res1);
            }
            first = first->next;
        }
    }
    if (res.size() == 0)
    {
        return NOT_FOUND;
    }
    return SUCCESS;
}

int LinkedList::getSize()
{
    return Qlist->size;
}