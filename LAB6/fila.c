#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

struct no{
	char nome[50];
	int cod;
	int prio;
	struct no* prox;
};

struct fila{
	struct no* ini;
	struct no* fim;
};

// === manipulação da fila ====

Fila* InicialiazaFila(){
	Fila* nova = (Fila*) malloc(sizeof(Fila));
	nova->ini = NULL;
	nova->fim = NULL;
	return nova;
}

No* ins_fim(No* fim, int cod, int prio, char* nome){
	No* p = (No*) malloc(sizeof(No));
	p->cod =cod;
	p->prio = prio;
	strcpy(p->nome,nome);
	p->prox =NULL;
	if(fim!=NULL){
		/*verifica se a lista não está vazia*/
		fim->prox =p;
	}
	return p;
}

void insere(Fila* f, int cod, int prio, char* nome){
	f->fim = ins_fim(f->fim, cod, prio, nome);
	if ( f->ini==NULL)
		f->ini= f->fim;
}

No* ret_ini(No* ini){
	No* p = ini->prox;
	free(ini);
	return p;
}

No* retira(Fila* f){
	No* aux;
	if( vaziaFila(f)){
		printf("Fila vazia \n");
		exit(1);
	}
	aux->cod = f->ini->cod;
	aux->prio = f->ini->prio;
	strcpy(aux->nome,f->ini->nome);
	f->ini = ret_ini(f->ini);
	if (f->ini == NULL) { //removeu o último
		f->fim = NULL;
	}
	return aux;
}

/*Verifica se a fila está vazia*/
int vaziaFila(Fila* f){
	return (f->ini == NULL);
}

/*libera todos os elementos*/
void liberaFila(Fila* f){
	No* q = f->ini;
	while (q!=NULL) {
		No* t = q->prox;
		free(q);
		q =t;
	}
	free(f);
}

/*Imprime a fila*/
void imprimeFila(Fila* f) {
	No* q;
	for(q=f->ini; q!=NULL; q= q->prox){
		printf("%d\n", q->cod);
	}
}


// ====== Funções Básicas da PILHA ===========
 
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

	novo = (Pilha*)malloc(sizeof(Pilha));
	if(novo == NULL)
		return;

	novo->prox = p;
	novo->cod = cod;
	novo->prio = prio;
	novo->prox = NULL;

	//procura posicao
	while(p != NULL && p->cod < cod)
	{
		anterior = p;
		p = p->prox;
	}
	/*insere elemeto*/
	if(pilha->prox == NULL) //insere no inicio
	{
		pilha->prox = novo;
		novo->prox = NULL;
	}
	else //insere no meio/fim
	{
		anterior->prox = novo;
		novo->prox = p;
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



Fila* convertePilhaParaLista(Pilha* p){
	Fila* nova = (Fila*) malloc(sizeof(Fila*));
	Pilha* aux;
	nova->ini = p;
	if(p == NULL){
		nova->fim = NULL;
		return nova;
	}
	aux = p;
	while(aux->prox != NULL)
		aux = aux->prox;
	nova->fim = aux;
	return nova;
}

Fila* organizaFila(Fila* f){
	printf("a");

	Pilha* noAux;
	Fila* novaLista;
	Pilha* auxPrio = InicializaPilha();
	Pilha* auxNPrio = InicializaPilha();
	Pilha* novaPilha = InicializaPilha();
	//verifico se está vazio
	if(f == NULL || f->ini == NULL)
		return NULL;
	noAux = f->ini;
	//separo quem tem prioridade de quem nao tem Inserindo Ordenado
	while(noAux != NULL){
		if(noAux->prio == 1)
			auxPrio = PushOrdenado(auxPrio, noAux->cod, noAux->prio , noAux->nome);
		else
			auxNPrio = PushOrdenado(auxNPrio, noAux->cod, noAux->prio , noAux->nome);
		noAux = noAux->prox;
	}
	//insiro as pilhas na nova fila
	novaPilha = JuntaPilhas(auxPrio, auxNPrio);
	novaLista = convertePilhaParaLista(novaPilha);
	return novaLista;
}
