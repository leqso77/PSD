#include <stdlib.h>
#include <string.h>
#include "paziente.h"

struct paziente {
    char *cognome;
    int eta;
    int gravita;
};

Paziente initPaziente(char* cognome, int eta, int gravita) {
    Paziente p = malloc(sizeof(struct paziente));
    p->cognome = strdup(cognome); p->eta = eta; p->gravita = gravita;
    return p;
}
char* getCognome(Paziente p) { return p->cognome; }
int getEta(Paziente p) { return p->eta; }
int getGravita(Paziente p) { return p->gravita; }