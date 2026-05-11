#include <stdio.h>
#include <stdlib.h>
#include "item.h" 
#include "stack.h"

struct Stack{
    Item info;
    struct Stack* next;
};

Stack createStack(){
    return NULL;
}

void push(Stack *s, Item item){
    Stack newNode=(Stack)malloc(sizeof(struct Stack));
    newNode->info=item;
    newNode->next=*s;
    *s=newNode;
}

Item pop(Stack *s){
    if (isempty(*s)){
        Item emptyItem;
        return emptyItem;
    }
    Stack temp=*s;
    Item item= temp->info;
    *s= (*s)->next;
    free(temp);
    return item;
}

int isempty(Stack s){
    return s==NULL;
}

Item top(Stack s){
    if(isempty(s)){
        Item emptyItem;
        return emptyItem;
    }
    return s->info;
}

void freeStack(Stack *s){
    while (!isempty(*s)){
        pop(s);
    }
}
