#include <stdio.h>
#include "stack.h"
#include "item.h"


int main(){
    initStack();
    push(10);
    push(20);
    push(30);

    while (!isEmpty()){
        Item val=pop();
        printItem(val);
    }
    printf("\n");
    return 0;
}