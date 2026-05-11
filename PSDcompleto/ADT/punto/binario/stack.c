#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "item.h"

struct Stack{
    Item info;
    struct Stack* next;
};

Stack createStack(){
    return NULL;
}

int isempty(Stack s){
    return s==NULL;
}

void push(Stack *s, Item item){
    Stack newNode= (Stack)malloc(sizeof(struct Stack));
    newNode->info=item;
    newNode->next=*s;
    *s=newNode;
}

Item pop(Stack *s){
    if(isempty(*s)){
        return '\0';
    }
    Stack temp=*s;
    Item item= temp->info;
    *s=temp->next;
    free(temp);
    return item;
}

Item top(Stack s){
    if (isempty(s)){
        return '\0';
    }
    return s->info;
}

void freeStack(Stack *s){
    while (!isempty(*s)){
        pop(s);
    }
}
