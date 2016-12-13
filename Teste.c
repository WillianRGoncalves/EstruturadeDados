

#include<stdio.h>
#include<stdlib.h>
void intercala_ordena(int v[], int i, int m, int n){
    int vetor_aux[n], aux1, aux2, aux_indice = 0;
    aux1 = i;
    aux2 = m;
    for (aux_indice = 0;(aux1 < m && aux2 < n);aux_indice++){
        if(v[aux1] < v[aux2]){
            vetor_aux[aux_indice] = v[aux1];
            aux1++;
        }else{
            vetor_aux[aux_indice] = v[aux2];
            aux2++;
        }
    }
    if(aux1 >= m)
        while(aux_indice < n){
            vetor_aux[aux_indice] = v[aux2];
            aux_indice++;
            aux2++;
        }
    else
        while(aux_indice < n){
            vetor_aux[aux_indice] = v[aux1];
            aux_indice++;
            aux1++;
        }
    for(aux_indice = 0; aux_indice < n; aux_indice++)
        v[aux_indice] = vetor_aux[aux_indice];

}

//FAZER ESTA MERDA
void mergesort(int v[], int i,int n){
    int meio = (n-i)/2;
    printf("\n i: %d\n n: %d\n meio: %d", i,n, meio);
    if(n<2)
        return;
    printf("\n i: %d\n n: %d\n meio: %d", i,n, meio);
    mergesort(v,i,meio-1);
    mergesort(v,meio,n);
}



int main () {
    int a[] = {10,50,70,80,100,8,30,60,90,200,300};
    int i;
    printf("\nConjunto Desordenado:\t");
    for (i = 0; i < 11; i++)
        printf("%d  ", a[i]);
    mergesort(a, 0,11);
    /*printf("\nConjunto Ordenado:\t");
    for (i = 0; i < 11; i++)
        printf("%d  ", a[i]);*/
    return 0;
}









