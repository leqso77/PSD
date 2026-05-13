#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "documento.h"

struct documento {
    char *nomeFile;
    int numeroPagine;
};


Documento newDocumento(char *nomeFile, int numeroPagine){
    Documento documento=malloc(sizeof(struct documento));
    documento->nomeFile=strdup(nomeFile);
    documento->numeroPagine=numeroPagine;
    return documento;
}

char *getNomeFile(Documento documento){
    return documento->nomeFile;
}

int getNumeroPagine(Documento documento){
    return documento->numeroPagine;
}

void printFile(Documento documento){
    printf("Documento %s, Numero pagine %d\n", documento->nomeFile, documento->numeroPagine);
}

void freeDocumento(Documento documento){
    free(documento->nomeFile);
    free(documento);
}