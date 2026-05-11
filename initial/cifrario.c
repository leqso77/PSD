#include <stdio.h>
#include <string.h>

void cript(char *message, int key){
    for (int i=0; i<strlen(message); i++){
        if (message[i]>= 'a' && message[i]<='z')
        message[i]+=key;
        if (message[i]>'z'){
            message[i]-=26;
        }
    }
}

void decript(char *message, int key){
    for (int i=0; i<strlen(message); i++){
        if (message>= 'a' && message<='z')
        message[i]-=key;
        if (message[i]=='a'){
            message[i]+=26;
        }
    }
}

int main(){

    char message[500];
    int chiave, scelta;

    printf("inserisci un messaggio: \n");
    scanf("%[^\n]", message);

    printf("inserisci una chiave: \n");
    scanf("%d", &chiave);


    printf("vuoi criptare o decriptare? (1 o 2)\n");
    scanf("%d", &scelta);

    if(scelta==1){
        cript(message, chiave);
        printf("il messaggio criptato: %s\n", message);
    }
    else if (scelta==2){
        decript(message, chiave);
        printf("il messaggio decriptato: %s\n", message);
    }
    else printf("scelta non valida\n");
}