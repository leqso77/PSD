typedef struct prenotazione *Prenotazione;

Prenotazione newPrenotazione(char *nome, int numeroPersone, char *tempo);
char *getNome(Prenotazione prenotazione);
int getNumeroPersone(Prenotazione prenotazione);
void printPrenotazione(Prenotazione prenotazione);
void freePrenotazione(Prenotazione prenotazione);

