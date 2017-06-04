/* Nome: João Carlos Pandolfi Santana
Data: 13/05/2014
Objetivo: O programa tem como objetivo uma lista generica (Usuario/Cliente)*/
typedef struct listagen Listagen;
typedef struct usuario Usuario;
typedef struct cliente Cliente;
typedef struct pessoa Pessoa;
Pessoa* Cria_pessoa();
Pessoa* Cria_usuario();
Pessoa* Cria_cliente();
Listagen* Cria_Listagen();
Listagen* Insere(Listagen* p);
void Imprime(Listagen* p);
int Login(Listagen* p);
