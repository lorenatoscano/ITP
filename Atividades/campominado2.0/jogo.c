#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void jogo(int, int, int);
void prepara_campo(int**, int, int, int);
void prepara_exibicao(char**, int, int);
void imprime_tabuleiro(char**, int, int);
void mostra_mina(int**, char**, int, int);
void checa_mina(int, int, int**, char**, int, int);

int main()
{
	int option;

	srand(time(NULL));
	system("clear");

	printf("ESCOLHA A DIFICULDADE:\n");
	printf("1 - Fácil (9x9)\n");
	printf("2 - Médio (16x16)\n");
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
		default: printf("Opção inválida!\n");
	}

	getchar();
	getchar();

	return 0;
}

void jogo(int lin, int col, int bomb)
{
	int** campo; //Localizacao das bombas
	char** exibicao; //O que o jogador ve
	int i, j, x, y, ok = 1;
	char action;

	//Aloca as matrizes
	campo = malloc(sizeof(int*) * lin);
	for (i = 0; i < lin; i++)
		campo[i] = malloc(sizeof(int) * col);

	exibicao = malloc(sizeof(char*) * lin);
	for (i = 0; i < lin; i++)
		exibicao[i] = malloc(sizeof(char) * col);

	//Preenche as matrizes
	prepara_campo(campo, lin, col, bomb);
    prepara_exibicao(exibicao, lin, col);

    //Executa o jogo
	do
	{
		system("clear");

		//Imprime o tabuleiro para o usuario
		imprime_tabuleiro(exibicao, lin, col);

		//Le as coordenadas e a açao
		printf("\nInsira as coordenadas e ação que deseja fazer (A para abrir e B para marcar como bomba):\n");
		scanf("%d %d %c", &x, &y, &action);
		if (x > lin || y > col)
		{
			printf("Valores inválidos!\n");
		}
		else
		{
			switch(action)
			{
				case 'A':
					if (campo[x - 1][y - 1]) //perdeu
					{
						exibicao[x - 1][y - 1] = 'x';
						mostra_mina(campo, exibicao, lin, col);
						ok = 0;
					}	
					else 
						checa_mina(x - 1, y - 1, campo, exibicao, lin, col);
					break;
				case 'B':
					exibicao[x - 1][y - 1] = 'B';
					break;
				default: 
					printf("Opção inválida!\n");
			}
		}
		getchar();
		getchar(); 

	} while(ok);
}

void prepara_campo(int** mat, int lin, int col, int n)
{
	//Insere a quantidade de bombas aleatoriamente
	int i, j;

	while (n > 0)
	{
		i = rand() % lin;
		j = rand() % col;

		while (mat[i][j])
		{
			i = rand() % lin;
			j = rand() % col;
		}

		mat[i][j] = 1;
		n--;
	}
}

void prepara_exibicao(char** mat, int lin, int col)
{
	// Preenche a matriz com asteriscos
	int i, j;
  
    for (i = 0; i < lin; ++i)
		for (j = 0; j < col; ++j)
			mat[i][j] = '*';
}

void imprime_tabuleiro(char** mat, int lin, int col)
{
	int i, j;

	//Imprime a primeira linha com os numeros
	printf("  ");
	for(i = 1; i <= lin; i++)
	{
		if (i < 10) printf(" 0%d", i);
		else printf(" %d", i);
	} 
	printf("\n");

	//Imprime a coluna lateral e o resto da matriz
	for (i = 0; i < lin; ++i)
	{
		if (i < 9) printf("0%d  ", i+1);
		else printf("%d  ", i+1);

		for (j = 0; j < col; ++j)
			printf("%c  ", mat[i][j]);
		printf("\n");
	}

}

void checa_mina(int x, int y, int** campo, char** exibicao, int lin, int col)
{
	int i, j, qtd = 0;

	// //Condicao de parada: há bombas ao redor
	// if(qtd > 0) 
	// 	exibicao[x][y] = qtd + '0';
	// else
	// {
		
	// }

	// printf("Checando minas...\n");

}

void mostra_mina(int** campo, char** exibicao, int lin, int col)
{
	int i, j;

	system("clear");
	imprime_tabuleiro(exibicao, lin, col);

	printf("BOOOM! Você perdeu!\n\n");

	
	getchar();
	getchar();

	//Imprime a localizacao de todas as bombas
}
