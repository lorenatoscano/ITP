#include "utils.h"

void jogo(int lin, int col, int bomb)
{
	int** campo; //Localizacao das bombas
	char** exibicao; //O que o jogador ve
	int** aux; //Marcação dos lugares verificados
	int i, j, x, y, perdeu = 0, ganhou = 0;
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

		// imprime_campo(campo, lin, col); //debug
		printf("(•‿•) Minas restantes: %d\n", bomb);
		//Imprime o tabuleiro para o usuario
		imprime_tabuleiro(exibicao, lin, col);

		//Le as coordenadas e a açao
		printf("Insira as coordenadas e a ação: \n(A - abrir | B - colocar ou retirar bandeira)\n");
		scanf("%d %d %c", &x, &y, &action);
		if (x > lin || x < 1 || y < 1 || y > col)
		{
			printf("Valores inválidos!\n");
			getchar();
			getchar(); 
		}
		else
		{
			//Subtrai 1 dos valores para fazer a correspondência com os indices da matriz
			switch(action)
			{
				case 'A':
					if (campo[x - 1][y - 1]) //perdeu
					{
						exibicao[x - 1][y - 1] = 'x';
						mostra_mina(campo, exibicao, lin, col);
						perdeu = 1;
					}	
					else
					{
						checa_mina(x - 1, y - 1, campo, exibicao, aux, lin - 1, col - 1);
					} 
					break;
				case 'B':
					if (exibicao[x - 1][y - 1] == '*')
					{
						exibicao[x - 1][y - 1] = 'B';
						bomb--;
					}
					else if (exibicao[x - 1][y - 1] == 'B')
					{
						exibicao[x - 1][y - 1] = '*';
						bomb++;
					}
					break;
				default: 
					printf("Opção inválida!\n");
					getchar();
					getchar(); 
			}
			ganhou = verifica_vitoria(exibicao, campo, lin, col);
		}

	} while(!perdeu && !ganhou);
}

