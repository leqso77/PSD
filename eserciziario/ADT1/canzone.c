#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "canzone.h"

struct canzone{
    char *titolo;
    char *artista;
    char *album;
    int durata;
};

Canzone createCanzone(char *titolo, char *artista, char *album, int durata){
    Canzone c= malloc(sizeof(struct canzone));
    c->titolo=malloc(strlen(titolo)+1);
    c->artista=malloc(strlen(artista)+1);
    c->album=malloc(strlen(album)+1);
    strcpy(c->titolo, titolo);
    strcpy(c->artista, artista);
    strcpy(c->album, album);
    c->durata=durata;
    return c;
}

void printCanzone(Canzone c){
    printf("Titolo: %s\n", c->titolo);
    printf("Artista: %s\n", c->artista);
    printf("Album: %s\n", c->album);
    printf("Durata: %d\n", c->durata);
}
