#include <stdio.h>

int main(){

int pinsegreto=1234;
int pinutente;
int tentativi=1;

printf("insert pin: ");
scanf("%d", &pinutente);

while(pinutente != pinsegreto){
    printf("sbagliato coglione riprova\n");
    printf("insert pin: ");
    scanf("%d", &pinutente);
    tentativi++;

    if (tentativi==3){
        printf("troppi tentativi");
        break;
    }
}
printf("access granted\n");
return 0;
}