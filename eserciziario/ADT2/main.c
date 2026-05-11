#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "catalogo.h"
#include "libro.h"

int main(){
    Catalogo catalogo=createCatalogo();
    Libro libri1=createLibro("Il Signore degli Anelli", "J.R.R. Tolkien", "Fantasy", 1954);
    Libro libri2=createLibro("1984", "George Orwell", "Dystopia", 1949);
    Libro libri3=createLibro("Il Grande Gatsby", "F. Scott Fitzgerald", "Novel", 1925);
    addLibro(catalogo, libri1);
    addLibro(catalogo, libri2);
    addLibro(catalogo, libri3);

    printCatalogo(catalogo);

    cercaPerAutoreCatalogo(catalogo, "George Orwell");
    cercaPerTitoloCatalogo(catalogo, "Il Signore degli Anelli");

    return 0;
}