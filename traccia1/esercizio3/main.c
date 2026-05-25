#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "item.h"
#include "stack.h"

void insertAtBottom(Stack s, Item item){
    if (isEmptyStack(s)){
        push(s, item);
        return;
    }

    Item estratto=top(s);
    pop(s);
    insertAtBottom(s, item);
    push(s, estratto);
}

void reverseStack(Stack s, Item item){
    if (isEmptyStack(s)){
        return;
    }
    Item estratto=top(s);
    pop(s);
    reverseStack(s, item);
    if(compareItem(estratto, item) > 0){
        insertAtBottom(s, estratto);
    }
}

int main() { // non modificare/spostare questa riga
	srand(time(NULL)); // non modificare/spostare questa riga


    FILE *fp=fopen("input.txt", "r");
    if (fp == NULL){
        printf("errore apertura file");
        return 1;
    }

    char line[256];
    char parola[100];

    while(fgets(line, 256, fp)){
        Stack s=newStack();
        Item param=NULL;
        int j=0;

        for (int i=0; line[i] != '\0'; i++){
            if (line[i] != ' ' && line[i]!='\n' && line[i] != '\r'){
                parola[j]=line[i];
                j++;
            }
            else if(j>0){
                parola[j]= '\0';

                char *element;
                if (strcmp(parola, "!") == 0){
                    element=randomItem();
                }
                else{
                    element=malloc(j+1);
                    strcpy(element, parola);
                }

                if (param == NULL){
                    param=element;
                    printf("Elemento Parametro: %s\n", (char*)param);
                    printf("Stack originale: ");
                }
                else{
                    push(s, element);
                }
                j=0;
            }
        }
        if(param != NULL){
            printStack(s);
            printf("\n");

            reverseStack(s, param);

            printf("Stack invertito: ");
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
