#include <stdio.h>
#include "item.h"

void printItem(Item val){
    printf("%d ", val);
}

int eq(Item a, Item b){
    return a==b;
}