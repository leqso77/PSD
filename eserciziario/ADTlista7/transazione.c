#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "transazione.h"

struct transazione{
    int id;
    char *clausola;
    float importo;
};

Transazione createTransazione(int id, char *clausola, float importo){
    Transazione transazione=malloc(sizeof(struct transazione));
    transazione->id=id;
    transazione->clausola=strdup(clausola);
    transazione->importo=importo;
    return transazione;
}

int getId(Transazione transazione){
    return transazione->id;
}

float getImporto(Transazione transazione){
    return transazione->importo;
}

void printTransazione(Transazione transazione){
    printf("id Transazione: %d, clausola: %s, importo: %.2f\n", transazione->id, transazione->clausola, transazione->importo);
}

void freeTransazione(Transazione transazione){
    free(transazione->clausola);
    free(transazione);
}