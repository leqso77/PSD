#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "catalogo.h"
#include "list.h"
#include "film.h"

struct catalogo {
	char *nome_genere;
	List films;
};

Catalogo createCatalogo(char* nome_genere){
	Catalogo c = malloc(sizeof(struct catalogo));
	c->nome_genere = strdup(nome_genere);
	c->films = newList();
	return c;
}

void addFilm(Catalogo c, Film f){
	addHead(c->films, f);
}

void removeFilm(Catalogo c, char *titolo){
	Film f = initFilm(titolo, "", 0);
	removeListItem(c->films, f);
}

void printCatalogo(Catalogo c){
	printf("Catalogo: %s", c->nome_genere);
	printList(c->films);
	printf("\n");
}

void sortByValutazione(Catalogo c){
    int n=sizeList(c->films);
    for (int i=0; i<n-1; i++){
        for (int j=0; j<n-i-1; j++){
            Film f1=(Film)getListItemPos(c->films, j);
            Film f2= (Film)getListItemPos(c->films, j+1);
            if (getValutazione(f1) < getValutazione(f2)){
                setListItemPos(c->films, j, f2);
                setListItemPos(c->films, j+1, f1);
            }
        }
    }
}