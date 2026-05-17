#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "btree.h"

int main(void) {
    printf("=== TEST STRUTTURA, ALTEZZA MINIMA E POTATURA ===\n\n");

    /* Costruiamo ALBERO 1:
     * 10
     * /  \
     * 5    20
     * /      \
     * 3        25
     * \
     * 30
     */
    Btree f3 = buildBtree(createItem(3), newBtree(), newBtree());
    Btree f30 = buildBtree(createItem(30), newBtree(), newBtree());
    
    Btree nodo5 = buildBtree(createItem(5), f3, newBtree());
    Btree nodo25 = buildBtree(createItem(25), newBtree(), f30);
    Btree nodo20 = buildBtree(createItem(20), newBtree(), nodo25);
    
    Btree albero1 = buildBtree(createItem(10), nodo5, nodo20);

    /* Costruiamo ALBERO 2 (Stessa struttura, numeri completamente diversi):
     * 99
     * /  \
     * 88   77
     * /      \
     * 66       55
     * \
     * 44
     */
    Btree f66 = buildBtree(createItem(66), newBtree(), newBtree());
    Btree f44 = buildBtree(createItem(44), newBtree(), newBtree());
    
    Btree nodo88 = buildBtree(createItem(88), f66, newBtree());
    Btree nodo55 = buildBtree(createItem(55), newBtree(), f44);
    Btree nodo77 = buildBtree(createItem(77), newBtree(), nodo55);
    
    Btree albero2 = buildBtree(createItem(99), nodo88, nodo77);

    // 1. Test Struttura
    if (isStrutturaUguale(albero1, albero2)) {
        printf("I due alberi hanno la STESSA FORMA! (Corretto)\n");
    } else {
        printf("I due alberi hanno forma diversa.\n");
    }

    // 2. Test Altezza Minima
    int altMin = altezzaMinima(albero1);
    int altMax = altezzaMinima(albero2); // Sappiamo che hanno la stessa struttura
    printf("\nAltezza minima dell'albero 1: %d (Atteso: 3 -> percorso 10-5-3)\n", altMin);

    // 3. Test Potatura (Pruning)
    printf("\n--- TEST POTATURA FOGLIE ---\n");
    printf("Pre-Order prima della potatura: ");
    printPreOrder(albero1);
    // Atteso: 10 5 3 20 25 30
    printf("\n");
    
    // Le foglie attualmente sono 3 e 30. Verranno distrutte.
    albero1 = prunaFoglie(albero1);
    
    printf("Pre-Order DOPO la potatura:   ");
    printPreOrder(albero1);
    // Atteso: 10 5 20 25 (I nodi 3 e 30 sono spariti!)
    printf("\n");

    // Pulizia
    freeBtree(albero1);
    freeBtree(albero2);

    return 0;
}