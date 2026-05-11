#ifndef CATALOGO_H
#define CATALOGO_H
#include "libro.h"

typedef struct catalogo *Catalogo;

Catalogo createCatalogo();
void addLibro(Catalogo catalogo, Libro);
void printCatalogo(Catalogo catalogo);
Libro cercaPerAutoreCatalogo(Catalogo catalogo, char *autore);
Libro cercaPerTitoloCatalogo(Catalogo catalogo, char *titolo);
#endif