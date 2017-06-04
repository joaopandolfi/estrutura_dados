/* Nome: João Carlos Pandolfi Santana
Data: 21/05/2014
Objetivo: Questoes da prova*/
typedef struct lista Lista;
typedef struct val Val;
typedef struct listaFloat ListaFloat;
typedef struct rect Rect;
typedef struct listaRect ListaRect;
//funções do tipo Lista
Lista* novaLista();
Lista* insere(Lista* p, int val);
void imprime(Lista* p);
Lista* inverte(Lista* p);
Lista* inverteRec(Lista* original, Lista* listaVazia);
//funções do tipo ListaFloat
void imprimeLFloat(ListaFloat* p);
ListaFloat* organizaVetor(ListaFloat* p, int tamVet, float* v);
//funções do tipo ListaRect
void imprimeRect(ListaRect* p);
ListaRect* insereRect(ListaRect* p, float b, float h);
