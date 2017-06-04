/* Nome: João Carlos Pandolfi Santana
Data: 30/07/2014
Objetivo: LAB7 - Arvore*/
#include "lista.h"
typedef struct arv Arv;
Arv* inicializaArv(void);
void imprimeArv(Arv* a,FILE* arq);
int vazia(Arv* a);
Arv* insereArv(Arv* a, char* palavra, Lista* ref);
Arv* liberaArv(Arv* a) ;
Arv* buscaArv(Arv* a, char* palavra);
Arv* excluirArv(Arv* a, char* pal);
