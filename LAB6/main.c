#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "pilha.h"
#include "labv1.h"

int main(){
	Fila* teste = InicialiazaFila();
	Fila* organizada = NULL;
	insere(teste, 20,1,"joao");
	insere(teste, 2,0,"bacalhau");
	insere(teste, 60,1,"as");
	insere(teste, 40,0,"hue");
	insere(teste, 3,0,"pipoca");
	insere(teste, 8,0,"goiaba");
	insere(teste, 22,1,"jaca");
	
	printf("\n Lista \n");
	imprimeFila(teste);
	
	organizada = organizaFila(teste);
	
	return 0;
}
