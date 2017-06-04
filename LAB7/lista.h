/* Nome: João Carlos Pandolfi Santana
Data: 30/07/2014
Objetivo: LAB7 - Arvore*/
#include <stdio.h> //coloquei para o FILE funcionar -> não sei fazer de outra forma
typedef struct lista Lista;
Lista* inicializaLista();
Lista* novoElemento();
Lista* insereNaLista(Lista* l,int val);
int listaVazia(Lista* l);
void liberaLista(Lista* l);
void imprimeLista(Lista* l,FILE* arq);
