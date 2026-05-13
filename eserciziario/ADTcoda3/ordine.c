#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordine.h"

struct ordine{
    int numeroOrdine;
    char *menu;
    float prezzo;
};

Ordine newOrdine(int numeroOrdine, char *menu, float prezzo){
    Ordine ordine=malloc(sizeof(struct ordine));
    ordine->numeroOrdine=numeroOrdine;
    ordine->menu=strdup(menu);
    ordine->prezzo=prezzo;
    return ordine;
}

int getNumeroOrdine(Ordine ordine){
    return ordine->numeroOrdine;
}
char *getMenu(Ordine ordine){
    return ordine->menu;
}

float getPrezzo(Ordine ordine){
    return ordine->prezzo;
}

void printOrdine(Ordine ordine){
    printf("cliente %d ha ordinato %s, prezzo: %.2f\n", ordine->numeroOrdine, ordine->menu, ordine->prezzo);
}

void freeOrdine(Ordine ordine){
    free(ordine->menu);
    free(ordine);
}