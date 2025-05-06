#ifndef JSON_H
#define JSON_H
#include "./model/Card.h"

void write_json(card *new_card);
void read_json();
void write_txt(card *new_card);
void read_txt();
void write_dat(card *new_card);
void read_dat();

void save_all_fson(card *head, card *tail);
void save_all_txt(card *head, card *tail);
#endif // !JSON_H