/* Nome: João Carlos Pandolfi Santana
Data: 08/04/2014
Objetivo: O programa faz operações com numeros racionais*/
#include <stdio.h>
#include "lib_racional.c"

int main()
{
	Racional* numero1 = set(1,2);
	Racional* numero2 = set(3,2);
	Racional* resultado;
	resultado = add(numero1,numero2);
	printf("soma %s\n",notation(resultado));
	libera(resultado);
	resultado = sub(numero2,numero1);
	printf("%s\n",notation(resultado));
	libera(resultado);
	resultado = mul(numero2,numero1);
	printf("%s\n",notation(resultado));
	libera(resultado);
	resultado = divide(numero2,numero1);
	printf("%s\n",notation(resultado));
	libera(resultado);
	libera(numero1);
	libera(numero2);	
	return 0;
}
