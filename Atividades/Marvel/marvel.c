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
			case 3: remove_hq(quadrinhos); break;
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
	system("clear");

	FILE* arq = fopen("marvel-data.txt", "r");
	
	int i = 0, j = 0, k, l;
	int tam, qtd, flag;
	char linha[1000], tail[1000], aux[1000], str[100];
	char* temp;

	if (arq == NULL) printf("Base de dados vazia!\n");
	else
	{
		printf("Carregando base de dados...\n");
		
		//Le linha por linha ate o final
		while(fgets(linha, 1000, arq) != NULL)
		{
			//Le o titulo
			sscanf(linha, "%[^;]s", quad[i].nome);

			//Guarda o resto numa string auxiliar
			for(k=strlen(quad[i].nome), l = 0; linha[k] != '\0'; k++, l++)
                tail[l] = linha[k];

            tail[l] = '\0';

            //Retira da auxiliar o restante das informacoes
			sscanf(tail, "; %d; %d-%d; %d;\n", &quad[i].num, &quad[i].mes, &quad[i].ano, &quad[i].lido);

			//Repete o processo pra guardar o resto da linha
			for(k=18, l = 0; tail[k] != '\0'; k++, l++)
                aux[l] = tail[k];
            aux[l - 1] = '\0';

			temp = strtok(aux, ",");
			j = 0;
			while(temp != NULL)
			{
				strcpy(quad[i].pers[j], temp);
				j++;
				temp = strtok(NULL, ",");
			}
			
			i++;
		}

		fclose(arq);
	}
	// tam = i;
	// //Imprime os dados apenas para verificacao
	// for(i = 0; i < tam; i++)
	// {
	// 	printf(">> Título da HQ %d: %s %d\n", i, quad[i].nome, quad[i].num);
	// 	printf(">> Data: %d/%d\n", quad[i].mes, quad[i].ano);
	// 	printf(">> Lido? %d\n", quad[i].lido);
	
	// 	printf(">> Personagens:\n");

	// 	for (j = 0; j < qtd; j++)
	// 	{
	// 		printf("> %s\n", quad[i].pers[j]);
	// 	}
	// 	printf("\n");
	// }

	// getchar();
	// getchar();
}

void adiciona(HQ quad[200])	
{
	system("clear");

	FILE* arq = fopen("marvel-data.txt", "a");

	HQ novo;
	int i = 0, ins = 0, res, qtd;
	
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
			fprintf(arq, "%s; ", novo.nome);

			//Faz o tratamento para imprimir os numeros com duas casas
			if (novo.num < 10) 
			{
				if (novo.mes < 10)
					fprintf(arq, "0%d; 0%d-%d; %d; ", novo.num, novo.mes, novo.ano, novo.lido);
				else	
					fprintf(arq, "0%d; %d-%d; %d; ", novo.num, novo.mes, novo.ano, novo.lido);
			}
			else if (novo.mes < 10) 
				fprintf(arq, "%d; 0%d-%d; %d; ", novo.num, novo.mes, novo.ano, novo.lido);
			else 
				fprintf(arq, "%d; %d-%d; %d; ", novo.num, novo.mes, novo.ano, novo.lido);
			
			for (i = 0; i < qtd; ++i)
			{
				fprintf(arq, "%s,", novo.pers[i]);
			}
			fprintf(arq, "\n");

			printf("Cadastro feito com sucesso!\n");
		}
		fclose(arq);
	}
	
	getchar();
	getchar();

	system("clear");
}

void remove_hq(HQ quad[200])
{
	system("clear");

	FILE* arq = fopen("marvel-data.txt", "r");
	FILE* novo = fopen("marvel-tmp.txt", "w");

	HQ del;
	int i, ok = 0;
	int num;
	char linha[1000], tit[200];

	if (arq == NULL || novo == NULL) printf("Erro na abertura do arquivo!\n");
	else
	{
		carrega_base(quad);

		printf("Digite as informações do quadrinho que deseja remover:\n\n");
		printf("Título:\n");
		scanf(" %[^\n]s", del.nome);
		printf("Número:\n");
		scanf("%d", &del.num);

		printf("Deletar %s %d\n", del.nome, del.num);

		while(fgets(linha, 1000, arq) != NULL)
		{
			//Leio o titulo e o numero no arquivo
			sscanf(linha, "%[^;]; %d", tit, &num);

			//Se for diferente do del, copio para o novo
			if(strcmp(tit, del.nome) != 0 && num != del.num)
				fprintf(novo, "%s", linha);
			//Senao, informo que a remocao ocorreu
			else
				ok = 1;

		}
		
		fclose(arq);
        fclose(novo);

        if(ok == 1)
            printf("Remocao realizada com sucesso!\n");
        else
            printf("Quadrinho nao encontrado!\n");

        system("mv marvel-tmp.txt marvel-data.txt");
	}

	getchar();
	getchar();

	system("clear");
}