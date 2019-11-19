#include <stdio.h>
#include <stdlib.h>
#include "contas.h"

int main()
{
	char op;

	system("clear");
	printf("Minha calculadora!\n\n");

	do
	{
		printf("Digite uma operacao (+, -, x, %% ou E para sair: \n");

		scanf(" %c", &op);

		switch(op)
		{
			case '+': adicao(); break;
			case '-': subtracao(); break;
			case 'x': multiplicacao(); break;
			case '%': divisao(); break;
			case 'E': break;
			default: printf("Opcao invalida!\n");
		}
	} while(op != 'E');

	return 0;
}