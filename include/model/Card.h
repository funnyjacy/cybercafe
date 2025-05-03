#ifndef CARD_H
#define CARD_H
#include <string>
#include <iostream>
using namespace std;

typedef struct Card{
    string name;
    string id;
    double balance;
    struct Card *next;
    // card(string name, string id, double balance)
    // : name(name), id(id), balance(balance), next(NULL){};
} card;

#endif // !CARD_H