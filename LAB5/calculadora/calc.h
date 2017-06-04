/* Nome: João Carlos Pandolfi Santana
Data: 12/06/2014
Objetivo: LAB5 - Calculadora*/
typedef struct calc Calc;
typedef struct pilha Pilha;
Calc* cria_calc(char* f);
void operando(Calc* c , float v);
void operador(Calc* c, char op);
void libera_calc(Calc* c);
int vazia(Pilha* p);
float pop(Pilha* p);
void push(Pilha* p, float val);
Pilha* cria();
