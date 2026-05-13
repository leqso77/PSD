typedef struct ordine *Ordine;

Ordine newOrdine(int numeroOrdine, char *menu, float prezzo);
int getNumeroOrdine(Ordine ordine);
char *getMenu(Ordine ordine);
float getPrezzo(Ordine ordine);
void printOrdine(Ordine ordine);
void freeOrdine(Ordine ordine);
