#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "partita.h"


struct partita{
    char *giocatore;
    int punteggio;
};

Partita createPartita(char *giocatore, int punteggio){
    Partita partita= malloc(sizeof(struct partita));
    partita->giocatore=strdup(giocatore);
    partita->punteggio=punteggio;
    return partita;
}

int getPunteggio(Partita partita){
    return partita->punteggio;
}

void stampaPartita(Partita partita){
    printf("Giocatore -> %s, punteggio -> %d\n", partita->giocatore, partita->punteggio);
}

void freePartita(Partita partita){
    free(partita->giocatore);
    free(partita);
}
