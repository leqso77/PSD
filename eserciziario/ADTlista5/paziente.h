typedef struct paziente *Paziente;

Paziente createPaziente(char *nome, int codiceGravita);
void printPaziente(Paziente paziente);
int getCodice(Paziente paziente);
void freePaziente(Paziente paziente);