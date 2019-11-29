#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef FUNCOES_H
#define FUNCOES_H

typedef struct
{
	char nome[100];
	int vit;
	int emp;
	int der;
	int gf;
	int gs;
	int pont;
	int sg; 
} Time;

//Funcoes que mexem no arquivo ou no vetor
Time* carrega_dados(int* tam);
void ordena_times(Time* camp, int tam);

//Funcoes de impressao
void imprime_tabela(Time* camp, int tam);
void imprime_time(Time atual);


#endif