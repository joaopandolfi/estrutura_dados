// Leonardo Camilo Ribeiro
// 
// O programa tem por finalidade testar a estrutura pilha e aplica-la em algum caso de uso.

#include <stdlib.h>
#include <stdio.h>
#include "tad-mouse.h"

#define sys "cls" //caso seja linux trocar para "clear"

void main(){
	char opcao, flag;
	tipo_matriz mat;
	
	while(1){
		system(sys);
		createMap(mat);					// cria o mapa
		flag = putPathOnMap(mat);		// desenha o caminho no mapa, descobre o caminho usando a função findPath
		printMap(mat);
		
		if(flag == 0)
			printf("\n\n Sem saida.");
		
		printf("\n gerar outro? (s/n): ");
		scanf("%c",&opcao);
		if(opcao == 'n')
			break;
	}
}