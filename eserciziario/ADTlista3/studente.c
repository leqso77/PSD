#include "studente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studente{
    char *matricola;
    char *nome;
    int voto;
};

Studente newStudente(char *matricola, char *nome, int voto){
    Studente studente=malloc(sizeof(struct studente));
    studente->matricola=strdup(matricola);
    studente->nome=strdup(nome);
    studente->voto=voto;

    return studente;
}

char* getMatricola(Studente studente){
    return studente->matricola;
}

void printStudente(Studente studente){
    printf("Matricola: %s, nome: %s, voto: %d\n", studente->matricola, studente->nome, studente->voto);
}

void freeStudente(Studente studente){
    free(studente->matricola);
    free(studente->nome);
    free(studente);
}