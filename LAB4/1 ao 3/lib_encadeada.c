/* Nome: João Carlos Pandolfi Santana
Data: 27/05/2014
Objetivo: Questoes Lab 4 - 1 ao 3*/
#include "lib_encadeada.h"

struct lista{
	int val;
	struct lista* prox;
	struct lista* ant;
};

// ====== FUNCOES BASICAS ======

Lista* Novo_elem(){
	Lista* novaLista = (Lista*) malloc(sizeof(Lista*));
	if(novaLista == NULL)
	{
		printf("\nMemoria Insuficiente");
		exit(1);
	}
	//inicializo as lista circular apontado para ela mesma nas duas direcoes
	novaLista->prox = NULL;
	novaLista->ant = NULL;
	//retorno a lista
	return novaLista;
}

Lista* Inicializa(){
	return NULL;
}

Lista* Adiciona(Lista* l,int val){
	Lista* novo = Novo_elem();
	novo->val = val;
	//se a lista estiver vazia, retorna novo
	if(l == NULL)
		return novo;
	//senao
	l->ant = novo;
	novo->prox = l;
	l = novo;
	return l;
}

void Imprime(Lista* l){
	Lista* aux;
	aux = l;
	while(aux != NULL)
	{
		printf("\n %d",aux->val);
		aux = aux->prox;
	}
}

void Libera(Lista* l){
	Lista* aux;
	Lista* prox;
	aux = l;
	while(aux != NULL)
	{
		prox = aux->prox;
		free(aux);
		aux = prox;
	}
}

// ====== FUNCOES DO EXERCICIO ======

Lista* Cria_invertida(Lista* l){
	Lista* nova = Inicializa();
	Lista* aux;
	aux = l;
	//percorro a lista l
	while(aux != NULL)
	{
		//adiciono o valor na nova lista
		nova = Adiciona(nova,aux->val);
		aux = aux->prox;
	}
	return nova;
}

Lista* Interseccao(Lista* l1, Lista* l2){
	Lista* nova = Inicializa();
	Lista* aux1;
	Lista* aux2;
	aux1 = l1;
	//percorro l1
	while(aux1 != NULL)
	{
		aux2 = l2;
		//percorro l2
		while(aux2 != NULL)
		{
			//se for igual adiciona a nova Lista
			if(aux1->val == aux2->val)
				nova = Adiciona(nova,aux1->val);
			aux2 = aux2->prox;
		}
		aux1 = aux1->prox;
	}
	return nova;
}

Lista* Uniao(Lista* l1, Lista* l2){
	Lista* nova = Inicializa();
	Lista* aux1;
	Lista* aux2;
	int achou;
	aux1 = l1;
	//insiro a lista 1 em Nova
	while(aux1 != NULL)
	{
		nova = Adiciona(nova,aux1->val);
		aux1 = aux1->prox;
	}
	aux2 = l2;
	//percorro l2, e se o elemento for diferente eu insiro
	while(aux2 != NULL)
	{
		aux1 = nova;
		achou = 0;
		while(aux1 != NULL)
		{
			//se tiver algum elemento igual eu informo a flag
			if(aux1->val == aux2->val)
				achou =1;
			aux1 = aux1->prox;
		}
		//se nao achou, adiciona
		if(achou == 0)
			nova = Adiciona(nova,aux2->val);		
		aux2 = aux2->prox;
	}
	return nova;
}
