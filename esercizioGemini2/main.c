#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "catalogo.h"
#include "film.h"

// da completare riga ***
void stampaEordina(Catalogo c){
	printf("\n-- Stampa catalogo originale --\n");
	printCatalogo(c);
	printf("\n-- Stampa catalogo dopo ordinamento per valutazione --\n");

	// *** inserire qui la chiamata all'operatore che ordina il catalogo
    sortByValutazione(c);
	printCatalogo(c);
	printf("\n\n");
}

// funzione che restituisce un numero intero tra 1 e 10
int randomValutazione() {
	return 1 + (rand() % 10);
}

int main() { 
	srand(time(NULL)); 

	// completare
    Catalogo c0=createCatalogo("Catalogo vuoto");
    stampaEordina(c0);
    
    Catalogo c1=createCatalogo("Catalogo classici");
    Film f1= initFilm("Il Padrino",  "Coppola", 1972);
    Film f2 = initFilm("Sharknado", "Ferrante", 2013);
    setValutazione(f1, 9);
    setValutazione(f2, 6);
    addFilm(c1, f1);
    addFilm(c1, f2);
    stampaEordina(c1);

    Catalogo c2=createCatalogo("Catalogo Sci-Fi");
    Film f3= initFilm("Interstellar", "Nolan", 2014);
    Film f4 = initFilm("Gravity", "Cuaron", 2013);
    Film f5 = initFilm("Dune", "Villeneuve", 2021);
    Film f6 = initFilm("Matrix", "Wachowski", 1999);
    setValutazione(f3, 9);
    setValutazione(f4, 7);
    setValutazione(f5, 8);
    setValutazione(f6, 10);
    addFilm(c2, f3);
    addFilm(c2, f4);
    addFilm(c2, f5);
    addFilm(c2, f6);
    stampaEordina(c2);
    return 0;
}