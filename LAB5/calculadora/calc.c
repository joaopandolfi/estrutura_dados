/* Nome: João Carlos Pandolfi Santana
Data: 12/06/2014
Objetivo: LAB5 - Calculadora*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "calc.h"
struct calc{
char f[21]; //formato para impressão
Pilha* p; //pilha de operandos
};

struct pilha{
	float val;
	struct pilha* prox;
};

Pilha* cria()
{
	return NULL;
}

void push(Pilha* p, float val)
{
	Pilha* novo = (Pilha*) malloc(sizeof(Pilha));
	novo->val = val;
	novo->prox = p;
	p = novo;
}

float pop(Pilha* p)
{
	Pilha* aux;
	float val;
	val = p->val;
	aux = p;
	p = p->prox;
	free(aux);
	return val;
}

int vazia(Pilha* p)
{
	return p == NULL;
}

Calc* cria_calc(char* formato){
Calc* c = (Calc*) malloc(sizeof(Calc));
strcpy(c->f, formato);
c->p=cria(); //cria pilha vazia
return c;
}

void operando(Calc* c, float v){
//empilha operando
push(c->p,v);
//empilha topo da pilha
printf(c->f,v);
}

void operador(Calc* c, char op){
float v1,v2,v;
if (vazia(c->p)) //desempilha
v2=0;
else
v2=pop(c->p);
if (vazia(c->p))
v1=0;
else
v1=pop(c->p);
switch(op) { //faz operação
case '+': v = v1 + v2; break;
case '-': v = v1 - v2; break;
case '*': v = v1 * v2; break;
case '/': v = v1/v2; break;
case 'r': v = sqrt(v1); break; 
case '^': v = pow(v1,v2); break;
}
push (c->p,v); //empilha resultado
printf(c->f,v); //imprime resultado
}
