#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "elemento.h"

struct elemento{
    char *nome;
    int quantita;
    float prezzo;
};

Elemento createElemento(char *nome, int quantita, float prezzo){
    Elemento elemento= malloc(sizeof(struct elemento));
    elemento->nome=malloc(strlen(nome)*sizeof(char)+1);
    strcpy(elemento->nome, nome);
    elemento->quantita=quantita;
    elemento->prezzo=prezzo;
    return elemento;
}

void printElemento(Elemento elemento){
    printf("Nome: %s, Quantità: %d, Prezzo: %.2f\n", elemento->nome, elemento->quantita, elemento->prezzo);
}

float getPrezzo(Elemento elemento){
    return elemento->prezzo;
}
int cercaPerNome(Elemento elemento, char *nome){
    return strcmp(elemento->nome, nome);
}