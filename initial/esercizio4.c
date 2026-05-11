#include <stdio.h>

int main(){

    char nome[50];
    printf("Come ti chiami?\n");
    scanf("%[^\n]", nome);

    printf("piacere di conoscerti %s\n", nome);
    return 0; 
}