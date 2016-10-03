/*
A recursão nesta implementação é utilizada para calcular a media de um aluno em vista de suas médias em provas
*/
#include<stdio.h>

float soma(float notas[], int tamanho){
    float resultado;
    if (tamanho == 0) return 0;
    if (tamanho == 1) return notas[tamanho-1];
    resultado += soma(notas, tamanho-1);
    return resultado + notas[tamanho-1];
}

int main (){
    float v[3] = {7.8,8.5,10.0};

	printf("Média do aluno: %.2f", soma(v,3)/3 );
    return 0;
}







