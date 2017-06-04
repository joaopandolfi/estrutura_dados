#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "fila.h"

// ====== Funções Básicas ===========

int Vazia(Pilha* p)
{
	return p == NULL;
}

Pilha* InicializaPilha()
{
	return NULL;
}

Pilha* CriaPilha(){
	Pilha* novaPilha = (Pilha*) malloc(sizeof(Pilha*));
	if(novaPilha == NULL)
	{
		printf("\nMemoria Insuficiente");
		exit(1);
	}
	novaPilha->prox = NULL;
	return novaPilha;
}

Pilha* Push(Pilha* p, int cod, int prio, char* nome)
{
	Pilha* nova = CriaPilha();
	nova->prox = p;
	nova->cod = cod;
	nova->prio = prio;
	strcpy(nova->nome,nome);
	return nova;
}

Pilha* Pop(Pilha* p)
{
	Posicao c;
	Pilha* aux;
	aux = p;
	c = p->c;
	p = p->prox;
	free(aux);
	return p;
}

void Libera(Pilha* p)
{
	Pilha* aux;
	while(p != NULL)
	{	
		aux = p;
		p = p->prox;
		free(aux);
	}
}

Pilha* PushOrdenado(Pilha* pilha, int cod, int prio, char* nome){
	Pilha* p = pilha;
	Pilha* novo;
	Pilha* anterior = NULL;

	novo = (Pilha*)malloc(sizeof(Pilha))
	if(novo == NULL)
		return;

	novo->prox = p;
	novo->cod = cod;
	novo->prio = prio;
	novo->proximo = NULL;

	//procura posicao
	while(p != NULL && p->cod < cod)
	{
		anterior = p;
		p = p->proximo;
	}
	/*insere elemeto*/
	if(inicio->proximo == NULL) //insere no inicio
	{
		inicio->proximo = novo;
		novo->proximo = NULL;
	}
	else //insere no meio/fim
	{
		anterior->proximo = novo;
		novo->proximo = p;
	}
	return novo;
}

Pilha* JuntaPilhas(Pilha* p1, Pilha* p2){
	Pilha* aux1;
	if(p1 == NULL)
		return p2;
	if(p2 == NULL)
		return p1;
		
	aux1 = p1;
	while(aux1->prox != NULL)
		aux1 = aux1->prox;
		
	aux1->prox = p2;
	return aux1;
}
