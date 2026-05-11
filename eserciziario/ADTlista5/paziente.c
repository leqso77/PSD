#include "paziente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct paziente{
    char *nome;
    int codiceGravita;
};

Paziente createPaziente(char *nome, int codiceGravita){
    Paziente paziente= malloc(sizeof(struct paziente));
    paziente->nome=strdup(nome);
    paziente->codiceGravita=codiceGravita;

    return paziente;
}

int getCodice(Paziente paziente){
    return paziente->codiceGravita;
}

void printPaziente(Paziente paziente){
    printf("paziente: %s, codice di gravita: %d\n", paziente->nome, paziente->codiceGravita);
}

void freePaziente(Paziente paziente){
    free(paziente->nome);
    free(paziente);
}