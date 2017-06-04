/* Nome: João Carlos Pandolfi Santana
Data: 12/06/2014
Objetivo: LAB5 - Calculadora*/
#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
int main()
{
Calc* calculadora;
char op;
float valor;
printf("Calculadora pos-fixada\n\n");
printf("Digite 's' para sair.\n");
printf("Digite 'r' para raiz quadrada.\n");
printf("Digite '^' para exponenciacao.\n\n");
// Inicializa a calculadora
calculadora = cria_calc("%.2f\n");
// Loop para utilizar a calculadora
do{
	scanf(" %c", &op);
	if(op=='+' || op=='-' || op=='*' || op=='/' || op=='^' || op=='r')
		operador(calculadora, op);
	else
	{
		ungetc(op, stdin);
		if(scanf("%f", &valor)==1)
			operando(calculadora, valor);
	}
}while(op!='s');

// Libera calculadora
//libera_calc(calculadora);
return 0;
}
