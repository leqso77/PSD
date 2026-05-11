#include "transazione.h"

typedef struct conto *Conto;

Conto createConto();
void aggiungiTransazione(Conto conto, Transazione transazione);
void annullaTransazione(Conto conto, int id);
float calcolaSaldo(Conto conto);
void stampaEstrattoConto(Conto conto);
void freeConto(Conto conto);