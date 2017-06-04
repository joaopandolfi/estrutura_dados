/* Nome: João Carlos Pandolfi Santana
Data: 13/05/2014
Objetivo: O programa tem como objetivo uma lista generica (Usuario/Cliente)*/
#include <stdio.h>
#include <stdlib.h>
#include "lib_listagen.h"

int main()
{
	Listagen* lista;
	lista = Cria_Listagen();
	lista = Insere(lista);
	lista = Insere(lista);
	lista = Insere(lista);
	if(Login(lista)==1)
		printf("\nLogado\n");
	else
		printf("\nLogin\senha inexistente ou invalido\n");
	
	Imprime(lista);
	return 0;
}
