typedef struct no No;
typedef struct fila Fila;
typedef struct no Pilha;

Fila* InicialiazaFila();
No* ins_fim(No* fim, int cod, int prio, char* nome);
void insere(Fila* f, int cod, int prio, char* nome);
No* ret_ini(No* ini);
No* retira(Fila* f);
int vaziaFila(Fila* f);
void liberaFila(Fila* f);
void imprimeFila(Fila* f);

//Pilha
Pilha* CriaPilha();
Pilha* InicializaPilha();
int Vazia(Pilha* p);
Pilha* Push(Pilha* p, int cod, int prio, char* nome);
void Libera(Pilha* p);
Pilha* PushOrdenado(Pilha* pilha, int cod, int prio, char* nome);
Pilha* JuntaPilhas(Pilha* p1, Pilha* p2);


Fila* convertePilhaParaLista(Pilha* p);
Fila* organizaFila(Fila* f);
