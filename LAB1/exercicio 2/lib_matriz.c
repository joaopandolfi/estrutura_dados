#include "lib_matriz.h"

struct matriz
{
	float val;
	struct matriz* p_linha;
	struct matriz* p_coluna;
};

Matriz* newMat()
{
	Matriz* result = (Matriz*)malloc(sizeof(Matriz));
	if(result == NULL)
	{
		printf("\nMemoria Insufuciente\n");
		exit(1);
	}
	return result;
}

Matriz* cria(int m, int n)
{
	int i ,j;
	Matriz* primeiro;
	Matriz* linha;
	Matriz* aux1;
	Matriz* aux2;
	primeiro = newMat();
	aux1 = primeiro;
	//preenche a primeira coluna
	for(i=1;i<=m;i++)
	{
		aux2 = newMat(); 		//aloco memoria
		aux1->p_linha = aux2;   //coloco o anterior para concatenar com o atual
		aux1 = aux2; 			// atualizo aux1
	}
	
	//atualizo os ponteiros
	linha = primeiro;
	aux1 = primeiro;
	
	//preenche o resto da matriz da segunda coluna em diante
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			aux2 = newMat();
			aux1->p_coluna = aux2;
			aux1 = aux2;
		}
		linha = linha->p_linha;
		aux1 = linha;
	}

	return primeiro;
}

void libera(Matriz* mat)
{
	Matriz* linha;
	Matriz* auxLinha;
	Matriz* coluna;
	Matriz* auxColuna;
	
	for(linha = mat;linha->p_linha != NULL; linha = linha->p_linha)
	{
		auxLinha = linha->p_linha; //guardo a prox posicao
		for(coluna = linha; coluna->p_coluna != NULL; coluna = coluna->p_coluna)
		{
			auxColuna = coluna->p_coluna; //guardo a prox posicao na aux
			free(coluna);				  //libero a atual
			coluna = auxColuna;			  //atualizo "coluna"
		}
		linha = auxLinha; 		//resgato a prox posicao
	}
}

float acessa(Matriz* mat, int i, int j)
{
	int l,c;
	Matriz* aux;
	aux = mat;
	
	//navega até a linha
	for(l=0;l<i && aux->p_linha != NULL;l++)
		aux = aux->p_linha;
	
	//navega até a coluna	
	for(c=0;l<j && aux->p_coluna != NULL;c++)
		aux = aux->p_coluna;
		
	//retorna o valor
	return aux->val;
}

void atribui(Matriz* mat, int i, int j, float v)
{
	int l,c;
	Matriz* aux;
	aux = mat;
	
	//navega até a linha
	for(l=0;l<i && aux->p_linha != NULL;l++)
		aux = aux->p_linha;
	
	//navega até a coluna	
	for(c=0;l<j && aux->p_coluna != NULL;c++)
		aux = aux->p_coluna;
		
	//atualiza o valor
	aux->val = v;
}

int linhas(Matriz* mat)
{
	int l;
	Matriz* aux;
	aux = mat;
	
	//navega pelas linhas
	for(l=0;aux->p_linha != NULL;l++)
		aux = aux->p_linha;
			
	//retorno o valor
	return l;	
}

int colunas(Matriz* mat)
{
	int c;
	Matriz* aux;
	aux = mat;
	
	//navega pelas linhas
	for(c=0;aux->p_coluna != NULL;c++)
		aux = aux->p_coluna;
			
	//retorno o valor
	return c;	
}
