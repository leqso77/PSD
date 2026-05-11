#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "veicolo.h"

struct veicolo{
    char *targa;
    char *modello;
    float prezzoRip;
};

Veicolo newVeicolo(char *targa, char *modello, float prezzoRip){
    Veicolo veicolo=malloc(sizeof(struct veicolo));
    veicolo->targa=strdup(targa);
    veicolo->modello=strdup(modello);
    veicolo->prezzoRip=prezzoRip;
    return veicolo;
}

char *getTarga(Veicolo veicolo){
    return veicolo->targa;
}

float getPrezzoRip(Veicolo veicolo){
    return veicolo->prezzoRip;
}

void printVeicolo(Veicolo veicolo){
    printf("Veicolo-> %s, Modello-> %s, prezzo di riparazione-> %.2f", veicolo->targa, veicolo->modello, veicolo->prezzoRip);
}

void freeVeicolo(Veicolo veicolo){
    free(veicolo->targa);
    free(veicolo->modello);
    free(veicolo);
}