/* Nome: João Carlos Pandolfi Santana
Data: 27/05/2014
Objetivo: Questoes Lab 4 - 1 ao 3*/
#include <stdio.h>
#include "lib_encadeada.c"

int main(){
	Lista* l1 = Inicializa();
	Lista* l2 = Inicializa();
	Lista* invertida = Inicializa();
	Lista* manipulada = Inicializa();
	//preencho lista 1
	l1 = Adiciona(l1,1);
	l1 = Adiciona(l1,2);
	l1 = Adiciona(l1,3);
	l1 = Adiciona(l1,4);
	l1 = Adiciona(l1,5);
	//preencho lista 2
	l2 = Adiciona(l2,4);
	l2 = Adiciona(l2,5);
	l2 = Adiciona(l2,6);
	l2 = Adiciona(l2,7);
	l2 = Adiciona(l2,8);
	
	printf("# EXERCICIO 1");
	printf("\n Lista1: ");
	Imprime(l1);
	
	printf("\n Lista1 Ivertida");
	invertida = Cria_invertida(l1);
	Imprime(invertida);

	printf("\n\n# EXERCICIO 2");
	printf("\n Lista1:");
	Imprime(l1);	
	printf("\n Lista2:");
	Imprime(l2);
	manipulada = Interseccao(l1,l2);
	printf("\n Interseccao");
	Imprime(manipulada);
	Libera(manipulada);
	
	printf("\n\n# EXERCICIO 3");
	printf("\n Lista1:");
	Imprime(l1);	
	printf("\n Lista2:");
	Imprime(l2);
	manipulada = Uniao(l1,l2);
	printf("\n Uniao");
	Imprime(manipulada);
	Libera(manipulada);
	
	Libera(l1);
	Libera(l2);
	Libera(invertida);
	return 0;
}
