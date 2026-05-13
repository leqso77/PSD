#include "ordine.h"

typedef struct drivethru *Drivethru;
Drivethru newDrivethru();
int isEmpty(Drivethru drivethru);
void enqueue(Drivethru drivethru, Ordine ordine);
Ordine dequeue(Drivethru drivethru);
int cercaOrdine(Drivethru drivethru, int numeroOrdine);
void printDrivethru(Drivethru drivethru);
void freeDrivethru(Drivethru drivethru);