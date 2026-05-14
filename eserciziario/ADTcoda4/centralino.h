#include "ticket.h"

typedef struct centralino *Centralino;

Centralino newCentralino();
int isEmpty(Centralino centralino);
void enqueue(Centralino centralino, Ticket ticket);
Centralino dequeue(Centralino centralino);
int contaChiamatePerReparto(Centralino centralino, char *repartoRichiesta);
void printCentralino(Centralino centralino);
void freeCentralino(Centralino centralino);