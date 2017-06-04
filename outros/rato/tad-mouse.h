#include "tad-stack.h"

#define TAM 15

enum marca { livre=1, parede=2, visitada=3, mouse=4, path=5}; 

typedef enum marca tipo_marca; 

typedef tipo_marca tipo_matriz[TAM][TAM];

void createMap(tipo_matriz mat); // cria um mapa aleatório

void printMap(tipo_matriz mat); // printa o mapa na tela

Stack* findPath(tipo_matriz mat); // acha a saida e retorna uma pilha com as cordenadas do caminho

int putPathOnMap(tipo_matriz mat);