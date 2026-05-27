typedef struct paziente *Paziente;
Paziente initPaziente(char* cognome, int eta, int gravita);
char* getCognome(Paziente p);
int getEta(Paziente p);
int getGravita(Paziente p);