/* Nome: João Carlos Pandolfi Santana
Data: 13/05/2014
Objetivo: O programa tem como objetivo uma lista generica (ContaCorrente/ContaPoupanca)*/
typedef struct listagen Listagen;
typedef struct conta Conta;
typedef struct contaPoupanca ContaPoupanca;
typedef struct contaCorrente ContaCorrente;
Conta* Cria_conta();
Conta* Cria_corrente();
Conta* Cria_poupanca();
Listagen* Cria_Listagen();
Listagen* Insere(Listagen* p);
void Imprime(Listagen* p);
void Debitar(Listagen* p);
