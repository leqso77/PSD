#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "btree.h"

int main(void) {
    printf("=== TEST STATISTICHE E RICERCA ===\n\n");

    /* Costruiamo questo albero:
     * 10
     * /    \
     * 5      14
     * / \    /  \
     * 3   8  12  15
     */
     
    // Livello delle foglie
    Btree f3 = buildBtree(createItem(3), newBtree(), newBtree());
    Btree f8 = buildBtree(createItem(8), newBtree(), newBtree());
    Btree f12 = buildBtree(createItem(12), newBtree(), newBtree());
    Btree f15 = buildBtree(createItem(15), newBtree(), newBtree());
    
    // Livello intermedio
    Btree ramo5 = buildBtree(createItem(5), f3, f8);
    Btree ramo14 = buildBtree(createItem(14), f12, f15);
    
    // Radice
    Btree albero = buildBtree(createItem(10), ramo5, ramo14);

    // 1. Somma
    int totale = sommaNodi(albero);
    printf("Somma totale di tutti i nodi: %d (Atteso: 67)\n", totale);

    // 2. Conteggio Pari
    int numPari = contaPari(albero);
    printf("Numero di nodi con valore pari: %d (Atteso: 4 -> nodi 10, 8, 14, 12)\n\n", numPari);

    // 3. Ricerca
    printf("--- TEST RICERCA ---\n");
    
    int target1 = 12;
    if (cercaValore(albero, target1) == 1) {
        printf("Il numero %d e' STATO TROVATO nell'albero!\n", target1);
    } else {
        printf("Il numero %d NON esiste nell'albero.\n", target1);
    }
    
    int target2 = 99;
    if (cercaValore(albero, target2) == 1) {
        printf("Il numero %d e' STATO TROVATO nell'albero!\n", target2);
    } else {
        printf("Il numero %d NON esiste nell'albero.\n", target2);
    }

    // Pulizia finale
    freeBtree(albero);

    return 0;
}