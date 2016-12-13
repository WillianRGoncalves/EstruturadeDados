#include <stdio.h>
#include "biblioteca.h"


//FAZER ESTA MERDA
int heapsort(int v[],int n){
    int aux, i, j;
    for(i = n-1; i>=1; i--)
        for(j = i; i>=1 ; j--)
            if(v[j] > v[j/2]){
                aux = v[j];
                v[j] = v[j/2];
                v[j/2] = aux;
            }
}

int main () {
    int a[] = {7,3,5,9,1,4,2};
    int i;
    printf("\nConjunto Desordenado:\t");
    for (i = 0; i < 7; i++)
        printf("%d  ", a[i]);
    printf("\nConjunto Ordenado:\t");
    heapsort(a, 7);
    for (i = 0; i < 7; i++)
        printf("%d  ", a[i]);
    return 0;
}

