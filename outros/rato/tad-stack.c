#include <stdlib.h>
#include <stdio.h>
#include "tad-stack.h"

struct stack{
	int i;
	int j;
	Stack* next;
};

Stack* inicializa(){
	return NULL;
}

Stack* push(Stack* stack,int i,int j){
	Stack* newNode = (Stack*)malloc(sizeof(Stack));
	newNode->i = i;
	newNode->j = j;
	newNode->next = stack;
	return newNode;
}

Stack* pop(Stack* stack){
	Stack* temp = stack;
	stack = stack->next;
	free(temp);
	return stack;
}

int getCordenateI(Stack* stack){
	return stack->i;
}

int getCordenateJ(Stack* stack){
	return stack->j;
}

void freeStack(Stack* stack){
	while(stack != NULL)
		pop(stack);
}

void printStack(Stack* stack){
	while(stack != NULL){
		printf(" i = %d\t j = %d\n",stack->i,stack->j);
		stack = stack->next;
	}
}