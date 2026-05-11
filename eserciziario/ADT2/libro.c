#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libro.h"


struct libro{
    char *titolo;
    char *autore;
    char *genere;
    int pubblicazione;
};


Libro createLibro(char *titolo, char *autore, char *genere, int pubblicazione){
    Libro libro=malloc(sizeof(struct libro));
    libro->pubblicazione=pubblicazione;
    libro->titolo=malloc((strlen(titolo)+1)*sizeof(char));
    libro->autore=malloc((strlen(autore)+1)*sizeof(char));
    libro->genere=malloc((strlen(genere)+1)*sizeof(char));
    strcpy(libro->titolo, titolo);
    strcpy(libro->autore, autore);  
    strcpy(libro->genere, genere);
    return libro;
}

int cercaPerAutore(Libro libro, char *autore){
    return strcmp(libro->autore, autore);
}

int cercaPerTitolo(Libro libro, char *titolo){
    return strcmp(libro->titolo, titolo);
}

void printLibro(Libro libro){
    printf("Titolo: %s, Autore: %s, Genere: %s, Pubblicazione: %d\n", libro->titolo, libro->autore, libro->genere, libro->pubblicazione);
}