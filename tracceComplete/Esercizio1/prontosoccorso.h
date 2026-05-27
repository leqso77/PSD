#include "paziente.h"

typedef struct prontosoccorso *ProntoSoccorso;

ProntoSoccorso createProntoSoccorso(char* nome_reparto);
void addPaziente(ProntoSoccorso, Paziente);
void printProntoSoccorso(ProntoSoccorso);

// ordina i pazienti mettendoli in ordine decrescente di gravità
// usando l'algoritmo INSERTION SORT
void ordinaPerGravita(ProntoSoccorso);