#include <stdio.h>
#include "list.h"

int main() {
    List miaLista = newList();

    printf("1. Inserisco in testa (10, poi 20)...\n");
    insertHead(miaLista, 10);
    insertHead(miaLista, 20);
    printList(miaLista); // Uscita: [20] -> [10] -> NULL

    printf("\n2. Inserisco in coda (99)...\n");
    insertTail(miaLista, 99);
    printList(miaLista); // Uscita: [20] -> [10] -> [99] -> NULL

    printf("\n3. Inserisco il numero 50 in posizione 1 (tra 20 e 10)...\n");
    insertNode(miaLista, 50, 1);
    printList(miaLista); // Uscita: [20] -> [50] -> [10] -> [99] -> NULL

    printf("\n4. Rimuovo l'elemento 10...\n");
    removeNode(miaLista, 10);
    printList(miaLista); // Uscita: [20] -> [50] -> [99] -> NULL

    freeList(miaLista);
    return 0;
}