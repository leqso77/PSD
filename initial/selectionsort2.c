#include <stdio.h>
#define N 5


void swap(int *a, int *b, int *contaScambi){
    int temp=*a;
    *a=*b;
    *b=temp;
    (*contaScambi)++;
}

void inputArray(int a[], int n){
    for (int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
}

void outputArray(int a[], int n){
    for (int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int max(int a[], int n, int *contaConfronti){
    int max=0;
    for (int i=1; i<n; i++){
        if (a[i]> a[max]){
            max=i;
            (*contaConfronti)++;
        }
    }
    return max;
}

void selectionsort(int a[], int n, int *contaScambi, int *contaConfronti){
    for (int i=0; i<n-1; i++){
        int m=max(a+i, n-i, contaConfronti);
        if (m!=0){
        swap(a+i, a+m+i, contaScambi);
        }
    }
}

int main(){
    int a[N], n=5, contaScambi=0, contaConfronti=0;
    inputArray(a, n);
    selectionsort(a, n, &contaScambi, &contaConfronti);
    outputArray(a, n);
    printf("scambi totali: %d\n", contaScambi);
    printf("confronti totali: %d\n", contaConfronti);
    return 0;

}

