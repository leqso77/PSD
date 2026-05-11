#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prodotto.h"


struct prodotto{
    char *nome;
    float prezzo;
};

Prodotto creaProdotto(char *nome, float prezzo){
    Prodotto prodotto = malloc(sizeof(struct prodotto));
    prodotto->nome=strdup(nome);
    prodotto->prezzo=prezzo;
    
    return prodotto;
}

float getPrezzo(Prodotto prodotto){
    return prodotto->prezzo;
}

void printProdotto(Prodotto prodotto){
    printf("prodotto: %s, prezzo %.2f euro\n", prodotto->nome, prodotto->prezzo);
}

void freeProdotto(Prodotto prodotto){
    free(prodotto->nome);
    free(prodotto);
}