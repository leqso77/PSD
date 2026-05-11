#ifndef ITEM_H
#define ITEM_H

struct Canzone {
    char titolo[50];
    char artista[50];
};

typedef struct Canzone Item;

void printItem(Item item);
#endif