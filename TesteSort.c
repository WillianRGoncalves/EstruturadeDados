#include <stdio.h>
#include "biblioteca.h"

int main () {
    int a[] = {7,3,5,9,1,4,2};
    int i;
    printf("\nConjunto Desordenado:\t");
    for (i = 0; i < 7; i++)
        printf("%d  ", a[i]);
    printf("\nConjunto Ordenado:\t");
    bolhasort(a, 7);
    for (i = 0; i < 7; i++)
        printf("%d  ", a[i]);
    return 0;
}

