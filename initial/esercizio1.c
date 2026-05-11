#include <stdio.h>

int main(){
    
    int a;

    printf("insert a number: ");
    scanf("%d", &a);

    for (int i=1; i<=10; i++){
        int tabellina=a*i;
        printf("%d x %d= %d\n", a, i, tabellina);
    }

}