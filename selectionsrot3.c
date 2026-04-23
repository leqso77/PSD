#include <stdio.h>
#include <string.h>

struct Personaggio{
    char nome[50];
    int hp;
};

void swapPersonaggio(struct Personaggio *p, struct Personaggio *p1){
    struct Personaggio p2=*p;
    *p=*p1;
    *p1=p2;
}

int minHp(struct Personaggio a[], int n){
int min=0;
for (int i=1; i<n; i++){
    if (a[i].hp<a[min].hp){
        min=i;
    }
}
return min;
}

void selectionsort(struct Personaggio a[], int n){
    for (int i=0; i<n-1; i++){
        int m=minHp(a+i, n-i);
        if (m!=0){
            swapPersonaggio(a+i, a+m+i);
        }
    }
}

int main(){
    struct Personaggio eroi[5]={
        {"Orco", 150},
        {"Ladro", 40},
        {"Cavaliere", 100},
        {"Mago", 30},
        {"Drago", 300}
    };
    selectionsort(eroi, 5);
    for (int i=0; i<5; i++){
            printf("eroi in ordine di hp: %s %dhp\n", eroi[i].nome, eroi[i].hp);
    }
    return 0;
}

