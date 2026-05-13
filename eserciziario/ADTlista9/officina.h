#include "veicolo.h"

typedef struct officina *Officina;

Officina createOfficina();
void addVeicolo(Officina officina, Veicolo veicolo);
void removeVeicolo(Officina officina, char *targa);
int calcoloIncasso(Officina officina);
void dannoMaggiore(Officina officina);
void printOfficina(Officina officina);
void freeOfficina(Officina officina);