#include "lib_folha.h";

struct ficha 
{
	int inscricao;
	char nome[50];
	int classe;
	int horasNormais;
	int horasExtras;
	struct ficha* proximo;
};

Ficha* novaFicha()
{
	Ficha* result = (Ficha*)malloc(sizeof(Ficha));
	if(result == NULL)
	{
		printf("\nMemoria Insufuciente\n");
		exit(1);
	}
	return result;
}

Ficha* preenche(Ficha* var)
{
	printf("\n#### FICHA #####");
	printf("\nNumero de Inscricao: ");
	scanf("%d",&var->inscricao);
	printf("Nome: ");
	scanf("%s",var->nome);
	printf("Classe: ");
	scanf("%d",&var->classe);
	printf("Horas Normais: ");
	scanf("%d",&var->horasNormais);
	printf("Horas Extras: ");
	scanf("%d",&var->horasExtras);
	return var;
}

void adiciona(Ficha* primeiro, Ficha* novo)
{
	Ficha* aux;
	aux = primeiro;
	while (aux->proximo != NULL)
		aux = aux->proximo;
	//neste momento aux possui a ultima posição
	aux->proximo = novo;
}

float novoSalarioBase(Ficha* funcionario, float salarioRef)
{
	if(funcionario->classe == 1)
		return salarioRef*1.3;
	else
		return salarioRef*1.9;
}

float calculaSalarioHoraNormal(int horasNormais, float salarioRef)
{
	return horasNormais*salarioRef;
}

float calculaSalarioHoraExtra(int horasExtras, float salarioRef)
{
	return (horasExtras*1.3)*salarioRef;
}

float calculaDescontoINSS(float salarioHoraNormal, float salarioHoraExtra)
{
	return (salarioHoraNormal+salarioHoraExtra)*0.11;
}

float calculaSalarioFinal(float salarioHoraNormal, float salarioHoraExtra, float descontoINSS)
{
	return (salarioHoraNormal+salarioHoraExtra) - descontoINSS;
}

void imprimeContracheques(Ficha* primeiro, float salarioRef)
{
	Ficha* aux;
	float novoSalarioRef;
	float salarioHoraNormal;
	float salarioHoraExtra;
	float descontoINSS;
	float salarioFinal;
	printf("\n######## CONTRACHEQUES ########");
	//percorro a lista
	for(aux = primeiro; aux != NULL; aux=aux->proximo)
	{
		//faz os calculos
		novoSalarioRef = novoSalarioBase(aux, salarioRef);
		salarioHoraNormal = calculaSalarioHoraNormal(aux->horasNormais,salarioRef);
		salarioHoraExtra = calculaSalarioHoraExtra(aux->horasExtras,salarioRef);
		descontoINSS = calculaDescontoINSS(salarioHoraNormal,salarioHoraExtra);
		salarioFinal = calculaSalarioFinal(salarioHoraNormal,salarioHoraExtra,descontoINSS);
		//imprime os dados na tela
		printf("\n#############################################");
		printf("\nNUMERO DE INSCRICAO: %d",aux->inscricao);
		printf("\nNOME: %s",&aux->nome);
		printf("\nSALARIO HORAS NORMAIS: %f",salarioHoraNormal);
		printf("\nSALARIO HORAS EXTRAS: %f",salarioHoraExtra);
		printf("\nREDUCAO DE INSS: %f",descontoINSS);
		printf("\nSALARIO LIQUIDO: %f",salarioFinal);
	}
}
