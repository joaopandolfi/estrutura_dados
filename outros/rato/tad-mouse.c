#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tad-mouse.h"
#include "tad-stack.h"

void createMap(tipo_matriz mat){
	int i,j; 
	srand(time(NULL));
	
	for(i=0;i<TAM; i++)
		for(j=0;j<TAM; j++){
			if(rand()%(TAM/2) == 0){
				mat[i][j]=parede; 
			}else{
				mat[i][j]=livre;
			}				
		}

	for(i=0;i<TAM; i++){ 
		mat[0][i] = parede; 
		mat[i][0] = parede;  
		mat[TAM-1][i] = parede; 
		mat[i][TAM-1] = parede;  
	}
		
	mat[1][1]=mouse; 
	mat[TAM-2][TAM-1]=livre;
}

void printMap(tipo_matriz mat){
	int i,j;
	for(i=0;i<TAM; i++){
		for(j=0;j<TAM; j++){
			switch(mat[i][j]){
				case livre:
					printf(" ");
					break;

				case visitada:
					printf(" ");
					break;
				
				case parede:
					printf("%c",219);
					break;

				case path:
					printf(".");
					break;

				case mouse:
					printf("%c",2);
			}
		}
		printf("\n");
	}
}


Stack* findPath(tipo_matriz mat){ 
	int i,j;
	Stack* stack = inicializa();
	stack = push(stack,1,1);		// primeira posicao

	while(stack != NULL){
		i = getCordenateI(stack);
		j = getCordenateJ(stack);

		mat[i][j] = visitada;
		
		if(i==(TAM-2) && j==(TAM-1))
			return stack;

		if(j<(TAM-1) && mat[i][j+1] == livre){
			stack = push(stack,i,j+1);
			continue;
		}
		
		if(i<(TAM-1) && mat[i+1][j] == livre){
			stack = push(stack,i+1,j);
			continue;
		}

		if(i>0 && mat[i-1][j] == livre){
			stack = push(stack,i-1,j);
			continue;
		}

		if(j>0 && mat[i][j-1] == livre){
			stack = push(stack,i,j-1);
			continue;
		}

		stack = pop(stack);
	}
	
	return stack;
}

int putPathOnMap(tipo_matriz mat){
	Stack* stack = findPath(mat);
	mat[1][1] = mouse;
	
	if(stack==NULL)
		return 0;

	while(stack != NULL){
		mat[getCordenateI(stack)][getCordenateJ(stack)] = path;
		stack = pop(stack);
	}

	mat[1][1] = mouse;
	return 1;
}
