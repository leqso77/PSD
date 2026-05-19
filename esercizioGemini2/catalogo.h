#include "film.h"

typedef struct catalogo *Catalogo;

Catalogo createCatalogo(char* nome_genere);
void addFilm(Catalogo, Film);
void removeFilm(Catalogo, char*);
void printCatalogo(Catalogo);
void sortByValutazione(Catalogo);