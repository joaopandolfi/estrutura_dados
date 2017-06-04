/*
 Prova 2 Questão 2 
 João Carlos Pandolfi Santana
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;

struct lista{
	Lista* prox;
	Lista* ant;
	int val;
};

Lista* Insere(Lista* l, int val){
	Lista* nova = (Lista*) malloc(sizeof(Lista));
	nova->prox = NULL;
	nova->ant = NULL;
	nova->val = val;
	if(l == NULL)
		return nova;
	l->ant = nova;
	nova->prox = l;
	return nova;
}

void Imprime(Lista* l){
	Lista* aux1 = l;
	while(aux1 != NULL){
		printf("\n%d",aux1->val);
		aux1 = aux1->prox;
	}
}

Lista* uniao(Lista* l1, Lista* l2){
	Lista* aux1;
	Lista* aux2;
	Lista* nova = NULL;
	Lista* novoElem;
	int achou;
	aux1 = l1;
	while(aux1 != NULL){
		novoElem = (Lista*) malloc(sizeof(Lista));
		novoElem->val = aux1->val;
		if(nova == NULL)
			nova = novoElem;
		else{
			nova->ant = novoElem;
			novoElem->prox = nova;
			nova = novoElem;
		}
		aux1 = aux1->prox;
	}
	aux1 = l2;
	while(aux1 != NULL){
		aux2 = nova;
		achou = 0;
		while(aux2 != NULL){
			if(aux2->val == aux1->val)
				achou = 1;
			aux2 = aux2->prox;
		}
		if(achou == 0){
			novoElem = (Lista*) malloc(sizeof(Lista));
			novoElem->val = aux1->val;
			novoElem->prox = nova;
			nova->ant = novoElem;
			nova = novoElem;
		}
		aux1=aux1->prox;
	}
	return nova;
}

int main(){
	Lista* l1 = NULL;
	Lista* l2 = NULL;
	Lista* R;

	l1 = Insere(l1 ,1);
	l1 = Insere(l1 ,2);
	l1 = Insere(l1 ,3);
	l1 = Insere(l1 ,4);

printf("\n\nLista1");
Imprime(l1);

	l2 = Insere(l2 ,3);
	l2 = Insere(l2 ,4);
	l2 = Insere(l2 ,5);
	l2 = Insere(l2 ,6);

printf("\n\nLista2");
Imprime(l2);

	printf("\n\nUniao");
	R = uniao(l1,l2);

	Imprime(R);

return 0;
}
