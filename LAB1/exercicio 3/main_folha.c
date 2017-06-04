/* Nome: João Carlos Pandolfi Santana
Data: 08/04/2014
Objetivo: O programa Gera Contracheques dos funcionarios cadastrados*/
#include <stdio.h>
#include "lib_folha.c"
int main()
{
	Ficha* funcionarios;
	char continuar;
	float salarioRef;
	continuar = 'a';
	printf("Digite o Salario Base: ");
	scanf("%f",&salarioRef);
	printf("\n####### INSERINDO FUNCIONARIOS ########");
	//adiciona o primeiro funcionario
	funcionarios = preenche(novaFicha());
	printf("\nInserir outro funcionario?(s/n) :");
	scanf("\n%c",&continuar); // \n foi colocado pos o enter fica armazenado no buffer após ler um inteiro
	//preenche o resto
	while(continuar == 's' || continuar == 'S')
	{
		adiciona(funcionarios,preenche(novaFicha()));
		printf("\nInserir outro funcionario?(s/n) :");
		scanf("\n%c",&continuar); //explicação dada acima
	}
	imprimeContracheques(funcionarios,salarioRef);
	return 0;	
}
