#ifndef CANZONE_H
#define CANZONE_H

typedef struct canzone *Canzone;

Canzone createCanzone(char *, char *, char*, int);
void printCanzone(Canzone);

#endif