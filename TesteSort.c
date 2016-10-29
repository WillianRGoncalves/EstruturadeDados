#include <stdio.h>
#include "biblioteca.h"

int main () {
    int a[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};
    int i;
    printf("\nConjunto Desordenado:\t");
    for (i = 0; i < 10; i++)
        printf("%d  ", a[i]);
    printf("\nConjunto Ordenado:\t");
    shellsort(a, 10);
    for (i = 0; i < 10; i++)
        printf("%d  ", a[i]);
    return 0;
}

