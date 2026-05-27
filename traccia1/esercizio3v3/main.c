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

void partizione(Stack s, Item item){
    if(isEmptyStack(s)){
        return;
    }
    Item element=top(s);
    pop(s);
    partizione(s, item);
    if(compareItem(element, item) < 0){
        insertAtBottom(s, element);
    }
    else {
        push(s, element);
    }
}

void printStackNew(Stack s){
    if (isEmptyStack(s)){
        return;
    }

    Item estratto=top(s);
    pop(s);
    printf("%s ", (char*)estratto);
    printStackNew(s);
    push(s, estratto);

}

int main(){
    srand(time(NULL));

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
            if (line[i] != ' ' && line[i] != '\n'){
                parola[j++]=line[i];
            }
            else if (j>0){
                parola[j]='\0';

                char *elem;
                if (strcmp(parola, "!")== 0){
                    elem=randomItem();
                }
                else {
                    elem=malloc(j+1);
                    strcpy(elem, parola);
                }

                if (param== NULL){
                    param=elem;
                    printf("Elemento parametro: %s\n", (char*)param);
                    printf("Stack originale: ");
                }
                else{
                    push(s, elem);
                }
                j=0;
            }
        }
        if (param!= NULL){
            printStackNew(s);
            printf("\n");

            partizione(s, param);

            printf("stack modificato: ");
            while(!isEmptyStack(s)){
                printf("%s ", (char*)top(s));
                pop(s);
            }
            printf("\n\n");
        }
    }
    fclose(fp);
    return 0;
}