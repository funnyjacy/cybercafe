#ifndef CARD_H
#define CARD_H
#include <string>
#include <iostream>
#include <QDateTime>
using namespace std;

typedef struct Card
{
    string name;
    string id;
    string password;
    double balance;
    struct Card *next;

    QDateTime time_last;
    int Status; // 状态

    Card() : next(NULL){}
} card;

#endif // !CARD_H