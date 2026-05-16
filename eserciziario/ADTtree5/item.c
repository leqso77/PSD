#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "item.h"


struct item{
    int valore;
};

Item createItem(int valore){
    Item item=malloc(sizeof(struct item));
    item->valore=valore;
    return item;
}

int getValore(Item item){
    return item->valore;
}

void printItem(Item item){
    printf("%d ", item->valore);
}

void freeItem(Item item){
    free(item);
}
