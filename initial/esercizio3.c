#include <stdio.h>

int main(){

int A[5];
int somma=0;
float media=0;
for (int i=0; i<5; i++){
    printf("insert grade: \n");
    scanf("%d", &A[i]);
}

printf("voti sono: ");
for (int i=0; i<5; i++){
    printf("[%d] ", A[i]);
}
printf("\n");


for(int i=0; i<5; i++){
    somma= somma+ A[i];
}
media=somma / 5;

printf("%d\n", somma);
printf("%f\n", media);
printf("\n");
return 0;
}