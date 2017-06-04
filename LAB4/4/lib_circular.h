/* Nome: João Carlos Pandolfi Santana
Data: 27/05/2014
Objetivo: Questoes Lab 4 - 4*/
typedef struct lista Lista;
Lista* Cria_lista();
Lista* Inicializa();
Lista* Adiciona(Lista* l,int num, char* nome);
Lista* Josephus(Lista* l);
void Libera(Lista* l);
void Imprime(Lista* l);
