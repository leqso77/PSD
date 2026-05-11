#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "classifica.h"
#include "partita.h"

int main(){
    Classifica classifica= createClassifica();
    aggiungiInClassifica(classifica, createPartita("giocatore 1", 1000));
    aggiungiInClassifica(classifica, createPartita("giocatore 2", 2000));
    aggiungiInClassifica(classifica, createPartita("giocatore 3", 2500));

    stampaClassifica(classifica);

    aggiungiInClassifica(classifica, createPartita("giocatore 4", 1500));

    stampaClassifica(classifica);

    aggiungiInClassifica(classifica, createPartita("giocatore 5", 3000));

    stampaClassifica(classifica);

    freeClassifica(classifica);

    return 0;
}