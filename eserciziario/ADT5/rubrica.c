#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "rubrica.h"
#include "contatto.h"

struct rubrica{
    Contatto contatti[100];
    int size;
};

Rubrica createRubrica(){
    Rubrica rubrica=malloc(sizeof(struct rubrica));
    rubrica->size=0;
    return rubrica;
}

void addContact(Rubrica rubrica, Contatto contatto){
    if (rubrica->size<100){
        rubrica->contatti[rubrica->size]=contatto;
        rubrica->size++;
    }
}

Contatto cercaPerNome(Rubrica rubrica, char *nome){
    for (int i=0; i<rubrica->size; i++){
        if(cercapernome(rubrica->contatti[i], nome)==1){
            return rubrica->contatti[i];
        }
    }
    return NULL;
}

Contatto cercaPerNumero(Rubrica rubrica, char *numero){
    for(int i=0; i<rubrica->size; i++){
        if (cercapernumero(rubrica->contatti[i], numero)==1){
            return rubrica->contatti[i];
        }
    }
    return NULL;
}

Contatto newDetails(Rubrica rubrica, Contatto contatto, char *nuovonome, char *nuovocognome, char *nuovonumero, char *nuovoemail){
    Contatto nuovocontatto=changeDetails(contatto, nuovonome, nuovocognome, nuovonumero, nuovoemail);
    return nuovocontatto;
}

void printRubrica(Rubrica rubrica){
    for (int i=0; i<rubrica->size; i++){
        printContatto(rubrica->contatti[i]);
    }
}