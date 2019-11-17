#include "jogo.h"
#include "utils.h"

void jogo(int lin, int col, int bomb)
{
	int** campo; //Localizacao das bombas
	char** exibicao; //O que o jogador ve
	int** aux; //Marcação dos lugares verificados
	int i, j, x, y, ok = 1, res;
	char action;

	//Aloca as matrizes
	campo = malloc(sizeof(int*) * lin);
	for (i = 0; i < lin; i++)
		campo[i] = malloc(sizeof(int) * col);

	exibicao = malloc(sizeof(char*) * lin);
	for (i = 0; i < lin; i++)
		exibicao[i] = malloc(sizeof(char) * col);

	aux = calloc(lin, sizeof(int*));
	for (i = 0; i < lin; i++)
		aux[i] = calloc(col, sizeof(int));


	//Preenche as matrizes
	prepara_campo(campo, lin, col, bomb);
    prepara_exibicao(exibicao, lin, col);

    //Executa o jogo
	do
	{
		system("clear");

		imprime_campo(campo, lin, col);
		//Imprime o tabuleiro para o usuario
		imprime_tabuleiro(exibicao, lin, col);

		//Le as coordenadas e a açao
		printf("Insira as coordenadas e ação que deseja fazer (A para abrir e B para marcar como bomba):\n");
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
						checa_mina(x - 1, y - 1, campo, exibicao, aux, lin, col);
					break;
				case 'B':
					exibicao[x - 1][y - 1] = 'B';
					break;
				default: 
					printf("Opção inválida!\n");
					getchar();
					getchar(); 
			}
		}

	} while(ok);
}

