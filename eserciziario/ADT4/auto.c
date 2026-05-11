#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auto.h"

struct car{
    char *marca;
    char *modello;
    int anno;
    int prezzo;
};

Auto createAuto(char *marca, char *modello, int anno, int prezzo){
    Auto car= malloc(sizeof(struct car));
    car->marca=malloc(sizeof(marca)*5);
    strcpy(car->marca, marca);
    car->modello=malloc(sizeof(modello)*5);
    strcpy(car->modello, modello);
    car->anno=anno;
    car->prezzo=prezzo;

    return car;
}

int cercapermarca(Auto car, char *marca){
    return strcmp(car->marca, marca)==0;
}

int cercapermodello(Auto car, char *modello){
    return strcmp(car->modello, modello)==0;
}

void printAuto(Auto car){
    printf("Marca: %s, Modello: %s, Anno: %d, Prezzo: %d\n", car->marca, car->modello, car->anno, car->prezzo);
}

