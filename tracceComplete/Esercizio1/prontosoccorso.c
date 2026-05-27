#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prontosoccorso.h"
#include "list.h"
#include "paziente.h"
#include "item.h"

struct prontosoccorso {
    char *nome_reparto;
    List pazienti;
};

ProntoSoccorso createProntoSoccorso(char* nome_reparto) {
    ProntoSoccorso ps = malloc(sizeof(struct prontosoccorso));
    ps->nome_reparto = strdup(nome_reparto);
    ps->pazienti = newList();
    return ps;
}

void addPaziente(ProntoSoccorso ps, Paziente p) {
    addHead(ps->pazienti, p);
}

void printProntoSoccorso(ProntoSoccorso ps) {
    printf("Reparto: %s\n", ps->nome_reparto);
    printList(ps->pazienti);
    printf("\n");
}

/* COMPLESSITÀ ASINTOTICA:
 * [Giustifica qui il costo dell'Insertion Sort, ricordandoti che 
 * getListItemPos all'interno di un ciclo costa!]
 */

/*
l'algorimo inserton sort ha complessita' O(n^2). se i dati sono gia' ordinati, per esempio i casi in cui abbiamo 0 o 1 elemento,
ha complessita O(1), questo perche' l'ADT con 0 o 1 elemento risulta automanticamente ordianto. 
la complessita' diventa O(n^2), caso medio/peggiore quando i dati sono in ordine casuale o decrescente
 */
void ordinaPerGravita(ProntoSoccorso ps) {
    int n = sizeList(ps->pazienti);
    
    // TODO: Implementa qui l'INSERTION SORT
    // Suggerimento: scorri con un 'for', salva l'elemento corrente con getListItemPos
    // e usa un 'while' per spostare in avanti gli elementi meno gravi, 
    // sovrascrivendoli con setListItemPos.
    // Usa compareItem() per confrontare le gravità.
    if (n<=1){
        return;
    }
    for(int i=1; i<n; i++){
        Item key=getListItemPos(ps->pazienti, i);
        int j=i-1;

        Item item_j=getListItemPos(ps->pazienti, j);

        while(j>=0 && compareItem(item_j, key)<0){
            setListItemPos(ps->pazienti, j+1, item_j);
            j--;
            if (j>=0){
                item_j=getListItemPos(ps->pazienti, j);
            }
        }
        setListItemPos(ps->pazienti, j+1, key);
    }
    
    
}