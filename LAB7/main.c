/* Nome: João Carlos Pandolfi Santana
Data: 30/07/2014
Objetivo: LAB7 - Arvore*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "arvore.h"
#include "arquivo.h"

int main(){
Arv* principal = inicializaArv();
principal = pesquisaReferencias();
geraSaida(principal);
printf("Saida Gerada com sucesso!\n");
return 0;
}
