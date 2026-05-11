#include <stdio.h>
#include <string.h>

int main(){

    char parola[50];
    int count=0;
    printf("inserisci una parola: ");
    scanf("%[^\n]", parola);
    for (int i=0; i<strlen(parola); i++){
        if (parola[i] == 'a' || parola[i] == 'e' || parola[i] == 'i' || parola[i] == 'o' || parola[i] == 'u'){
            count++;
        }
    }

    printf("%d\n", count);

}