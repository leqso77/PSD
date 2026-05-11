typedef struct transazione *Transazione;

Transazione createTransazione(int id, char *clausola, float importo);
int getId(Transazione transazione);
float getImporto(Transazione transazione);
void printTransazione(Transazione transazione);
void freeTransazione(Transazione transazione);