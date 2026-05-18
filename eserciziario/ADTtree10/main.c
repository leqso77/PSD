#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "btree.h"

int main(void) {
    printf("=== TEST TAIL RECURSION AVANZATA ===\n\n");

    /* ALBERO 1: Tutto a Sinistra
     * 50
     * /
     * 30
     * /
     * 10
     */
    Btree f10 = buildBtree(createItem(10), newBtree(), newBtree());
    Btree n30 = buildBtree(createItem(30), f10, newBtree());
    Btree alberoSx = buildBtree(createItem(50), n30, newBtree());

    /* ALBERO 2: Percorso Zig-Zag 
     * Pari va a Sx, Dispari va a Dx.
     * 10 (pari -> sx)
     * /  \
     * 7    99
     * \
     * 14 (pari -> sx)
     * /
     * 2
     */
    Btree f2 = buildBtree(createItem(2), newBtree(), newBtree());
    Btree n14 = buildBtree(createItem(14), f2, newBtree());
    Btree n7 = buildBtree(createItem(7), newBtree(), n14); // 7 è dispari, il figlio sta a destra
    Btree f99 = buildBtree(createItem(99), newBtree(), newBtree());
    Btree alberoZigZag = buildBtree(createItem(10), n7, f99);

    // 1. Test Tutto a Sinistra
    printf("--- TEST TUTTO A SINISTRA ---\n");
    if (isTuttoASinistra(alberoSx)) {
        printf("L'Albero 1 e' orientato TUTTO a sinistra. (Corretto!)\n");
    }
    if (!isTuttoASinistra(alberoZigZag)) {
        printf("L'Albero 2 NON e' tutto a sinistra. (Corretto!)\n\n");
    }

    // 2. Test Somma Zig-Zag
    printf("--- TEST SOMMA ZIG-ZAG ---\n");
    // Partiamo passando 0 come accumulatore iniziale
    int somma = sommaZigZag(alberoZigZag, 0);
    // Percorso: 10 (sx) -> 7 (dx) -> 14 (sx) -> 2 (fermo). Somma = 10+7+14+2 = 33.
    printf("Somma del percorso Zig-Zag nell'Albero 2: %d (Atteso: 33)\n\n", somma);

    // 3. Test Trova Minimo (con Accumulatore)
    printf("--- TEST TROVA MINIMO (DEGENERE) ---\n");
    // Per iniziare, passiamo come "minimo temporaneo" il valore della radice stessa!
    int minPartenza = getValore(getBtreeRoot(alberoSx));
    int minimoTrovato = trovaMinimoDegenere(alberoSx, minPartenza);
    printf("Il valore minimo dell'Albero 1 e': %d (Atteso: 10)\n", minimoTrovato);

    // Pulizia
    freeBtree(alberoSx);
    freeBtree(alberoZigZag);

    return 0;
}