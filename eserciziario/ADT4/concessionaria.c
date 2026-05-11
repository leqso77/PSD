#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auto.h"
#include "concessionaria.h"

struct concessionaria{
    Auto cars[100];
    int size;
};

Concessionaria createConcessionaria(){
    Concessionaria concessionaria = malloc(sizeof(struct concessionaria));
    concessionaria->size=0;
    return concessionaria;
}

void addAuto(Concessionaria concessionaria, Auto car){
    if (concessionaria->size<10){
        concessionaria->cars[concessionaria->size]=car;
        concessionaria->size++;
    }
}

Auto cercaPerModello(Concessionaria concessionaria, char *modello){
    for (int i=0; i<concessionaria->size; i++){
        if (cercapermodello(concessionaria->cars[i], modello)==0){
            return concessionaria->cars[i];
        }
    }
}

Auto cercaPerMarca(Concessionaria concessionaria, char *marca){
    for (int i=0; i<concessionaria->size; i++){
        if (cercapermarca(concessionaria->cars[i], marca)==0){
            return concessionaria->cars[i];
        }
    }
}

void vendiAuto(Concessionaria concessionaria, Auto car){
    for (int i=0; i< concessionaria->size; i++){
        if (concessionaria->cars[i]==car){
            for (; i<concessionaria->size-1; i++){
                concessionaria->cars[i]=concessionaria->cars[i+1];
            }
            concessionaria->size--;
        } 
    }
}

void printConcessionaria(Concessionaria concessionaria){
    for(int i=0; i<concessionaria->size; i++){
        printAuto(concessionaria->cars[i]);
    }
}
