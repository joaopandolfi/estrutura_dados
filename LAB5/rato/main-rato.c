#include <stdio.h>
#include <stdlib.h>
#include "lib-rato.h"
#define clean "cls" //windows -> "cls" | linux -> "clear"

int main()
{
	tipo_matriz matriz;
	char sair;
	while(1)
	{
		system(clean);
		CriaMapa(matriz);
		ImprimeMapa(matriz);
		AchaCaminho(matriz);
		ImprimeMapa(matriz);
		printf("\n\n Gerar outro mapa? (s/n): ");
		scanf("%c",&sair);
		if(sair == 'n')
			break;
	}
	
	return 0;	
}
