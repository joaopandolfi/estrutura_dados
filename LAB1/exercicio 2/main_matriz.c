/* Nome: João Carlos Pandolfi Santana
Data: 08/04/2014
Objetivo: O programa manipula uma matriz de inteiros*/
#include <stdio.h>
#include "lib_matriz.c"

int main()
{
	Matriz* mat = cria(2,2);
	printf("Tamanho da matriz %d x %d", linhas(mat),colunas(mat));
	atribui(mat,1,2,1.3);
	printf("\no valor da posicao 1,2 e %f",acessa(mat,1,2));
	libera(mat);
	return 0;
}
