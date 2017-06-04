/* Nome: João Carlos Pandolfi Santana
Data: 27/05/2014
Objetivo: Questoes Lab 4 - 4*/
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lib_circular.h"

struct lista{
	int numero;
	char nome[30];
	struct lista* prox;
};

// ====== FUNCOES BASICAS ======

Lista* Cria_lista(){
	Lista* novaLista = (Lista*) malloc(sizeof(Lista*));
	if(novaLista == NULL)
	{
		printf("\nMemoria Insuficiente");
		exit(1);
	}
	//aponta para ele mesmo
	novaLista->prox = novaLista;
	//retorno a lista
	return novaLista;
}

Lista* Inicializa(){
	return NULL;
}

void Imprime(Lista* l){
	Lista* aux;
	aux = l;
	do{
		printf("\nNumero: %d",aux->numero);
		printf("\nNome: %s",aux->nome);
		aux = aux->prox;
	}while(aux != l);
}

Lista* Adiciona(Lista* l,int num, char* nome){
	Lista* novoElem;
	Lista* aux;
	//verifica se está vazia
	if(l == NULL)
	{
		l = Cria_lista();
		l->numero = num;
		strcpy(l->nome,nome);
		return l;
	}
	else if(l->prox == l)
	{
		novoElem = Cria_lista();
		//seto os valores
		novoElem->numero = num;
		strcpy(novoElem->nome,nome);
		//insiro na lista
		novoElem->prox = l;
		l->prox = novoElem;
	}
	else
	{
		//sem o aux estava dando problema
		aux = l->prox;
		novoElem = Cria_lista();
		//seto os valores
		novoElem->numero = num;
		strcpy(novoElem->nome,nome);
		//insiro na lista
		novoElem->prox = aux;
		l->prox = novoElem;
	}
	//retorna o ultimo elemento
	return novoElem;
}

void Libera(Lista* l){
	Lista* aux;
	Lista* prox;
	if(l == NULL)
		return;
	//recebe primeiro elemento
	aux = l->prox;
	//transforma e lista encadeada comum
	l->prox = NULL;
	//lipa lista
	while(aux != NULL)
	{
		prox = aux->prox;
		free(aux);
		aux = prox;
	}
}

// ====== FUNCOES DO EXERCICIO ======

Lista* Josephus(Lista* l){
	Lista* aux;
	Lista* rem;
	int num,i;
	char nome[30];

	//gero um numero aleatorio
	srand(time(NULL));
	num = rand() % 20;
	printf("\n O Numero Sorteado foi: %d",num);

	//leio o nome sorteado
	printf("\n Informe o nome sorteado: ");
	scanf("%s",nome);

	aux = l;
	//percorro até encontrar o nome
	while(strcmp(aux->nome,nome))
		aux = aux->prox;

	i = 0;
	//percorro até possuir somente um elemento na lista
	while(aux->prox != aux)
	{
		i++;
		//quando chega no numero
		if(i == num)
		{
			rem = aux->prox;
			printf("\n\n O Numero %d saiu.",rem->numero);
			printf("\n Nome: %s",rem->nome);
			aux->prox = aux->prox->prox;
			free(rem);
			i=0;
		}
		aux = aux->prox;
	}
	return aux;
}
