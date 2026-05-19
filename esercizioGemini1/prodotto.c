#include <stdlib.h>
#include <string.h>
#include "prodotto.h"

struct prodotto {
	char *nome;
	char *categoria;
	float prezzo;
    int sconto;
};

Prodotto initProdotto(char* nome, char* categoria, float prezzo){
	Prodotto p = malloc(sizeof(struct prodotto));
	p->nome = strdup(nome);
	p->categoria = strdup(categoria);
	p->prezzo = prezzo;
	return p;
}

char* getNome(Prodotto p){
	char *nome = malloc(sizeof(char) * (1+strlen(p->nome)));
	strcpy(nome, p->nome);
	return nome;
}

char* getCategoria(Prodotto p){
	char *categoria = malloc(sizeof(char) * (1+strlen(p->categoria)));
	strcpy(categoria, p->categoria);
	return categoria;
}

float getPrezzo(Prodotto p){
	return p->prezzo;
}

void setSconto(Prodotto p, int sconto){
    p->sconto=sconto;
}

int getSconto(Prodotto p){
    return p->sconto;
}

float getPrezzoFinale(Prodotto p){
    return p->prezzo - (p->prezzo * p->sconto / 100);
}