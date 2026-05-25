#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "queue.h"
#include "item.h"

void reverseCoda(Queue q, Item item){
    if(isEmptyQueue(q)){
        return;
    }

    Item estratto=dequeue(q);
    reverseCoda(q, item);
    if(compareItem(estratto, item)<0){
        enqueue(q, estratto);
    }
}


int main() { // non modificare/spostare questa riga
	srand(time(NULL)); // non modificare/spostare questa riga
FILE *fp = fopen("input.txt", "r");
    if (!fp) return 1;

    char riga[256], parola[100];
    
    while (fgets(riga, 256, fp)) {
        Queue q = newQueue();
        Item param = NULL;
        int j = 0;

        for (int i = 0; riga[i] != '\0'; i++) {
            if (riga[i] != ' ' && riga[i] != '\n' && riga[i] != '\r') {
                parola[j++] = riga[i];
            } 
            else if (j > 0) {
                parola[j] = '\0';

                char *elem;
                if (strcmp(parola, "!") == 0) elem = randomItem();
                else { elem = malloc(j + 1); strcpy(elem, parola); }

                // Se param è vuoto, è la prima parola
                if (param == NULL) {
                    param = elem;
                    printf("Elemento parametro: %s\nCoda originale: ", (char*)param);
                } else { // Altrimenti va in coda
                    enqueue(q, elem);
                    printf("%s ", elem);
                }
                j = 0;
            }
        }
        if (param != NULL) {
            printf("\n");
            reverseAndFilter(q, param);
            
            printf("Coda invertita: ");
            while (!isEmptyQueue(q)) printf("%s ", (char*)dequeue(q));
            printf("\n");
        }
    }

    fclose(fp);
    return 0;
}

