/*
As filas são essenciais para manter a organização de um determinado processo, dando a prioridade para que o que entrou
primeiro seja atendido mais rapidamente.

O exemplo implementado neste arquivo mostra uma fila de pedidos para que sejam impressos documentos, portanto é importante
para que haja organização que o primeiro pedido a ser feito seja o primeiro a que seu processo de confecção seja iniciado.
*/


#include<stdio.h>
#include<stdlib.h>

typedef struct cel{
    int cont; //Número do pedido
    struct cel *seg;
}celula;




//Adicionar na fila
void addPedido(celula **i, celula **f, int x){
    celula *novo = malloc(sizeof(celula));
    novo->cont = x;
    novo->seg = NULL;
    if(*f == NULL) *i = novo;
    else (*f)->seg = novo;
    *f = novo;
}

//Remover da Fila

int iniciarProducaoPedido(celula **i){
    if(*i!=NULL){
        celula *pedido_a_fazer = *i;
        int x = pedido_a_fazer->cont;
        *i = (*i)->seg;
        free(pedido_a_fazer);
        return x;
    }

}

void inserirPedidos(celula **ini, celula **fim){
    char opcao = 's';
    int pedido;
    printf("%c",opcao);
    while (opcao == 's'){
        printf("Pedido: ");
        scanf("%d",&pedido);
        addPedido(ini, fim, pedido);
        fflush(stdin);
        printf("Continuar? s/n\n");
        scanf("%c",&opcao);
    }
}

void comecarPedidos(celula **ini){
    char opcao = 's';
    int pedido;
    while (opcao == 's'){
        printf("Pedido a ser feito: %d \n", iniciarProducaoPedido(ini));
        fflush(stdin);
        printf("Continuar? s/n");
        scanf("%c",&opcao);
    }
}

void imprime(celula *lst){
	celula *p;
	for (p=lst ; p!=NULL ; p=p->seg)
		printf("%d", p->cont);
	printf("\n");
}

int main(){
    celula *f = NULL;
    celula *i = NULL;
    inserirPedidos(&i,&f);
    imprime(i);
    comecarPedidos(&i);
    return 0;
}








