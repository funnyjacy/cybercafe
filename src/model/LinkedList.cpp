#include "include/model/LinkedList.h"
#include "include/model/Card.h"
#include "include/control/add.h"
#include <QMessageBox>
#include "include/global.h"

LinkedList::LinkedList()
{
    card *newCard = new card;
    head = newCard;
    tail = newCard;
    size = 0;
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
    if (name.size() > 5 || id.size() > 7 || num < 0 || password.size() > 7)
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
        tail->next = newCard;
        tail = newCard;
        size++;

        return SUCCESS;
    }
}

// 查询节点
int LinkedList::query(string name, string id, card &res)
{
    if (name == "" && id == "") // 两个都为空
    {
        return EMPTY;
    }
    if (id != "")
    {
        card *first = Qlist->head;
        while (first != NULL)
        {
            if (first->id == id)
            {
                res.id = first->id;
                res.name = first->name;
                res.balance = first->balance;
                res.Status = first->Status;
                res.time_last = first->time_last;
                return SUCCESS;
            }
            first = first->next;
        }
        return NOT_FOUND;
    }
    if (name != "")
    {
        card *first = Qlist->head;
        while (first != NULL)
        {
            if (first->name == name)
            {
                res.id = first->id;
                res.name = first->name;
                res.balance = first->balance;
                return SUCCESS;
            }
            first = first->next;
        }
        return NOT_FOUND;
    }
}