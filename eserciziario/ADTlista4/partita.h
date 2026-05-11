typedef struct partita *Partita;

Partita createPartita(char *giocatore, int punteggio);
int getPunteggio(Partita partita);
void stampaPartita(Partita partita);
void freePartita(Partita partita);