#include <stdio.h>
#define N 5

void swap(int *a, int*b){
    int temp=*a;
    *a=*b;
    *b=temp;
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
}

int min(int a[], int n){
    int min=0;
    for (int i=1; i<n; i++){
        if (a[i]<a[min]) min=i;
    }
    return min;
}

void selectionSort(int a[], int n){
    for (int i=0; i<n-1; i++){
        int m=min(a+i, n-i);
        swap(a+i, a+m+i);
    }
}

int main(){
    int a[N], n=5;
    inputArray(a, n);
    selectionSort(a, n);
    outputArray(a, n);
    return 0;
}