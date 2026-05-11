#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libro.h"
#include "catalogo.h"

#define MAX_LIBRI 100

struct catalogo{
    Libro *libri;
    int size;
}; 

Catalogo createCatalogo(){
    Catalogo catalogo=malloc(sizeof(struct catalogo));
    catalogo->size=0;
    catalogo->libri=malloc(MAX_LIBRI*sizeof(Libro));
    return catalogo;
}

void addLibro(Catalogo catalogo, Libro libro){
    if (catalogo->size<MAX_LIBRI){
        catalogo->libri[catalogo->size]=libro;
        catalogo->size++;
    }
    else{
        printf("Catalogo pieno, impossibile aggiungere il libro.\n");
    }
}
Libro cercaPerAutoreCatalogo(Catalogo catalogo, char *autore){
    for (int i=0; i<catalogo->size; i++){
        if (cercaPerAutore(catalogo->libri[i], autore)==0){
            return catalogo->libri[i];
        }
    }
    return NULL;
}

Libro cercaPerTitoloCatalogo(Catalogo catalogo, char *titolo){
    for(int i=0;i<catalogo->size; i++){
        if(cercaPerTitolo(catalogo->libri[i], titolo)==0){
            return catalogo->libri[i];
        }
    }
    return NULL;
}
void printCatalogo(Catalogo catalogo){
    printf("Catalogo contiene %d libri:\n", catalogo->size);
    for (int i=0; i<catalogo->size; i++){
        printLibro(catalogo->libri[i]);
    }
}

