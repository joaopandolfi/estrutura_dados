#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

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
	novaPilha = juntaPilhas(auxPrio, auxNPrio);
	novaLista = convertePilhaParaLista(novaPilha);
	return novaLista;
}
