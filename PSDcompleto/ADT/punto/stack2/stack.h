#ifndef STACK_H
#define STACK_H
#include "item.h"

typedef struct Stack* Stack;

Stack createStack();
int isEmpty(Stack s);
void push(Stack *s, Item item);
Item pop(Stack *s);
void freeStack(Stack *s);

#endif // STACK_H