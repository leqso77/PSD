#include "prenotazione.h"

typedef struct registro *Registro;

Registro newRegistro();

void addPrenotazione(Registro registro, Prenotazione prenotazione);
void removePrenotazione(Registro registro, char *nome);
int calcolaCoperti(Registro registro);
void printRegistro(Registro registro);
void freeRegistro(Registro registro);