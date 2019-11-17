#include "jogo.h"
#include "utils.h"

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
	for(i = 1; i <= col; i++)
	{
		if (i < 10) printf(" 0%d", i);
		else printf(" %d", i);
	} 
	printf("\n");

	//Imprime as colunas laterais e o resto da matriz
	for (i = 0; i < lin; ++i)
	{
		if (i < 9) printf("0%d  ", i+1);
		else printf("%d  ", i+1);

		for (j = 0; j < col; ++j)
			printf("%c  ", mat[i][j]);

		if (i < 9) printf("0%d  ", i+1);
		else printf("%d  ", i+1);
		printf("\n");
	}
	//Imprime a linha com os numeros
	printf("  ");
	for(i = 1; i <= col; i++)
	{
		if (i < 10) printf(" 0%d", i);
		else printf(" %d", i);
	} 
	printf("\n");

}
void imprime_campo(int** mat, int lin, int col)
{
	//Apenas para verificacao
	int i, j;
	printf(">>Campo por debaixo dos panos:\n");
	//Imprime a primeira linha com os numeros
	printf("  ");
	for(i = 1; i <= col; i++)
	{
		if (i < 10) printf(" 0%d", i);
		else printf(" %d", i);
	} 
	printf("\n");

	//Imprime as colunas laterais e o resto da matriz
	for (i = 0; i < lin; ++i)
	{
		if (i < 9) printf("0%d  ", i+1);
		else printf("%d  ", i+1);

		for (j = 0; j < col; ++j)
			printf("%d  ", mat[i][j]);

		if (i < 9) printf("0%d  ", i+1);
		else printf("%d  ", i+1);
		printf("\n");
	}
	//Imprime a linha com os numeros
	printf("  ");
	for(i = 1; i <= col; i++)
	{
		if (i < 10) printf(" 0%d", i);
		else printf(" %d", i);
	} 
	printf("\n");
}

void checa_mina(int x, int y, int** campo, char** exibicao, int lin, int col)
{
	int i, j, qtd = 0;

	//Identifica o tamanho da matriz por meio do numero maximo de bombas
	// if (n == 10) lin = col = 9;
	// else if (n == 40) lin = col = 16;
	// else if (n == 99)
	// {
	// 	lin = 16;
	// 	col = 30;
	// }

	//Verifica os arredores fazendo tratamento de borda
	if (x != 0) 
	{
		qtd += campo[x - 1][y];
		if (y != 0)
		{
			qtd += campo[x - 1][y - 1];
			qtd += campo[x][y - 1];
		}
		if (y != col) 
		{
			qtd += campo[x - 1][y + 1];
			qtd += campo[x][y + 1];
		}
	}
	if (x != lin) 
	{
		qtd += campo[x + 1][y];
		if (y != col) 
			qtd += campo[x + 1][y + 1];
		if (y != 0)
			qtd += campo[x + 1][y - 1];
	}
	

	//Há bombas ao redor
	if(qtd > 0) 
		exibicao[x][y] = qtd + '0';
	
	//Abre as casas se não houver
	else if (qtd == 0)
	{
		if (x > 0 && x < lin && y > 0 && y < lin)
			for (i = x - 1; i <= x + 1; i++)
				for (j = y - 1; j <= y + 1; j++)
					if (exibicao[i][j] == '*')
						exibicao[i][j] = ' ';
		
	}
	

	printf("Checando minas...\n");

}

void mostra_mina(int** campo, char** exibicao, int lin, int col)
{
	int i, j;

	system("clear");
	imprime_tabuleiro(exibicao, lin, col);

	printf("BOOOM! Você perdeu! :(\n\n");
	printf("Pressione enter para continuar\n");

	getchar();
	getchar();

	system("clear");
	//Marca a localizacao de todas as bombas
	for (i = 0; i < lin; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (campo[i][j]) exibicao[i][j] = 'x';
		}
	}

	imprime_tabuleiro(exibicao, lin, col);
	printf("Mais sorte na próxima!\n");
	
	getchar();
	getchar(); 
	
}
