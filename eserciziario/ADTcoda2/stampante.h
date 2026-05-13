#include "documento.h"

typedef struct stampante *Stampante;

Stampante newStampante();
int isEmpty(Stampante stampante);
void enqueue(Stampante stampante,Documento documento);
Documento dequeue(Stampante stampante);
int CalcolaTempo(Stampante stampante);
void printStampante(Stampante stampante);
void freeStampante(Stampante stampante);