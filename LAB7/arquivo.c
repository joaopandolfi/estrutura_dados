/* Nome: João Carlos Pandolfi Santana
Data: 30/07/2014
Objetivo: LAB7 - Arvore*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "arvore.h"

// ============ DEFINES ===============
#define ARQ_REF "referencia.txt"
#define ARQ_TEXTO "texto.txt"
#define ARQ_SAIDA "saida.txt"

// ====== FUNÇÕES DO PROBLEMA =========

//verifica se o caracter é separador
int eSeparador(char caracter){
	switch(caracter)
	{
		case ' ':
		case ',':
		case '.':
		case ')': 
		case '(': 
		case '*': 
		case '-': 
		case '_':
		case '\n':
		return 1; 
		break;
	}
	return 0;
}

//pesquisa palavra no texto e retorna a lista de referencia
Lista* pesquisaPalavra(char* pal){
	//variaveis de dados
	char buffer[30];//maior palavra na lingua portuguesa 29 letras
	FILE *arq = fopen(ARQ_TEXTO,"r"); //abro arquivo [modo leitura]
	Lista* referencias = inicializaLista(); 

	//variaveis de controle
	int countLinha = 1;
	int buffCounter = 0;
	char* caracter = NULL;
	
	//limpeza do buffer
	memset(buffer,'\0',30);
	
	while (!feof(arq)) {
		//leio um caracter por vez
		caracter = fgetc(arq); 
		if (eSeparador(caracter)){
			//verifico se a palavra no buffer é a que estou procurando
			if(strcmp(buffer,pal) == 0)
				referencias = insereNaLista(referencias,countLinha);
			//limpo buffer e reseto counter do buffer
			memset(buffer,'\0',30);
			buffCounter = 0;
			//se for [enter] incremento o contador de linha
			if(caracter=='\n')
				countLinha++;
		}
		else{
			//se nao for separador coloco no buffer
 			buffer[buffCounter] = caracter;
 			buffCounter++;
		}
   }
   //fecho arquivo
   fclose(arq);
   return referencias;
}

//le as refencias do arquivo e procura no texto [retorna arvore]
Arv* pesquisaReferencias(){
	//variaves de dados
	char buffer[30];//maior palavra na lingua portuguesa 29 letras
	FILE *arq = fopen(ARQ_REF,"r"); //abro arquivo [modo leitura]
	Arv* arvore = inicializaArv();
	Lista* auxList = inicializaLista();
	
	//variaveis de controle
	int buffCounter = 0;
	char* caracter = NULL;

	//limpeza do buffer
	memset(buffer,'\0',30);

	while (!feof(arq)) {
		//leio um caracter por vez
		caracter = fgetc(arq); 
		//se for[enter] quer dizer que posso procurar a palavra
		if(caracter == '\n'){
			auxList = inicializaLista();
			auxList = pesquisaPalavra(buffer);
			//se a lista nao retornar vazia, encontrou a palavra em algum lugar
			if (!listaVazia(auxList))
				arvore = insereArv(arvore,buffer,auxList);
			//reseto o buffer
			memset(buffer,'\0',30);
			buffCounter = 0;
		}
		else{
			//se nao for [enter] jogo para o buffer
			buffer[buffCounter] = caracter;
			buffCounter++;
		}
	}
	//fecho arquivo
	fclose(arq);
	return arvore;
}

//cria o arquivo de saida
void geraSaida(Arv* arvore){
	FILE *arq = fopen(ARQ_SAIDA,"w"); //abro arquivo [modo escrita]
	imprimeArv(arvore,arq);
	fclose(arq);//fecho arquivo
}
