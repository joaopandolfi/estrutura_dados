#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib-rato.h"

// ========= Estruturas =============

struct pilha {
	Posicao c;
	Pilha* prox; 
};

// ====== Funções Básicas ===========

int Vazia(Pilha* p)
{
	return p == NULL;
}

Pilha* InicializaPilha()
{
	return NULL;
}

Pilha* CriaPilha(){
	Pilha* novaPilha = (Pilha*) malloc(sizeof(Pilha*));
	if(novaPilha == NULL)
	{
		printf("\nMemoria Insuficiente");
		exit(1);
	}
	novaPilha->prox = NULL;
	return novaPilha;
}

Pilha* Push(Pilha* p, Posicao c)
{
	Pilha* nova = CriaPilha();
	nova->prox = p;
	nova->c = c;
	return nova;
}

Pilha* Pop(Pilha* p)
{
	Posicao c;
	Pilha* aux;
	aux = p;
	c = p->c;
	p = p->prox;
	free(aux);
	return p;
}

void Libera(Pilha* p)
{
	Pilha* aux;
	while(p != NULL)
	{	
		aux = p;
		p = p->prox;
		free(aux);
	}
}

// === Controle da Coordenada ====

Posicao ConverteXY(int x, int y)
{
	return (x*100)+y;
}

Pilha* InsereCoordenada(Pilha* p, Posicao pos)
{
	return Push(p,pos);
}

Posicao RecuperaCoordenada(Pilha* p)
{
	return p->c;
}

int PegaX(Posicao c)
{
	return c/100;
}

int PegaY(Posicao c)
{
	return c%100;
}

// ====== Funções do problema =======
void CriaMapa(tipo_matriz m)
{
	int x,y;
	//controle do aleatorio
	srand(time(NULL));

	for(x=0;x<TAM;x++)
		for(y=0;y<TAM;y++)
		{
			if(rand()%10 < 3)
				m[x][y] = parede;
			else
				m[x][y] = livre;
		}
	
	//faz as paredes do mapa	
	for(x=0;x<TAM;x++)
	{
		m[0][x] = parede; //esquerda
		m[x][0] = parede; //cima
		m[TAM-1][x] = parede; //direita
		m[x][TAM-1] = parede; //baixo
	}
	//define ponto incial e saida
	m[2][2] = rato;
	m[TAM-2][TAM-1] = saida;
}

void ImprimeMapa(tipo_matriz m)
{
	int x,y;
	printf("\n");
	for(x=0;x<TAM;x++)
	{		
		printf("\n");
		for(y=0;y<TAM;y++)
			switch(m[x][y])
			{
				case livre:
					printf(" ");
				break;
				case parede:
					printf("%c",219);
				break;
				case visitada:
					printf(".");
				break;
				case rato:
					printf("@");
				break;
				case beco:
					printf("%c",176);
				break;
				case saida:
					printf("X");
				break;
			}
	}
}

void AchaCaminho(tipo_matriz m)
{
	Pilha* caminho = InicializaPilha();
	Posicao p;
	int x,y,controle;
	//posição inicial
	x = 2;
	y = 2;
	controle = 1;
	while(controle)
	{
		if(x+1 < TAM && (m[x+1][y] == livre || m[x+1][y] == saida)) //para direita
		{
			m[x][y] = visitada;
			p = ConverteXY(x,y);
			caminho = InsereCoordenada(caminho,p);
			if(m[x+1][y] == saida)
				controle = 0;
			else
				x = x+1;
		}
		else if(y-1 >=0 && (m[x][y-1] == livre || m[x][y-1] == saida)) //para cima
		{
			m[x][y] = visitada;
			p = ConverteXY(x,y);
			caminho = InsereCoordenada(caminho,p);
			if(m[x][y-1] == saida)
				controle = 0;
			else
				y = y-1;
		}
		else if(x-1 >= 0 && (m[x-1][y] == livre || m[x-1][y] == saida)) //para esquerda
		{
			m[x][y] = visitada;
			p = ConverteXY(x,y);
			caminho = InsereCoordenada(caminho,p);
			if(m[x-1][y] == saida)
				controle = 0;
			else
				x = x-1;
		}
		else if(y+1 < TAM && (m[x][y+1] == livre || m[x][y+1] == saida)) //para baixo
		{
			m[x][y] = visitada;
			p = ConverteXY(x,y);
			caminho = InsereCoordenada(caminho,p);
			if(m[x][y+1] == saida)
				controle = 0;
			else
				y = y+1;			
		}
		else //beco
		{
			m[x][y] = beco;
			if(Vazia(caminho))
			{
				printf("\nLabirinto Sem saida!");
				controle = 0;
			}
			else
			{
				p = RecuperaCoordenada(caminho);
				x = PegaX(p);
				y = PegaY(p);
				caminho = Pop(caminho);
			}
		}
	}
	Libera(caminho);
}
