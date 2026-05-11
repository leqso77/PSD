#ifndef STACK_H
#define STACK_H
#include "item.h"

typedef struct Stack* Stack;

Stack createStack();
void push(Stack *s, Item item);
Item pop(Stack *s);
int isempty(Stack s);
void freeStack(Stack *s);

#endif