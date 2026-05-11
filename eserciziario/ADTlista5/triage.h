#include "paziente.h"

typedef struct salaAttesa *SalaAttesa;

SalaAttesa createSalaAttesa();

void aggiungiPaziente(SalaAttesa salaAttesa, Paziente paziente);
void chiamaProssimo(SalaAttesa salaAttesa);
void printSalaAttesa(SalaAttesa salaAttesa);
void freeSalaAttesa(SalaAttesa salaAttesa);

