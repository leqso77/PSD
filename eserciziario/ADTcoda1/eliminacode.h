#include "cliente.h"

typedef struct eliminacode *Eliminacode;

Eliminacode createEliminacode();
int isEmpty(Eliminacode eliminacode);
void enqueue(Eliminacode eliminacode, Cliente cliente);
Cliente dequeue(Eliminacode eliminacode);
void printEliminacode(Eliminacode eliminacode);
void freeEliminacode(Eliminacode eliminacode);