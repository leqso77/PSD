#ifndef RUBRICA_H
#define RUBRICA_H
#include "contatto.h"

typedef struct rubrica *Rubrica;

Rubrica createRubrica();
void addContact(Rubrica rubrica, Contatto contatto);
Contatto cercaPerNome(Rubrica rubriuca, char *nome);
Contatto cercaPerNumero(Rubrica rubrica, char *numero);
Contatto newDetails(Rubrica rubrica, Contatto contato, char *nuovonome, char *nuovocognome, char *nuovonumero, char *nuovoemail);
void printRubrica(Rubrica rubrica);

#endif


