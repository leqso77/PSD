#define PRODOTTO_H

typedef struct prodotto *Prodotto;

Prodotto initProdotto(char* nome, char* categoria, float prezzo);
char* getNome(Prodotto);
char* getCategoria(Prodotto);
float getPrezzo(Prodotto);
void setSconto(Prodotto, int sconto);
int getSconto(Prodotto);
float getPrezzoFinale(Prodotto);
