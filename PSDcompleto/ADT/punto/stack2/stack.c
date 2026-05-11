#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// Solo qui dentro sveliamo il segreto: lo Stack è una lista di nodi!
struct stack_node {
    Item info;
    struct stack_node *next;
};

// Crea uno Stack vuoto (punta a NULL)
Stack initStack() {
    return NULL;
}

// È vuoto se il puntatore è NULL
int isEmpty(Stack s) {
    return s == NULL;
}

// Push: Inserimento in testa alla lista
void push(Stack *s, Item val) {
    // 1. Creiamo la nuova "scatola" (nodo)
    struct stack_node *nuovo = malloc(sizeof(struct stack_node));
    if (nuovo == NULL) {
        printf("Errore: Memoria esaurita!\n");
        return;
    }
    
    // 2. Riempiamo la scatola con l'Item
    nuovo->info = val;
    
    // 3. Lo mettiamo in cima: il suo 'next' punta al vecchio inizio della pila
    nuovo->next = *s;
    
    // 4. Aggiorniamo la pila in modo che parta dal nuovo nodo
    *s = nuovo;
}

// Pop: Estrazione dalla testa della lista
Item pop(Stack *s) {
    if (isEmpty(*s)) {
        printf("Errore: Stack vuoto!\n");
        return -1;
    }
    
    // 1. Salviamo il nodo attualmente in cima
    struct stack_node *temp = *s;
    
    // 2. Recuperiamo il prezioso Item contenuto dentro
    Item estratto = temp->info;
    
    // 3. Facciamo scendere la cima della pila al nodo successivo
    *s = temp->next;
    
    // 4. Distruggiamo la vecchia scatola per liberare memoria!
    free(temp);
    
    return estratto;
}

// Distrugge tutto lo stack
void freeStack(Stack *s) {
    while (!isEmpty(*s)) {
        pop(s); // Sfruttiamo il pop che fa già la 'free'
    }
}