/* Nome: João Carlos Pandolfi Santana
Data: 30/07/2014
Objetivo: LAB7 - Arvore*/
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista {
	int val;
	struct lista * prox;
};

Lista* inicializaLista(){
	return NULL;
}

Lista* novoElemento(){
	Lista* nova = (Lista*) malloc(sizeof(Lista*));
	if(nova == NULL){
		printf("\nMemoria insufuciente\n");
		exit(1);
	}
	return nova;
}

Lista* insereNaLista(Lista* l,int val){
	Lista* novoElem = novoElemento();
	Lista* aux;
	novoElem->val = val;
	novoElem->prox = NULL;
	if(l == NULL)
		return novoElem;
	aux = l;
	
	while(aux->prox != NULL)
		aux = aux->prox;
		
	aux->prox = novoElem; 
	return l;
}

int listaVazia(Lista* l){
	return l == NULL;
}

void imprimeLista(Lista* l,FILE* arq){
	while(l != NULL){
		fprintf(arq,",%d",l->val);
		l = l->prox;		
	}
	fprintf(arq,"\n");//final da linha
}

void liberaLista(Lista* l){
	Lista* aux;
	while(l != NULL){
		aux = l;
		l = l->prox;
		free(aux);
	}
}
