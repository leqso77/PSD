#include <stdlib.h>
#include <string.h>
#include "film.h"

struct film {
	char *titolo;
	char *regista;
	int anno;
    int valutazione;
};

Film initFilm(char* titolo, char* regista, int anno){
	Film f = malloc(sizeof(struct film));
	f->titolo = strdup(titolo);
	f->regista = strdup(regista);
	f->anno = anno;
	return f;
}

char* getTitolo(Film f){
	char *titolo = malloc(sizeof(char) * (1+strlen(f->titolo)));
	strcpy(titolo, f->titolo);
	return titolo;
}

char* getRegista(Film f){
	char *regista = malloc(sizeof(char) * (1+strlen(f->regista)));
	strcpy(regista, f->regista);
	return regista;
}

int getAnno(Film f){
	return f->anno;
}

void setValutazione(Film f, int valutazione){
    f->valutazione=valutazione;
}

int getValutazione(Film f){
    return f->valutazione;
}