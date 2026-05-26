#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "stack.h"

void removeDublicates(Stack s){
    if (isEmptyStack(s)){
        return;
    }
    Item estratto=top(s);
    pop(s);
    removeDublicates(s);
    if (!isEmptyStack(s)){
        Item topElement=top(s);
        if (compareItem(estratto, topElement) == 0){
            return;
        }
    }
    push(s, estratto);
}

void printStackNuovo(Stack s){
    if (isEmptyStack(s)){
        return;
    }

    Item estratto=top(s);
    pop(s);
    printf("%s ", (char*)estratto);
    printStackNuovo(s);
    push(s, estratto);
}

int main(){
    FILE *fp=fopen("input.txt", "r");
    if(fp==NULL){
        printf("errore apertura file");
        return 1;
    }

    char line[256];
    char lettere[100];

    while(fgets(line, 256, fp)){
        Stack s=newStack();
        Item param=NULL;
        int j=0;

        for (int i=0; line[i] != '\0'; i++){
            if (line[i] != ' ' && line[i] != '\n' && line[i] != '\r'){
                lettere[j++]=line[i];
            }
            else if(j>0){
                lettere[j]='\0';

                char *elem;
                if(strcmp(lettere, "!") == 0){
                    elem=randomItem();
                }
                else {
                    elem=malloc(j+1);
                    strcpy(elem, lettere);
                }
                push(s, elem);
                j=0;
            }
        }
        printf("stack originale: ");
        if (!isEmptyStack(s)){
            printStackNuovo(s);
            printf("\n");

            removeDublicates(s);
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