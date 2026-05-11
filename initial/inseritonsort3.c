#include <stdio.h>

struct Studente {
    char nome[50];
    int voto;
};

 
void insertionsort(struct Studente a[], int n){
    for (int i=1; i<n; i++){
      struct Studente key=a[i];
      int j=i-1;

      while (j>=0 && a[j].voto > key.voto){
        a[j+1]=a[j];
        j=j-1;
      }
      a[j+1]=key;
}
}

void outputArray(struct Studente a[], int n){
    for(int i=0; i<n; i++){
        printf("%s - voto %d\n", a[i].nome, a[i].voto);
    }
}

int main() {
    struct Studente registro[4]={
        {"Marco", 5},
        {"Anna", 9},
        {"Luca", 7},
        {"Sofia", 10}
    };
    int n=4;
    outputArray(registro, n);
    insertionsort(registro, n);
    outputArray(registro, n);

    return 0;
}