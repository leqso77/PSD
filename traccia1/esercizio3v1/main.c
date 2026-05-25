#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "item.h"
#include "stack.h"

void doublePrint(Stack s, Item item){
    if(isEmptyStack(s)){
        return;
    }
    Item estratto=top(s);
    pop(s);
    doublePrint(s, item);
    push(s, estratto);
    if (compareItem(estratto, item) > 0){
        push(s, estratto);
    }
}

void printStackNuovo(Stack s){
    if(isEmptyStack(s)){
        return;
    }

    Item estratto=top(s);
    pop(s);
    printf("%s ", (char*)estratto);
    printStackNuovo(s);

    push(s, estratto);
}

int main() {
    srand(time(NULL));

    FILE *fp=fopen("input.txt", "r");
    if (fp == NULL){
        printf("errore apertura file");
        return 1;
    }

    char line[256];
    char lettere[100];
    while (fgets(line, 256, fp)){
        Stack s= newStack();
        Item param=NULL;
        int j=0;

        for(int i=0; line[i] != '\0'; i++){
            if (line[i] != ' ' && line[i] != '\n' && line[i] != '\r'){
                lettere[j]=line[i];
                j++;
            }
            else if (j>0){
                lettere[j]='\0';

                char *elem;
                if (strcmp(lettere, "!")==0){
                    elem=randomItem();
                }
                else{
                    elem=malloc(j+1);
                    strcpy(elem, lettere);
                }
                if (param == NULL){
                    param=elem;
                    printf("Elemento parametro: %s\n", (char*)param);
                    printf("stack originale: ");
                }

                else{
                    push(s, elem);
                }
                j=0;
            }
        }
        if (param !=NULL){
            printStackNuovo(s);
            printf("\n");

            doublePrint(s, param);
            printf("stack modificato: ");
            while(!isEmptyStack(s)){
                printf("%s ", (char*)top(s));
                pop(s);
            }
            printf("\n");
        }
    }
    fclose(fp);
    return 0;
}