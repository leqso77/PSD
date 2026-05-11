#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "stack.h"

int main(){
    Stack s= createStack();

    push(&s, 5);
    printf("Minimum element in the stack: %d\n", getMin(s));
    push(&s, 3);
    printf("Minimum element in the stack: %d\n", getMin(s));
    push(&s, 7);
    printf("Minimum element in the stack: %d\n", getMin(s));
    push(&s, 2);
    printf("Minimum element in the stack: %d\n", getMin(s));

    printf("Minimum element after popping: %d\n", getMin(s));
    pop(&s);
    freeStack(&s);
    return 0;
}