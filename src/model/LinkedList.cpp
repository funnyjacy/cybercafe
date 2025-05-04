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
    // Step 1: Write the current linked list to the JSON file (overwriting it)
    QFile file("E:\\A_codes\\VS_code\\cmake_test\\src\\data.json");
    QJsonArray jsonArray;

    // Iterate through the linked list and populate the JSON array
    card *current = head;
    while (current != nullptr)
    {

        QJsonObject obj;
        obj.insert("name", QString::fromStdString(current->name));
        obj.insert("ID", QString::fromStdString(current->id));
        obj.insert("余额", current->balance);
        obj.insert("状态", current->Status);
        obj.insert("密码", QString::fromStdString(current->password));
        QString dt = current->time_last.toString("yyyy-MM-dd hh:mm:ss");
        obj.insert("上次使用时间", dt);

        jsonArray.append(obj);
        current = current->next;
    }

    // Write the JSON array to the file
    QJsonDocument doc(jsonArray);
    QByteArray json = doc.toJson(QJsonDocument::Indented);

    if (!file.open(QIODevice::WriteOnly))
    {
        qDebug() << "Error: Failed to open file for writing in destructor.";
    }
    else
    {
        file.write(json);
        file.close();
    }

    // Step 2: Clean up the linked list
    current = head;
    while (current != nullptr)
    {
        card *temp = current;
        current = current->next;
        delete temp;
    }

    // Step 3: Reset head, tail, and size
    head = nullptr;
    tail = nullptr;
    size = 0;
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
        write_json(newCard);

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

int LinkedList::getSize()
{
    return Qlist->size;
}