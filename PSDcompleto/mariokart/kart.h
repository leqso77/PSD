#ifndef KART_H
#define KART_H

struct Pilota {
   char nome[20];
float tempo;
};

void ordinaClassifica(struct Pilota p[], int n);
void stampaClassifica(struct Pilota p[], int n);

#endif
