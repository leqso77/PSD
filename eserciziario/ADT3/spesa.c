#include <stdio.h>
#include <stdlib.h>
#include "spesa.h"
#include "elemento.h"

struct spesa{
    Elemento *elementi[100];
    int size;
};

Spesa createSpesa(){
    Spesa spesa=malloc(sizeof(struct spesa));
    spesa->size=0;
    return spesa;
}

void addElemento(Spesa spesa, char *nome, int quantita, float prezzo){
    if(spesa->size<100){
        spesa->elementi[spesa->size]=createElemento(nome, quantita, prezzo);
        spesa->size++;
    }
}

void removeElemento(Spesa spesa, char *nome, int quantita, float prezzo){
        for (int i=0; i<spesa->size; i++){
        if(cercaPerNome(spesa->elementi[i], nome)==0){
            for(; i<spesa->elementi; i++){
                spesa->elementi[i]=spesa->elementi[i+1];
                spesa->size--;
            }
        }
    }
}

void totaleSpesa(Spesa spesa){
    float totale=0;
    for (int i=0; i<spesa->size; i++){
        totale+=getPrezzo(spesa->elementi[i]);
    }
    printf("Totale spesa: %.2f\n", totale);
}

void printSpesa(Spesa spesa){
    printf("La spesa contiene %d elementi:\n", spesa->size);
    for (int i=0; i<spesa->size; i++){
        printElemento(spesa->elementi[i]);
    }
}
