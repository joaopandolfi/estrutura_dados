/* Nome: João Carlos Pandolfi Santana
Data: 13/05/2014
Objetivo: O programa tem como objetivo uma lista generica (ContaCorrente/ContaPoupanca)*/
#include <string.h>
#include "lib_listagen.h"
#define CORRENTE 0
#define POUPANCA 1

//--------- ESTRUTURAS ---------
struct listagen{
	Conta* conta;
	struct listagen* prox;
};

struct conta{
	int tipo;
	void* info;
	int codigo;
	char nomeTitular[30];
	float saldo;
};

struct contaCorrente{
	float credito;
	float limite;
};

struct contaPoupanca{
	float taxaReferencial;
};

//-------- FUNCOES BASICAS ----------
Conta* Cria_conta(){
	Conta* novaConta = (Conta*) malloc(sizeof(Conta*));
	//verifica erro
	if(novaConta == NULL)
	{
		printf("Memoria insuficiente");
		exit(1);	
	}
	novaConta->info = NULL;
	//coleta os dados da conta
	printf("\nInforme o Nome do titular: ");
	scanf("%s",novaConta->nomeTitular);
	printf("Informe o saldo atual: ");
	scanf("%f",&novaConta->saldo);
	//retorna o tipo Conta preenchido
	return novaConta;
}

Conta* Cria_corrente(){
	Conta* novaConta = Cria_conta();
	ContaCorrente* novaCorrente  = (ContaCorrente*) malloc(sizeof(ContaCorrente*));
	//verifica erro
	if(novaCorrente == NULL)
	{
		printf("Memoria insuficiente");
		exit(1);	
	}
	//preenche os valores
	printf("Informe o Credito: ");
	scanf("%f",&novaCorrente->credito);
	printf("Informe o Limite: ");
	scanf("%f",&novaCorrente->limite);
	//joga Corrente para dentro de Conta
	novaConta->tipo = CORRENTE;
	novaConta->info = (ContaCorrente*) novaCorrente;
	//retorna o tipo Conta preenchido
	return novaConta;
}

Conta* Cria_poupanca(){
	Conta* novaConta = Cria_conta();
	ContaPoupanca* novaPoupanca = (ContaPoupanca*) malloc(sizeof(ContaPoupanca*));
	//verifica erro
	if(novaPoupanca == NULL)
	{
		printf("Memoria insuficiente");
		exit(1);	
	}
	//preenche os valores
	printf("Informe a Taxa Referencial: ");
	scanf("%f",&novaPoupanca->taxaReferencial);
	//joga Poupanca para dentro de Conta
	novaConta->tipo = POUPANCA;
	novaConta->info = (ContaPoupanca*) novaPoupanca;
	//retorna o tipo Conta preenchido
	return novaConta;
}

Listagen* Cria_Listagen(){
	Listagen* novaListagen = (Listagen *) malloc(sizeof(Listagen*));
	//verifica erro
	if(novaListagen == NULL)
	{
		printf("Memoria insuficiente");
		exit(1);	
	}
	novaListagen->prox = NULL;
	//retorna novaListagen
	return novaListagen;
}

// --------- FUNÇÕES DE CONTROLE -------

Listagen* Insere(Listagen* p){
	Listagen* novaListagen = Cria_Listagen();
	int escolha;
	//pergunta o tipo de usuario a ser criado
	printf("\nQual tipo de conta deseja criar? (1-Poupanca / 2-Corrente): ");
	scanf("%d",&escolha);
	while(escolha != 1 && escolha != 2)
	{
		printf("\nQual tipo de usuario deseja criar? (1-Poupanca / 2-Corrente)");
		scanf("%d",&escolha);
	}
	//preeche de acordo com a escolha
	if(escolha == 1)
		novaListagen->conta = (Conta*) Cria_poupanca();
	else
		novaListagen->conta = (Conta*) Cria_corrente();
		
	if(p == NULL)
		p = novaListagen;
	else
	{	
		novaListagen->prox = p;
		p = novaListagen;
	}
	return p;
}

void Imprime(Listagen* p)
{
	Listagen* aux;
	ContaPoupanca* poupancaAux;
	ContaCorrente* correnteAux;
	aux = p;
	//percorre a lista
	while(aux->prox != NULL)
	{
		if(aux->conta->tipo == POUPANCA)
		{
			printf("Dados da Conta POUPANCA:\n");
			printf("Nome Titular: %s\n",aux->conta->nomeTitular);
			printf("Saldo: %f\n",aux->conta->saldo);
			poupancaAux = (ContaPoupanca*) aux->conta->info;
			printf("Taxa Referencial: %f\n",poupancaAux->taxaReferencial);
		}
		else
		{
			printf("Dados da conta CORRENTE:\n");
			printf("Nome Titular: %s\n",aux->conta->nomeTitular);
			printf("Saldo: %f\n",aux->conta->saldo);
			correnteAux = (ContaCorrente*) aux->conta->info;
			printf("Credito: %f\n",correnteAux->credito);
			printf("Limite: %f\n",correnteAux->limite);
		}
	aux = aux->prox;
	}
}

void Debitar(Listagen* p)
{
	Listagen* aux = p;
	ContaCorrente* correnteAux;
	float val;

	while(aux->prox!=NULL)
	{
		if(aux->conta->tipo == CORRENTE)
		{
			printf("\nDEBITO EM CONTA CORRENTE\n");
			printf("Insira o valor: ");
			scanf("%f",&val);
			correnteAux = (ContaCorrente*) aux->conta->info;
			if(val >= (aux->conta->saldo + correnteAux->limite))
				printf("\nExcedeu o Limite.");
			else
			{
				aux->conta->saldo = aux->conta->saldo - val;
				printf("\nValor Debitado co Sucesso!");
			}
		}
		else
		{
			printf("\nDEBITO EM CONTA POUPANCA\n");
			printf("Insira o valor: ");
			scanf("%f",&val);
			if(val >= aux->conta->saldo)
				printf("\nExcedeu o Limite.");
			else
			{
				aux->conta->saldo = aux->conta->saldo - val;
				printf("\nValor Debitado co Sucesso!");
			}
			
		}
	aux = aux->prox;
	}
}
