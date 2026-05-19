#define CARRELLO_H

#include "prodotto.h"

typedef struct carrello *Carrello;

Carrello createCarrello(char* id_carrello);
void addProdotto(Carrello, Prodotto);
void removeProdotto(Carrello, char*);
void printCarrello(Carrello);
void sortbyPrezzo(Carrello);
