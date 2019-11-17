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
	printf(">> Campo por debaixo dos panos:\n");
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
	printf("\n>> Visão do usuario:\n");
}

void checa_mina(int x, int y, int** campo, char** exibicao, int** aux, int lin, int col)
{
	int i, j, qtd = 0;

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
		{
			qtd += campo[x + 1][y + 1];
			qtd += campo[x][y + 1];
		}
		if (y != 0)
		{
			qtd += campo[x + 1][y - 1];
			qtd += campo[x][y - 1];
		}

	}

	//Se tiver minas, exibe a quantidade
	if(qtd > 0) 
	{
		exibicao[x][y] = qtd + '0';
		return;
	}
		
	//Abre as casas se não tiver
	else if (qtd == 0)
	{

		if (exibicao[x][y] == '*')
		{
			exibicao[x][y] = ' ';
		}	
	}

	//Marca essas coordenadas como verificadas
	aux[x][y] = 1;
	
	if (qtd == 0)
	{
		//Chamada recursiva para verificar as outras casas
		if (x != 0) 
		{
			if (!aux[x - 1][y]) checa_mina(x - 1, y, campo, exibicao, aux, lin, col);
			if (y != 0)
			{
				if (!aux[x - 1][y - 1]) checa_mina(x - 1, y - 1, campo, exibicao, aux, lin, col);
				if (!aux[x][y - 1]) checa_mina(x, y - 1, campo, exibicao, aux, lin, col);
			}
			if (y != col) 
			{
				if (!aux[x - 1][y + 1]) checa_mina(x - 1, y + 1, campo, exibicao, aux, lin, col);
				if (!aux[x][y + 1]) checa_mina(x, y + 1, campo, exibicao, aux, lin, col);
			}
		}
		if (x != lin) 
		{
			if (!aux[x + 1][y]) checa_mina(x + 1, y, campo, exibicao, aux, lin, col);
			if (y != col)
			{ 
				if (!aux[x + 1][y + 1]) checa_mina(x + 1, y + 1, campo, exibicao, aux, lin, col);
				if (!aux[x][y + 1]) checa_mina(x, y + 1, campo, exibicao, aux, lin, col);
			}
			if (y != 0)
			{
				if (!aux[x + 1][y - 1]) checa_mina(x + 1, y - 1, campo, exibicao, aux, lin, col);
				if (!aux[x][y - 1]) checa_mina(x, y - 1, campo, exibicao, aux, lin, col);
			}
		}
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
			if (campo[i][j]) 
				exibicao[i][j] = 'x';
			else if (!campo[i][j] && exibicao[i][j] == 'B')
				exibicao[i][j] = '%';
		}
	}

	imprime_tabuleiro(exibicao, lin, col);
	printf("\nMais sorte na próxima!\n");
	getchar();
	getchar(); 
	
}

int verifica_vitoria(char** exibicao, int** campo, int lin, int col)
{
	int ganhou = 1;
	int i, j;

	//Se alguma casa sem bomba nao foi revelada
	for (i = 0; i < lin; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (!campo[i][j] && (exibicao[i][j] == '*' || exibicao[i][j] == 'B'))
			{
				ganhou = 0;
				break;
			}

		}
	}

	if (ganhou) 
	{
		printf("PARABÉNS! VOCÊ GANHOU!");
		return 1;
	}
	else return 0;
}
