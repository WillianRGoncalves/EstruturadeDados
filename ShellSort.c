#include <stdio.h>

void shell_sort (int *a, int n) {
    int gap, i, j, aux;
    for (gap = n; gap = gap / 2;) {
        for (i = gap; i < n; i++) {
            aux = a[i];
            for (j = i; j >= gap && aux < a[j - gap]; j = j - gap)
                a[j] = a[j - gap];
            a[j] = aux;
        }
    }
}

int main () {
    int a[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};
    int i;
    printf("\nConjunto Desordenado:\t");
    for (i = 0; i < 10; i++)
        printf("%d  ", a[i]);
    printf("\nConjunto Ordenado:\t");
    shell_sort(a, 10);
    for (i = 0; i < 10; i++)
        printf("%d  ", a[i]);
    return 0;
}

