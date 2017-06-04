/* Nome: João Carlos Pandolfi Santana
Data: 21/05/2014
Objetivo: Questoes da prova*/
#include <stdio.h>
#include <stdlib.h>
#include "lib_prova.h"

// === estruturas ===
struct lista{
	int val;
	struct lista* prox;
};	

struct val{
	float numero;
	int qtd;
};

struct listaFloat{
	Val info;
	struct listaFloat *prox;
};

struct rect{
	float b;
	float h;
};

struct listaRect{
	Rect info;
	struct listaRect* prox;
};
// ===== FUNÇÕES BASICAS =====
Lista* novaLista(){	
	Lista* result = (Lista*)malloc(sizeof(Lista));
	if(result == NULL)
	{
		printf("\nMemoria Insufuciente\n");
		exit(1);
	}
	result->prox = NULL;
	return result;
}

Lista* insere(Lista* a,int val){
	Lista* aux;
	aux = novaLista();
	aux->val = val;
	aux->prox = a;
	return aux;
}

void imprime(Lista* p){
	Lista* a;
	a= p;
	while(a != NULL)
	{
		printf("\n%d",a->val);
		a = a->prox;
	}
}

void imprimeLFloat(ListaFloat* p){
	ListaFloat* a;
	a= p;
	while(a != NULL)
	{
		printf("\n\n Float");
		printf("\n%f -numero",a->info.numero);
		printf("\n%d -quant",a->info.qtd);
		a = a->prox;
	}
}

void imprimeRect(ListaRect* p){
	ListaRect* a;
	a= p;
	while(a != NULL)
	{
		printf("\n\n Retangulo");
		printf("\n%f -base",a->info.b);
		printf("\n%f -altura",a->info.h);
		a = a->prox;
	}
}
//=== FUNÇÕES DA PROVA ===

//questão 1 letra A
Lista* inverte(Lista* original){
	Lista* aux1;
	Lista* aux2;
	Lista* topo;
	Lista* novo = NULL;
	Lista* novoTopo;
	topo = original;
	if(topo == NULL)
		return NULL;

	while(topo->prox != NULL)
	{
		aux2 = aux1 = topo;
		while(aux1->prox != NULL)
		{
			aux2 = aux1;
			aux1 = aux1->prox;
		}
		if(novo == NULL)
			novoTopo = novo = aux1;
		else
		{
			novo->prox = aux1;
			novo = novo->prox;
		}
		aux2->prox = NULL;
	}
	novo->prox = topo;
	topo->prox = NULL;
	return novoTopo;
}

//questão 2 letra B
Lista* inverteRec(Lista* l,Lista* vazia){
	Lista* aux2;
	if(l==NULL)
		return vazia;
	else
	{
		vazia = insere(vazia,l->val);
		aux2 = l;
		l = l->prox;
		free(aux2);
		inverteRec(l,vazia);
	}
}

//questão 2
ListaFloat* organizaVetor(ListaFloat* p, int tamVet, float* v){
	int i, achou;
	ListaFloat* aux1;
	ListaFloat* aux2;
	ListaFloat* topo;
	i = 1;
	aux1 = (ListaFloat*) malloc(sizeof(ListaFloat*));
	aux1->info.numero = v[0];
	aux1->info.qtd = 1;
	topo = p = aux1;
	while(i<tamVet)
	{
		aux1 = topo;
		achou = 0;
		while(aux1 != NULL)
		{
			if(aux1->info.numero == v[i])
			{
				aux1->info.qtd++;
				achou=1;
			}
			aux2 = aux1;
			aux1 = aux1->prox;
		}
		aux1 = aux2;
		if(achou == 0)
		{
			aux2 = (ListaFloat*) malloc(sizeof(ListaFloat*));
			aux2->info.numero = v[i];
			aux2->info.qtd = 1;
			aux1->prox = aux2;
		}
		i++;
	}
	return topo;
}

//questão 3
Lista* diferenca(Lista* l1, Lista* l2){
	Lista* nova = NULL;
	Lista* aux1;
	Lista* aux2;
	Lista* ant;
	aux1 = l1;
	aux2 = l2;
	//copia l1 para dentro da nova
	while(aux1 != NULL)
	{
		nova = insere(nova,aux1->val);
		aux1 = aux1->prox;
	}
	//removo os elementos de l2 de dentro de l1
	aux1 = nova;
	ant = NULL;
	while(aux1 != NULL)
	{
		aux2 = l2;
		while(aux2 != NULL)
		{
			if(aux1->val == aux2->val)
			{
				if(ant == NULL)
				{
					ant = aux1;
					aux1 = aux1->prox;printf("\nremovido %d",ant->val);
					free(ant);
					ant = NULL;
				}
				else
				{
					ant->prox = aux1->prox;printf("\nremovido %d",aux1->val);
					free(aux1);
					aux1 = ant;
				}
			}
		aux2 = aux2->prox;
		}
		ant = aux1;
		aux1 = aux1->prox;
	}
	return nova;
}

//questao 4
ListaRect* insereRect(ListaRect* l, float b, float h){
	float area1,area2;
	ListaRect* aux1;
	ListaRect* aux2;
	int inseriu =0;
	aux1 = l;
	if(l == NULL)
	{
		l = (ListaRect*) malloc(sizeof(ListaRect*));
		l->info.b = b;
		l->info.h = h;
		return l;
	}
	area2 = b*h;
	while(aux1->prox != NULL)
	{
		area1 = (aux1->prox->info.b * aux1->prox->info.h);
		if(area2<area1)
		{
			aux2 = (ListaRect*) malloc(sizeof(ListaRect*));
			aux2->prox = aux1->prox;
			aux2->info.b = b;
			aux2->info.h = h;
			aux1->prox = aux2;
			inseriu = 1;
		}
		aux1 = aux1->prox;
	}
	if(inseriu == 0)
	{
		aux2 = (ListaRect*) malloc(sizeof(ListaRect*));
		aux2->info.h = h;
		aux2->info.b = b;
		aux1->prox = aux2;
	}
	return l;
}
