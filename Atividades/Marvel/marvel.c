#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
	char nome[100];
	int num;
	int mes, ano;
	int lido;
	char pers[50][100];
} HQ;


void carrega_base(HQ*);
void adiciona(HQ*);
void remove_hq(HQ*);
void busca(HQ*);
void consulta(HQ*);
void marca_lido(HQ*);

int main()
{
	system("clear");

	int option = 0;
	HQ* quadrinhos;

	quadrinhos = calloc(200, sizeof(HQ));

	while (option != 7)
	{

		printf("MENU DE OPÇÕES:\n");
		printf("1 - Carregar base de dados\n");
		printf("2 - Adicionar um quadrinho\n");
		printf("3 - Remover um quadrinho\n");
		printf("4 - Consulta um quadrinho\n");
		printf("5 - Consultas Gerais\n");
		printf("6 - Marcar como lido:\n");
		printf("7 - Sair​\n");

		scanf("%d", &option);

		switch (option)
		{
			case 1: carrega_base(quadrinhos); break;
			case 2: adiciona(quadrinhos); break;
			// case 3: remove_hq(quadrinhos); break;
			// case 4: busca(quadrinhos); break;
			// case 5: consulta(quadrinhos); break;
			// case 6: marca_lido(quadrinhos); break;
			case 7: break;
			default: printf("Opção inválida!\n");
		}
	}

	system("clear");

	return 0;
}

void carrega_base(HQ quad[200])
{
	FILE* arq = fopen("marvel-data.txt", "r");
	int i = 0, j = 0, k, l, tam, qtd;
	char linha[1000];
	char aux[200];

	if (arq == NULL) printf("Base de dados vazia!\n");
	else
	{
		printf("Carregando base de dados...\n");

		//Le as informacoes do arquivo e armazena no vetor quad
		while(fscanf(arq, "%[^\n]s", quad[i].nome) != EOF)
		{
			fscanf(arq, "%d %d %d %d\n", &quad[i].num, &quad[i].mes, &quad[i].ano, &quad[i].lido);
			
			//Guarda a linha com os personagens para retirar cada um
			// fscanf(arq, "%[\n]s", linha);
			// do
			// {
			// 	sscanf(linha, "%[^;]s", quad[i].pers[j]);
			// 	j++;
			// } while(sscanf(linha, "%s", aux) != '\0');
			i++;

		}
	}

	tam = i;
	qtd = j;

	//Imprime os dados apenas para verificacao
	// for(i = 0; i < tam; i++)
	// {
	// 	printf(">> Título da HQ %d: %s %d\n", i, quad[i].nome, quad[i].num);
	// 	printf(">> Data: %d/%d\n", quad[i].mes, quad[i].ano);
	// 	printf(">> Lido? %d\n\n", quad[i].lido);
	
	// 	// printf(">> Personagens:\n");

	// 	// for (j = 0; j < qtd; j++)
	// 	// {
	// 	// 	printf("> %s\n", quad[i].pers[j]);
	// 	// }
	// 	// printf("\n");
	// }

	// getchar();
	// getchar();
}

void adiciona(HQ quad[200])	
{
	system("clear");
	HQ novo;
	int i = 0, ins = 0, qtd, res;
	FILE* arq = fopen("marvel-data.txt", "a");
	
	if (arq == NULL) printf("Erro na abertura do arquivo!\n");
	else
	{
		
		carrega_base(quad);

		printf("Digite as informações do quadrinho que deseja adicionar:\n\n");
		printf("Título:\n");
		scanf(" %[^\n]s", novo.nome);
		printf("Número:\n");
		scanf("%d", &novo.num);

		//Verifica se o quadrinho ja existe
		for (i = 0; i < 200; i++)
		{
			res = strcmp(novo.nome, quad[i].nome);
			if (res == 0)
			{
				if (quad[i].num == novo.num)
				{
					printf("Esse quadrinho já está cadastrado!\n");
					ins = 1;
					break;
				}
			}
		}

		//Se nao foi cadastrado, le as demais informacoes
		if (ins == 0)
		{
			printf("Mês e ano de publicação:\n");
			scanf("%d %d", &novo.mes, &novo.ano);

			novo.lido = 0;

			printf("Quantos personagens deseja adicionar?\n");
			scanf("%d", &qtd);
			printf("Insira os personagens separados por enter:\n");
			for (i = 0; i < qtd; ++i)
				scanf(" %[^\n]s", novo.pers[i]);

			//Insere as informações no arquivo:
			fprintf(arq, "%s\n", novo.nome);
			fprintf(arq, "%d %d %d %d\n", novo.num, novo.mes, novo.ano, novo.lido);
			for (i = 0; i < qtd; ++i)
			{
				fprintf(arq, "%s;", novo.pers[i]);
			}
			fprintf(arq, "\n");

		}
	}
	
	getchar();
	getchar();

	system("clear");
}