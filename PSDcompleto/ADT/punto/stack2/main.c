#include <stdio.h>
#include "item.h"
#include "stack.h"

int main() {
    // Creiamo DUE pile distinte (impossibile con l'esercizio precedente!)
    Stack pilaPari = createStack();
    Stack pilaDispari = createStack();
    
    // Riempiamo la pila dei numeri pari
    push(&pilaPari, 2);
    push(&pilaPari, 4);
    push(&pilaPari, 8);
    
    // Riempiamo la pila dei numeri dispari
    push(&pilaDispari, 3);
    push(&pilaDispari, 7);
    push(&pilaDispari, 9);
    
    printf("--- Svuoto la Pila dei DISPARI ---\n");
    while (!isEmpty(pilaDispari)) {
        Item val = pop(&pilaDispari);
        printItem(val);
    }
    printf("\n");
    
    printf("--- Svuoto la Pila dei PARI ---\n");
    while (!isEmpty(pilaPari)) {
        Item val = pop(&pilaPari);
        printItem(val);
    }
    printf("\n");
    
    // Pulizia finale (sicurezza per evitare memory leak)
    freeStack(&pilaPari);
    freeStack(&pilaDispari);
    
    return 0;
}