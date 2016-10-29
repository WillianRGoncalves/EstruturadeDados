#include<stdio.h>
#include<stdlib.h>

typedef struct cel{
	int cont;
	struct cel *seg;
} celula;


void insereM (int y, celula *p) {
	celula *nova;

	nova=malloc (sizeof (celula));
	nova->cont=y;
	nova->seg=NULL;
	p->seg=nova;
}

void converte(int v[], int n, celula *lst){
	celula *p;
	p = lst;
	int i;

	for (i=0 ; i<n ; i++, p=p->seg)
		insereM (v[i],p);
}

celula *insere (celula *lst, celula *nova){
	lst->seg=nova;
	return nova;
}

celula *desempilha(celula *p){
	celula *lixo;
	lixo=p->seg;
	p->seg=lixo->seg;
	return lixo;
}

celula *intercala2 (celula *l1, celula *l2){
	celula *p1;
	p1=l1;
	celula *p2;
	p2=l2;
	celula *l3;
	l3=malloc(sizeof(celula));
	l3->seg=NULL;
	celula *p3;
	p3=l3;
	while (p1->seg!=NULL || p2->seg!=NULL){
		p3=insere(p3,desempilha(p1));
		p3=insere(p3,desempilha(p2));
	}
	return l3;
}


celula *intercala (celula *l1, celula *l2){

	celula *p1;
	p1=l1->seg;

	celula *p2;
	p2=l2->seg;

	celula *l3;
	l3=malloc(sizeof(celula));
	l3->seg=NULL;
	celula *p3;
	p3=l3;

	while(p1!=NULL || p2!=NULL){
		p3=insere(p3,p1);
		p1=p1->seg;

		p3=insere(p3,p2);
		p2=p2->seg;
	}
	return l3;
}

void imprime(celula *lst){
	celula *p;
	for (p=lst->seg ; p!=NULL ; p=p->seg)
		printf("%d", p->cont);
	printf("\n");
}

void insercaosort (int v[], int n) {
    int i, j, aux;
    for (i = 1; i < n; i++) {
    aux = v[i];
    for (j = i; j >= 1 && aux < v[j - 1]; j = j - 1)
        v[j] = v[j - 1];
    v[j] = aux;
    }
}

void shellsort (int v[], int n) {
    int gap, i, j, aux;
    for (gap = n; gap>=1; gap = gap / 2) {
        for (i = gap; i < n; i++) {
            aux = v[i];
            for (j = i; j >= gap && aux < v[j - gap]; j = j - gap)
                v[j] = v[j - gap];
            v[j] = aux;
        }
    }
}

void bolhasort(int v[], int n){
    int i, j, aux;
    for(i = n-1; i>0; i--)
        for(j=1; j<=i; j++)
            if(v[j-1]>v[j]){
                aux = v[j];
                v[j] = v[j-1];
                v[j-1] = aux;
            }

}

void selecaosort(int v[],int n){
    int i, j, aux, menor;
    for(i = 1; i < n; i++){
        menor = i-1;
        for (j = i; j<n; j++)
            if(v[j] < v[menor])
                menor = j;
        aux = v[i-1];
        v[i-1] = v[menor];
        v[menor] = aux;
    }

}
