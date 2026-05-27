#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "paziente.h"

Item inputItem() { return NULL; }

void outputItem(Item item) {
    Paziente p = item;
    printf("[%s - Età: %d - Gravità: %d]\n", getCognome(p), getEta(p), getGravita(p));
}

int compareItem(Item item1, Item item2) {
    Paziente p1 = item1; Paziente p2 = item2;
    if (getGravita(p1) > getGravita(p2)) return 1;
    if (getGravita(p1) < getGravita(p2)) return -1;
    return 0;
}

Item randomItem() {
    char *cognomi[] = {"Rossi", "Bianchi", "Verdi", "Russo", "Ferrari", "Esposito"};
    char *cognome_scelto = cognomi[rand() % 6];
    int eta_random = (rand() % 80) + 10;
    int gravita_random = (rand() % 5) + 1; 
    return initPaziente(cognome_scelto, eta_random, gravita_random);
}