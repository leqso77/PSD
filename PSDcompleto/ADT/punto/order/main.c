#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "stack.h"


void stampastack1(Stack *s){
    Stack temp=createStack();
    while (!isempty(*s)){
        Item item=pop(s);
        printItem(item);
        push(&temp, item);
    }

    while (!isempty(temp)){
        Item rip=pop(&temp);
        push(s, rip);
    }
    printf("\n");   
}

void stampastack(Stack *s){
    while (!isempty(*s)){
        printItem(pop(s));
    }
    printf("\n");   
}

int main(){
    Stack s=createStack();
    Stack s1=createStack();

    push(&s, 34);
    push(&s, 3);
    push(&s, 31);
    push(&s, 98);
    push(&s, 92);
    push(&s, 23);

    stampastack1(&s);

    while (!isempty(s)){
        Item temp=pop(&s);
        
        while (!isempty(s1) && top(s1)<temp){
            Item temp1=pop(&s1);
            push(&s, temp1);
        }
        push(&s1, temp);
    }
    printf("sorted stack: ");
    stampastack(&s1);
    freeStack(&s);
    freeStack(&s1);
    return 0;
}