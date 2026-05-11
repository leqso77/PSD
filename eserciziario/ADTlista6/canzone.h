typedef struct canzone *Canzone;

Canzone createCanzone(char *titolo, char *autore, int durata);

char *getTitolo(Canzone canzone);
int getDurata(Canzone canzone);
void stampaCanzone(Canzone canzone);
void freeCanzone(Canzone canzone);

