#ifndef PRODOTTO_H
#define PRODOTTO_H

typedef struct prodotto *Prodotto;

Prodotto creaProdotto(char *nome, float prezzo);
float getPrezzo(Prodotto prodotto);
void printProdotto(Prodotto prodotto);
void freeProdotto(Prodotto prodotto);

#endif
