#ifndef SPESA_H
#define SPESA_H

typedef struct spesa *Spesa;

Spesa createSpesa();
void addElemento(Spesa spesa, char *nome, int quantita, float prezzo);
void removeElemento(Spesa spesa, char *nome, int quantia, float prezzo);
void totaleSpesa(Spesa spesa);
void printSpesa(Spesa spesa);

#endif