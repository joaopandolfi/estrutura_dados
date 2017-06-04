#include "lib_racional.h"

struct racional
{
	int num;
	int den;
};

int getN(Racional* x)
{
	return x->num;
}

int getD(Racional* x)
{
	return x->den;
}

Racional* set(int num, int den)
{
	Racional* racional = (Racional*)malloc(sizeof(Racional));
	if(racional == NULL)
	{
		printf("Memoria insuficiente");
		exit(1);	
	}
	racional->num = num;
	racional->den = den;
}

void libera(Racional* x)
{
		free(x);
}

Racional* add(Racional* x, Racional* y)
{
	int den, num;
	num = (getD(x)*getN(y))+(getN(x)*getD(y));
	den = (getD(x)*getD(y));
	Racional* result = set(num,den);
	return result;
}

Racional* sub(Racional* x, Racional* y)
{
	int den, num;
	num = (getD(x)*getN(y))-(getN(x)*getD(y));
	den = (getD(x)*getD(y));
	Racional* result = set(num,den);
	return result;
}

Racional* mul(Racional* x, Racional* y)
{
	int den, num;
	num = (getN(x)*getN(y));
	den = (getD(x)*getD(y));
	Racional* result = set(num,den);
	return result;
}

Racional* divide(Racional* x, Racional* y)
{
	int den, num;
	num = (getN(x)*getD(y));
	den = (getD(x)*getN(y));
	Racional* result = set(num,den);
	return result;
}

char* notation(Racional* x)
{
	char s[50];
	sprintf(s, "%i/%i", getN(x),getD(x));
	return s;
}
