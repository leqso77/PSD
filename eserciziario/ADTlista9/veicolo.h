typedef struct veicolo *Veicolo;

Veicolo newVeicolo(char *targa, char *modello, float prezzoRip);
char *getTarga(Veicolo veicolo);
float getPrezzoRip(Veicolo veicolo);
void printVeicolo(Veicolo veicolo);
void freeVeicolo(Veicolo veicolo);