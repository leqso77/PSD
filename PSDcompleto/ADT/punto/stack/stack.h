#ifndef STACK_H
#define STACK_H
#include "item.h"
#define max 100

void initStack();
int isEmpty();
void push(Item val);
Item pop();
#endif