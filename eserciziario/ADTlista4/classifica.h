#include "partita.h"

typedef struct classifica *Classifica;

Classifica createClassifica();
void aggiungiInClassifica(Classifica classifica, Partita partita);
void stampaClassifica(Classifica classifica);
void freeClassifica(Classifica classifica);

