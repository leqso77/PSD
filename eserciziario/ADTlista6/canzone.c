#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "canzone.h"

struct canzone{
    char *titolo;
    char *autore;
    int durata;
};

Canzone createCanzone(char *titolo, char *autore, int durata){
    Canzone canzone=malloc(sizeof(struct canzone));
    canzone->titolo=strdup(titolo);
    canzone->autore=strdup(autore);
    canzone->durata=durata;
    return canzone;
}

char *getTitolo(Canzone canzone){
    return canzone->titolo;
}

int getDurata(Canzone canzone){
    return canzone->durata;
}

void stampaCanzone(Canzone canzone){
    printf("%s di %s, durata: %d\n", canzone->titolo, canzone->autore, canzone->durata);
}

void freeCanzone(Canzone canzone){
    free(canzone->titolo);
    free(canzone->autore);
    free(canzone);
}