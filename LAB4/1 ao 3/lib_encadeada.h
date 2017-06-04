/* Nome: João Carlos Pandolfi Santana
Data: 27/05/2014
Objetivo: Questoes Lab 4 - 1 ao 3*/
typedef struct lista Lista;
Lista* Novo_elem();
Lista* Inicializa();
Lista* Adiciona(Lista* l,int val);
void Imprime(Lista* l);
void Libera(Lista* l);
Lista* Cria_invertida(Lista* l);
Lista* Interseccao(Lista* l1, Lista* l2);
Lista* Uniao(Lista* l1, Lista* l2);
