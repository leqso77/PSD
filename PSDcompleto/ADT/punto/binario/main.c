#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"
#include "item.h"

int main(){
    Stack s=createStack();
    int decimal;

    printf("insert a decimal number: ");
    scanf("%d", &decimal);

    int temp=decimal;

    if (temp==0){
        push(&s, 0);
    }

    while (temp>0){
        int resto=temp%2;
        push(&s, resto);
        temp/=2;
    }

    printf("the binary representation of %d is: ", decimal);
    while (!isempty(s)){
        Item bit=pop(&s);
        printItem(bit);
    }
    printf("\n\n");

    freeStack(&s);
    return 0;
}