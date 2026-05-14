#include "auto.h"

typedef struct autolavaggio *Autolavaggio;

Autolavaggio newAutolavaggio();
int isEmpty(Autolavaggio autolavaggio);
void enqueue(Autolavaggio autolavaggio, Auto automobile);
Auto dequeue(Autolavaggio autolavaggio);
int contaLavaggiPremium(Autolavaggio autolavaggio, char *programmaLavaggio);
void printAutolavaggio(Autolavaggio autolavaggio);
void freeAutolavaggio(Autolavaggio autolavaggio);
