#include "studente.h"

typedef struct registro *Registro;

Registro newRegistro();
void aggiungiStudnete(Registro registro, Studente studente);
Studente cercaPerMatricola(Registro registro, char *matricola);
void rimuoviStudente(Registro registro, char *matricola);
void stampaRegistro(Registro registro);
void freeRegistro(Registro registro);
