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

int LinkedList::add(string name, string id, string balance)
{
    if (name == "" || id == "" || balance == "")
    {
        return EMPTY;
    }
    else
    {
        card *newCard = new card;
        newCard->name = name;
        newCard->id = id;
        double Balance = stod(balance);
        newCard->balance = Balance;

        newCard->next = NULL;
        tail->next = newCard;
        tail = newCard;
        size++;

        return SUCCESS;
    }
}
