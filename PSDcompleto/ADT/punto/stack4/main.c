#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "item.h"
#include "stack.h"

int main(){
    Stack s= createStack();

    char espressione[]= "3 4 + 2 *";
    int lunghezza = strlen(espressione);

    for (int i=0; i<lunghezza; i++){
        char c= espressione[i];

    if (c==' ') continue;
    
    if (isdigit(c)){
        int numero= c- '0';
        push(&s, numero);
        printf("Pushed: %d\n", numero);
    } 
    else if (c== '+'){
        int dx=pop(&s);
        printf("Popped: %d\n", dx);
        int sx=pop(&s);
        printf("Popped: %d\n", sx);
        int risultato;

        risultato=sx+dx;
        push(&s, risultato);
        printf("Pushed: %d\n", risultato);
    }
    else if (c== '-'){
        int dx=pop(&s);
        printf("Popped: %d\n", dx);
        int sx=pop(&s);
        printf("Popped: %d\n", sx);
        int risultato;

        risultato= sx-dx;
        push(&s, risultato);
        printf("Pushed: %d\n", risultato);
    }
    else  if(c=='*'){
        int dx=pop(&s);
        printf("Popped: %d\n", dx);
        int sx=pop(&s);
        printf("Popped: %d\n", sx);
        int risultato;

        risultato = sx*dx;
        push(&s, risultato);
        printf("Pushed: %d\n", risultato);
    }
    }
    int risultatoFinale= pop(&s);
    printf("Risultato finale: %d\n", risultatoFinale);

    return 0;
}