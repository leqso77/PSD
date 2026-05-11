#ifndef STACK_H
#define STACK_H
#include "item.h"

typedef struct Stack* Stack;

Stack createStack();
void push(Stack *s, Item item);
int isempty(Stack s);
Item pop(Stack *s);
Item top(Stack s);
void freeStack(Stack *s);

#endif
