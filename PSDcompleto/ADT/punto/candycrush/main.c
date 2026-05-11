#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "item.h"
#include "stack.h"


int main(){
    Stack s= createStack();
    char parola[]= "abbaca";
    int lunghezza=strlen(parola);

    for (int i=0; i<lunghezza; i++){
        char lettera= parola[i];

        if(!isempty(s) && top(s)==lettera){
            pop(&s);
        } else {
            push(&s, lettera);
        }
    }

    Stack temp=createStack();
    while(!isempty(s)){
        push(&temp, pop(&s));
    }
    printf("Parola dopo rimozione lettere adiacenti: ");
        while(!isempty(temp)){
        printItem(pop(&temp));
    }
    freeStack(&s);
    freeStack(&temp);
    return 0; 
}
