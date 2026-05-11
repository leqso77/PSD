#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prenotazione.h"

struct prenotazione{
    char *nome;
    int numeroPersone;
    char *tempo;
};

Prenotazione newPrenotazione(char *nome, int numeroPersone, char *tempo){
    Prenotazione prenotazione= malloc(sizeof(struct prenotazione));
    prenotazione->nome=strdup(nome);
    prenotazione->numeroPersone=numeroPersone;
    prenotazione->tempo=strdup(tempo);
    return prenotazione;
}

char *getNome(Prenotazione prenotazione){
    return prenotazione->nome;
}

int getNumeroPersone(Prenotazione prenotazione){
    return prenotazione->numeroPersone;
}

void printPrenotazione(Prenotazione prenotazione){
    printf("%s ha prenotato per %d persone alle ore %s\n", prenotazione->nome, prenotazione->numeroPersone, prenotazione->tempo);
}

void freePrenotazione(Prenotazione prenotazione){
    free(prenotazione->nome);
    free(prenotazione->tempo);
    free(prenotazione);
}