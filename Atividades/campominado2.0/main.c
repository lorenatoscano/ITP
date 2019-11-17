#include "jogo.h"

int main()
{
	int option;

	srand(time(NULL));
	system("clear");

	printf("BEM VINDO AO CAMPO MINADO!\n");
	printf("(Recomendamos jogar em tela cheia)\n\n");
	printf("ESCOLHA A DIFICULDADE:\n");
	printf("1 - Fácil (9x9)\n");
	printf("2 - Intermediário (16x16)\n");
	printf("3 - Difícil (16x30)\n");

	scanf("%d", &option);

	switch(option)
	{
		case 1: 
			jogo(9, 9, 10);
			break;
		case 2:
			jogo(16, 16, 40);
			break;
		case 3:
			jogo(16, 30, 99);
			break;
		default: 
			printf("Opção inválida!\n");
			getchar();
			getchar();
	}

	return 0;
}