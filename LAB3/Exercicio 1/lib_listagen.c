/* Nome: João Carlos Pandolfi Santana
Data: 13/05/2014
Objetivo: O programa tem como objetivo uma lista generica (Usuario/Cliente)*/
#include <string.h>
#include "lib_listagen.h"
#define USUARIO 0
#define CLIENTE 1

//--------- ESTRUTURAS ---------
struct listagen{
	Pessoa* pessoa;
	struct listagen* prox;
};

struct pessoa{
	int tipo;
	void* info;
	int codigo;
	char nome[30];
	char dataCadastro[12];
};

struct cliente{
	char email[30];
	char endereco[50];
	char telefone[12];
};

struct usuario{
	char login[20];
	char senha[12];
};

//-------- FUNCOES BASICAS ----------
Pessoa* Cria_pessoa(){
	Pessoa* novaPessoa = (Pessoa*) malloc(sizeof(Pessoa*));
	//verifica erro
	if(novaPessoa == NULL)
	{
		printf("Memoria insuficiente");
		exit(1);	
	}
	novaPessoa->info = NULL;
	//coleta os dados da pessoa
	printf("Informe o Codigo de cadastro: ");
	scanf("%d",&novaPessoa->codigo);
	printf("Informe a Data de cadastro: ");
	scanf("%s",novaPessoa->dataCadastro);
	printf("Informe o Nome: ");
	scanf("%s",novaPessoa->nome);
	//retorna o tipo Pessoa preenchido
	return novaPessoa;
}

Pessoa* Cria_usuario(){
	Pessoa* novaPessoa = Cria_pessoa();
	Usuario* novoUsuario  = (Usuario*) malloc(sizeof(Usuario*));
	//verifica erro
	if(novoUsuario == NULL)
	{
		printf("Memoria insuficiente");
		exit(1);	
	}
	//preenche os valores
	printf("Informe o Login do usuario: ");
	scanf("%s",novoUsuario->login);
	printf("Informe a Senha do usuario: ");
	scanf("%s",novoUsuario->senha);
	//joga Usuario para dentro de Pessoa
	novaPessoa->tipo = USUARIO;
	novaPessoa->info = novoUsuario;
	//retorna o tipo pessoa preenchido
	return novaPessoa;
}

Pessoa* Cria_cliente(){
	Pessoa* novaPessoa = Cria_pessoa();
	Cliente* novoCliente = (Cliente*) malloc(sizeof(Cliente*));
	//verifica erro
	if(novoCliente == NULL)
	{
		printf("Memoria insuficiente");
		exit(1);	
	}
	//preenche os valores
	printf("Informe o Email do cliente: ");
	scanf("%s",novoCliente->email);
	printf("Informe o Endereco do cliente: ");
	scanf("%s",novoCliente->endereco);
	printf("Informe o Telefone do cliente: ");
	scanf("%d",novoCliente->telefone);
	//joga Cliente para dentro de Pessoa
	novaPessoa->tipo = CLIENTE;
	novaPessoa->info = (Cliente*) novoCliente;
	//retorna o tipo pessoa preenchido
	return novaPessoa;
}

Listagen* Cria_Listagen(){
	Listagen* novaListagen = (Listagen *) malloc(sizeof(Listagen*));
	//verifica erro
	if(novaListagen == NULL)
	{
		printf("Memoria insuficiente");
		exit(1);	
	}
	novaListagen->prox = NULL;
	//retorna novaListagen
	return novaListagen;
}

// --------- FUNÇÕES DE CONTROLE -------

Listagen* Insere(Listagen* p){
	Listagen* novaListagen = Cria_Listagen();
	int escolha;
	//pergunta o tipo de usuario a ser criado
	printf("\nQual tipo de usuario deseja criar? (1-Usuario / 2-Cliente)");
	scanf("%d",&escolha);
	while(escolha != 1 && escolha != 2)
	{
		printf("\nQual tipo de usuario deseja criar? (1-Usuario / 2-Cliente)");
		scanf("%d",&escolha);
	}
	//preeche de acordo com a escolha
	if(escolha == 1)
		novaListagen->pessoa = (Pessoa*) Cria_usuario();
	else
		novaListagen->pessoa = (Pessoa*) Cria_cliente();
		
	if(p == NULL)
		p = novaListagen;
	else
	{	
		novaListagen->prox = p;
		p = novaListagen;
	}
	return p;
}

void Imprime(Listagen* p)
{
	Listagen* aux;
	Cliente* clienteAux;
	Usuario* usuarioAux;
	aux = p;
	//percorre a lista
	while(aux->prox != NULL)
	{
		if(aux->pessoa->tipo == CLIENTE)
		{
			printf("Dados do Cliente:\n");
			printf("Codigo: %d\n",aux->pessoa->codigo);
			printf("Data Cadastro: %s\n",aux->pessoa->dataCadastro);
			printf("Nome: %s\n",aux->pessoa->nome);
			clienteAux = (Cliente*) aux->pessoa->info;
			printf("Email: %s\n",clienteAux->email);
			printf("Endereco: %s\n",clienteAux->endereco);
			printf("Telefone: %s\n",clienteAux->telefone);
		}
		else
		{
			printf("Dados do Usuario:\n");
			printf("Codigo: %d\n",aux->pessoa->codigo);
			printf("Data Cadastro: %s\n",aux->pessoa->dataCadastro);
			printf("Nome: %s\n",aux->pessoa->nome);
			usuarioAux = (Usuario*) aux->pessoa->info;
			printf("Login: %s\n",usuarioAux->login);
			printf("Senha: %s\n",usuarioAux->senha);
		}
	aux = aux->prox;
	}
}

int Login(Listagen* p)
{
	Listagen* aux = p;
	Usuario* usuarioAux;
	char login[20];
	char senha[12];
	int achou = 0;

	printf("Insira o Login do Usuario: ");
	scanf("%s",login);
	printf("Insira a Senha do Usuario: ");
	scanf("%s",senha);
	
	while(aux->prox!=NULL && achou != 1)
	{
		if(aux->pessoa->tipo == USUARIO)
		{
			usuarioAux = (Usuario*) aux->pessoa->info;
			if(strcmp(login,usuarioAux->login)==0)
				if(strcmp(senha,usuarioAux->senha)==0)
					achou = 1;
		}
	aux = aux->prox;
	}
	return achou;
}
