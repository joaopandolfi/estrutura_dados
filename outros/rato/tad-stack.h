
typedef struct stack Stack; // pilha de coordenadas

Stack* inicializa(); // inicializa a pilha

Stack* push(Stack* stack,int i,int j); // coloca uma nova estrutura no topo da pilha e retorna seu novo endereço

Stack* pop(Stack* stack); //retira o primeiro elemento da pilha e retorna seu novo endereço

int getCordenateI(Stack* stack); //ler o elemento I do top da pilha

int getCordenateJ(Stack* stack); //ler o elemento J do top da pilha

void freeStack(Stack* stack); // libera a pilha da memoria

void printStack(Stack* stack); //para debug