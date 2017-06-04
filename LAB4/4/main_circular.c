/* Nome: João Carlos Pandolfi Santana
Data: 27/05/2014
Objetivo: Questoes Lab 4 - 4*/
#include <stdio.h>
#include "lib_circular.c"

int main(){
	Lista* l = Inicializa();
	Lista* ultimo = Inicializa();
	
	l = Adiciona(l,0,"f");
	l = Adiciona(l,1,"g");
	l = Adiciona(l,2,"h");
	l = Adiciona(l,3,"i");
	l = Adiciona(l,4,"j");
	
	printf("\n# QUESTAO 4");
	
	printf("\nLista");
	Imprime(l);
	
	printf("\n\n Rodando o Algoritmo");
	ultimo = Josephus(l);
	
	printf("\n\n Utimo soldado.");
	Imprime(ultimo);
	
	Libera(ultimo);
	Libera(l);
	return 0;
}
