#ifndef ELEMENTO_H
#define ELEMENTO_H

typedef struct elemento *Elemento;

Elemento createElemento(char *, int,  float);
void printElemento(Elemento elemento);
float getPrezzo(Elemento elemento);
int cercaPerNome(Elemento elemento, char *nome);


#endif