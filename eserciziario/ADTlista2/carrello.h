#ifndef CARRELLO_H
#define CARRELLO_H
#include "prodotto.h"

typedef struct carrello *Carrello;

Carrello createCarrello();
void aggiungiAlCarrello(Carrello carrello, Prodotto prodotto);
float calcolaTotale(Carrello carrello);
void stampaCarrello(Carrello carrello);
void svuotaCarrello(Carrello carrello);

#endif