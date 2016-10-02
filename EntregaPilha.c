/*
As pilhas são úteis pelo seu comportamento de retirar o último elemento a ser colocado na estrutura,
para saber o último a entrar em determinada situação, diferente da fila que avalia o primeiro a entrar.

O exemplo utilizado nesta implementação trata-se de um verificador para apresentações, em uma escola
há duas apresentações, e se armazena na pilha a ordem em que os alunos resolveram fazer a primeira apresentação
e a depois de armazenar todos os nomes o professor desempilha a estrutura para inverter a ordem das apresentações
na segunda vez.
*/


#include<stdio.h>
#include<stdlib.h>

typedef struct cel{
	int cont; // Número de chamada do aluno
	struct cel *seg;
} celula;


void add (int x, celula *p)
{
   celula *nova;
   nova = malloc (sizeof (celula));
   nova->cont = x;
   nova->seg = p->seg;
   p->seg = nova;
}

int desempilha (celula *p) {
    int x; celula *q;
    q = p->seg;
    x = q->cont;
    p->seg = q->seg;
    free (q);
    return x;
}



void imprime(celula *lst){
	celula *p;
	for (p=lst->seg ; p!=NULL ; p=p->seg)
		printf("%d", p->cont);
	printf("\n");
}

void leituraAlunos(celula *lst){
    char opcao = 's';
    int numero;
    printf("%c",opcao);
    while (opcao == 's'){
        printf("Aluno: ");
        scanf("%d",&numero);
        add(numero, lst);
        fflush(stdin);
        printf("Continuar? s/n\n");
        scanf("%c",&opcao);
    }
}

void segundaApresentacao(celula *lst){
    char opcao = 's';
    int numero;
    while (opcao == 's'){
        printf("aluno: %d \n", desempilha(lst));
        fflush(stdin);
        printf("Continuar? s/n");
        scanf("%c",&opcao);
    }
}


int main (){

	celula *alunos;

	alunos=malloc(sizeof(celula));
	alunos->seg=NULL;
    leituraAlunos(alunos);
    segundaApresentacao(alunos);


	return 0;

}








