#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "item.h"
#include "stack.h"


struct Stack{
    Item info;
    Item min;
    struct Stack* next;
};

Stack createStack(){
    return NULL;
}

void push(Stack *s, Item item){
    Stack newNode= (Stack)malloc(sizeof(struct Stack));
    newNode->info=item;
    newNode->next=*s;

    if(isempty(*s)){
        newNode->min=item;
    } else {
        if (item < (*s)->min){
            newNode->min=item;
        }
        else{
            newNode->min=(*s)->min;
        }
    }
    *s=newNode;
}

int isempty(Stack s){
    return s==NULL;
}

Item pop(Stack *s){
    if (isempty(*s)){
        return '\0';
    }
    Stack temp=*s;
    Item item= temp->info;
    *s= (*s)->next;
    free(temp);
    return item;
}

void freeStack(Stack *s){
    while (!isempty(*s)){
        pop(s);
    }
}

Item getMin(Stack s){
    if (isempty(s)){
        return '\0';
    }
    return s->min;
}