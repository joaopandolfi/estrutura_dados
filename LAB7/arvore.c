/* Nome: João Carlos Pandolfi Santana
Data: 30/07/2014
Objetivo: LAB7 - Arvore*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "arvore.h"

struct arv {
	struct arv* esq;
	struct arv* dir;
	char* pal;
	Lista* ref ;
};

Arv* inicializaArv(){
	return NULL;
}

int vazia(Arv* a){
	if (a == NULL) 
		return 1;
	else 
		return 0;
}

Arv* insereArv(Arv* a, char* palavra, Lista* ref) {
	if (vazia(a)) {
		Arv* no = (Arv*) malloc(sizeof (Arv));
		no->pal = (char*) malloc(sizeof (char*));
		strcpy(no->pal, palavra);
		no->ref = ref;
		no->esq = no->dir= NULL;
		return no;
	}
	//verifico se a palavra da é "maior" que a do no acima
	if (strcmp(a->pal,palavra)>0)
		a->esq= insereArv (a->esq, palavra, ref);
	else
		a->dir = insereArv (a->dir, palavra, ref);
	return a;
}

Arv* buscaArv(Arv* a, char* palavra)
{
	if (vazia(a) == 1)
	return NULL;
	else if (strcmp(a->pal,palavra)>0)
	return buscaArv(a->esq, palavra);
	else if (strcmp(a->pal,palavra)<0)
	return buscaArv(a->dir, palavra);
	else return a;
}


Arv* excluirArv(Arv* a, char* pal){
	if (vazia(a) == 1)
		return NULL;
	else if (strcmp(a->pal,pal)>0)
		a->esq = (Arv*) excluirArv(a->esq,pal);
	else if (strcmp(a->pal,pal)<0)
		a->dir = (Arv*) excluirArv(a->dir,pal);
	else{/*achou o nó a ser excluido*/
		/*nó sem filhos*/
		if (a->esq == NULL && a->dir==NULL){
			free(a);
			a = NULL;
		}
		/*nó só tem filho à direita*/
		else if (a->esq == NULL){
			Arv* t = a;
			a = a->dir;
			free(t);
		}
		/*só tem filho à esquerda*/
		else if(a->dir == NULL){
			Arv* t = a;
			a = a->esq;
			free(t);
		}
		/*Nó tem os dois filhos*/
		else{
			Arv* f = a->esq;
			while(f->dir != NULL){
				f = f->dir;
			}
			a->pal = f->pal;
			f->pal = pal;
			a->esq = excluirArv(a->esq,pal);
		}
	}
	return a;
}

void imprimeArv(Arv* a,FILE* arq){
	if (!vazia(a)){
		imprimeArv(a->esq,arq);
		fprintf(arq,"%s", a->pal);
		imprimeLista(a->ref,arq);
		imprimeArv(a->dir,arq);
	}
}

Arv* liberaArv(Arv* a) {
	if (!vazia(a)){
		liberaArv(a->esq);
		liberaArv(a->dir);
		liberaLista(a->ref);
		free(a);
	}
	return NULL;
}
