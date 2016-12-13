#include <stdio.h>
#include <stdlib.h>

struct cel{
    int valor;
    struct cel *esq;
    struct cel *dir;
};

typedef struct cel no;

no* find_pai(no * raiz, int n){
    no *no = raiz, *pai = no;
    while(no != NULL){
        if (n == no->valor) {
            return pai;
        }
        pai = no;
        if (n > no->valor)
            no = no->dir;
        else
            no = no->esq;

    }
    return NULL;
}

void inverter(no *raiz){
    if(raiz != NULL){
        no *aux;
        aux = raiz->dir;
        raiz->dir = raiz->esq;
        raiz->esq = aux;
        inverter(raiz->esq);
        inverter(raiz->dir);
    }
}


void inserir_recursivo(no **raiz, int n){
    if(*raiz == NULL){
        (*raiz) = malloc (sizeof (no));
        (*raiz)->valor = n;
        (*raiz)->esq = (*raiz)->dir = NULL;
    }else if((*raiz) ->valor > n)
        inserir_recursivo(&(*raiz)->esq,n);
    else
        inserir_recursivo(&(*raiz)->dir,n);
}

void imprimir(no *raiz){
    if(raiz != NULL){
        imprimir(raiz->esq);
        printf("%d\t",raiz->valor);
        imprimir(raiz->dir);
    }
}

int altura(no* raiz){
    if(raiz != NULL){
        int h1 = altura(raiz->esq)+1;
        int h2 = altura(raiz->dir)+1;
        if(h1>h2) return h1;
        else return h2;
    }
    else
        return -1;
}




int main(){
    no *arvore = NULL;
    inserir_recursivo(&arvore,7);
    inserir_recursivo(&arvore,9);
    inserir_recursivo(&arvore,3);
    inserir_recursivo(&arvore,5);
    imprimir(arvore);
    printf("\n\n%d\n\n",(find_pai(arvore,5)->valor));
    inverter(arvore);
    imprimir(arvore);
    printf("\n\n%d\n\n",altura(arvore));
    return 0;
}
