typedef struct no Pilha;

//Pilha
Pilha* CriaPilha();
Pilha* InicializaPilha();
int Vazia(Pilha* p);
Pilha* Push(Pilha* p, int cod, int prio, char* nome);
Pilha* Pop(Pilha* p);
void Libera(Pilha* p);
Pilha* PushOrdenado(Pilha* pilha, int cod, int prio, char* nome);
Pilha* JuntaPilhas(Pilha* p1, Pilha* p2);
