#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "item.h"
#include "prontosoccorso.h"
#include "paziente.h"

int main() {
    srand(time(NULL)); 

    // 1. Crea il pronto soccorso (es. "Reparto Emergenze")
    ProntoSoccorso ps=createProntoSoccorso("Reparto Emergenze");
    // 2. Aggiungi 7 pazienti casuali usando randomItem() e addPaziente()
    for (int i=0; i<7; i++){
        Paziente p=randomItem();
        addPaziente(ps, p);
    }
    // 3. Stampa il pronto soccorso non ordinato
    printProntoSoccorso(ps);
    
    // 4. Chiama ordinaPerGravita()
    ordinaPerGravita(ps);
    
    // 5. Stampa il pronto soccorso ordinato
    printProntoSoccorso(ps);
    
    return 0;
}