#include <stdio.h>

int trovaMassimo(int a, int b){
    if (a>b) return a;
    else return b;
}
int main(){
    int x, y, max;
    printf("insert 2 numebers: ");
    scanf("%d %d", &x, &y);

    max=trovaMassimo(x, y);
printf("%d\n", max);
}