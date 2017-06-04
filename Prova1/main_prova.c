/* Nome: João Carlos Pandolfi Santana
Data: 21/05/2014
Objetivo: Questoes da prova*/
#include <stdio.h>
#include <stdlib.h>
#include "lib_prova.h"

int main(){
	Lista* a = NULL;
	Lista* b = NULL;
	ListaFloat* c;
	Lista* a2 = NULL;
	Lista* dif;
	ListaRect* retangulos;
	//questao 1
	float d[5];
	d[0] = 1.0;
	d[1] = 1.0;
	d[2] = 4.5;
	d[3] = 3.1;
	d[4] = 6.1;
	a = insere(a,1);
	a = insere(a,2);
	a = insere(a,3);
	a = insere(a,4);
	a = insere(a,5);
	a2 = insere(a2,1);
	a2 = insere(a2,9);
	a2 = insere(a2,8);
	a2 = insere(a2,2);
	a2 = insere(a2,5);
	printf("\n Normal");
	imprime(a);
	a = inverte(a);
	printf("\n Invertido - iterativo");
	imprime(a);
	printf("\n reinverte  - recursivo");
	a = inverteRec(a,b);
	imprime(a);

	//questao 2
	printf("\n QUESTAO 2");
	c = organizaVetor(c,5,d);
	imprimeLFloat(c);

	//questao 3
	printf("\n Questao 3");
	printf("\n Lista 1");
	imprime(a);
	printf("\n Lista 2");
	imprime(a2);	
	dif = diferenca(a,a2);
	printf("\n Diferenca (l1-l2)");
	imprime(dif);
	
	//questao 4
	printf("\n Questao 4");
	retangulos = insereRect(retangulos,2.0,2.1);
	retangulos = insereRect(retangulos,2.9,2.1);
	retangulos = insereRect(retangulos,3.0,2.1);
	retangulos = insereRect(retangulos,5.0,7.2);
	retangulos = insereRect(retangulos,9.0,6.1);
	imprimeRect(retangulos);
	
	return 0;
}
