
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


int main (){

	int v1[]={1,3,5,7,9};
	int v2[]={2,4,6,8,10};

	celula *lp1;
	celula *lp2;
	celula *lp3;

	lp1=malloc(sizeof(celula));
	lp1->seg=NULL;
	lp2=malloc(sizeof(celula));
	lp2->seg=NULL;

	converte (v1,5,lp1);
	converte (v2,5,lp2);

	imprime(lp1);
	imprime(lp2);

	//lp3=intercala(lp1,lp2);
	lp3=intercala2(lp1,lp2);
	imprime(lp3);

	return 0;

}








