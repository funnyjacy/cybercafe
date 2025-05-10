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
    int Del; // 是否注销
    int Pay; // 是否支付

    Card() : next(NULL) {}
} card;

#endif // !CARD_H