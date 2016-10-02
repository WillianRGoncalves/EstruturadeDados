/*
Uma das vantagens da lista encadeada em relação a um simples vetor é o fato de liberar memória após a
remoção do dado, portanto algo bom para utilização de uma maior quantidade de dados.

Nesta implementação se adiciona corredores de uma corrida e se verifica os ainda competindo eliminando
o competidor que terminor a corrida pelo seu número.

*/
#include<stdio.h>
#include<stdlib.h>

typedef struct cel{
	int cont;//Número do corredor
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

void busca_e_remove (int corredor, celula *le)
{
   celula *p, *q;
   p = le;
   q = le->seg;
   while (q != NULL && q->cont != corredor) {
      p = q;
      q = q->seg;
   }
   if (q != NULL) {
      p->seg = q->seg;
      free (q);
   }
}

void terminaramCorrida(celula *lst){
    char opcao = 's';
    int corredor;
    printf("%c",opcao);
    while (opcao == 's'){
        printf("Corredor: ");
        scanf("%d",&corredor);
        busca_e_remove (corredor, lst);
        fflush(stdin);
        printf("Continuar? s/n\n");
        scanf("%c",&opcao);
    }
}

void imprime(celula *lst){
	celula *p;
	printf("Corredores restantes:\n");
	for (p=lst->seg ; p!=NULL ; p=p->seg)
		printf("%d\t", p->cont);
	printf("\n");
}

int main (){

	int v[50];
	int i;

	for(i=1;i<=50;i++) v[i-1] = i;

	celula *corredores;


	corredores=malloc(sizeof(celula));
	corredores->seg=NULL;

	converte (v,50,corredores);

	terminaramCorrida(corredores);

	imprime(corredores);



	return 0;

}








