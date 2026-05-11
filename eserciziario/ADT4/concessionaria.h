#ifndef CONCESSIONARIA_H
#define CONCESSIONARIA_H
#include "auto.h"

typedef struct concessionaria *Concessionaria;

Concessionaria createConcessionaria();
void addAuto(Concessionaria concessionaria, Auto car);
Auto cercaPerMarca(Concessionaria concessionaria, char *marca);
Auto cercaPerModello(Concessionaria concessionaria, char *modello);
void vendiAuto(Concessionaria concessionaria, Auto);
void printConcessionaria(Concessionaria concessionaria);

#endif
