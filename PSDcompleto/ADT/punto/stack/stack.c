#include <stdio.h>
#include "stack.h"

static Item stack[max];
static int top=0;

void initStack(){
    top=0;
}

int isEmpty(){
    return top==0;
}

void push(Item val){
    if (top==max){
        printf("Stack overflow\n");
        return;
    }
    stack[top++]=val;
}   

Item pop(){
    if (isEmpty()){
        printf("Stack underflow\n");
        return -1;
    }
    return stack[--top];
}


