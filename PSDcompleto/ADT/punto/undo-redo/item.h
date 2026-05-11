#ifndef ITEM_H
#define ITEM_H

struct Azione{
    char descrizione[100];
};

typedef struct Azione Item;

void printItem(Item item);

#endif