#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cliente.h"
#include "eliminacode.h"

int main() {
    printf("=== SALUMERIA DA GINO ===\n\n");

    Eliminacode display = createEliminacode();

    // 1. Arrivano i clienti (Enqueue)
    printf("I clienti prendono il numeretto...\n");
    enqueue(display, newCliente(1, "Prosciutto crudo 200g"));
    enqueue(display, newCliente(2, "Mozzarella di bufala"));
    enqueue(display, newCliente(3, "Pane fresco e mortadella"));

    printf("\n--- DISPLAY ATTESA ---\n");
    printEliminacode(display);

    // 2. Il salumiere serve i primi due (Dequeue)
    printf("\n>>> DING DONG! Il salumiere chiama:\n");
    
    // Servo il primo
    Cliente servito1 = dequeue(display);
    if (servito1 != NULL) {
        printf("Servendo: ");
        printCliente(servito1);
        freeCliente(servito1); // La coda l'ha scartato, lo distruggo io qui!
    }

    // Servo il secondo
    Cliente servito2 = dequeue(display);
    if (servito2 != NULL) {
        printf("Servendo: ");
        printCliente(servito2);
        freeCliente(servito2);
    }

    // 3. Situazione aggiornata
    printf("\n--- DISPLAY ATTESA AGGIORNATO ---\n");
    printEliminacode(display);

    // 4. Arriva un nuovo cliente in coda
    printf("\nArriva un nuovo cliente...\n");
    enqueue(display, newCliente(4, "Salame piccante"));
    
    printEliminacode(display);

    // Spegnimento
    freeEliminacode(display);

    return 0;
}