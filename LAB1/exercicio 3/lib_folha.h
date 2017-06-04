typedef struct ficha Ficha;
//aloca memoria para uma nova ficha
Ficha* novaFicha();
//preenche uma ficha
Ficha* preenche(Ficha* var);
//adiciona um novo valor a lista
void adiciona(Ficha* primeiro, Ficha* novo);
//funçoes de calculo
float novoSalarioBase(Ficha* funcionario, float salarioRef);
float calculaSalarioHoraNormal(int horasNormais, float salarioRef);
float calculaSalarioHoraExtra(int horasExtras, float salarioRef);
float calculaDescontoINSS(float salarioHoraNormal, float salarioHoraExtra);
float calculaSalarioFinal(float salarioHoraNormal, float salarioHoraExtra, float descontoINSS);
//imprime o contracheque
void imprimeContracheques(Ficha* primeiro, float salarioRef);
