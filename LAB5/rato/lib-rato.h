#define TAM 15
enum marca { livre=1, parede=2, visitada=3, beco=4, rato=5, saida=6};
typedef enum marca tipo_marca; 
typedef tipo_marca tipo_matriz[TAM][TAM];
typedef struct pilha Pilha;
typedef int Posicao;

//Mapa
void CriarMapa(tipo_matriz m);
void ImprimeMapa(tipo_matriz m);
void AchaCaminho(tipo_matriz m);

//Pilha
Pilha* CriaPilha();
Pilha* InicializaPilha();
int Vazia(Pilha* p);
Pilha* Push(Pilha* p, Posicao pos);
Pilha* Pop(Pilha* p);
void Libera(Pilha* p);

//Coodenada
Posicao ConverteXY(int x,int y);
Posicao RecuperaCoordenada(Pilha* p);
Pilha* InsereCoordenada(Pilha*p, Posicao pos);
int PegaX(Posicao pos);
int PegaY(Posicao pos);
