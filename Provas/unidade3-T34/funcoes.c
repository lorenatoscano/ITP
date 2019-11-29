#include "funcoes.h"

Time* carrega_dados(int* tam)
{
	FILE* arq = fopen("base.txt", "r");

	Time* vetor;
	char linha[1000], tail[1000];
	char* nome;
	int i, j, k, l;

	//Verifica se o arquivo existe
	if(arq == NULL)
	{
        return NULL;
    }
    else
    {
    	//Le a quantidade
    	fscanf(arq, "%d", tam);

    	//Cria o vetor
    	vetor = malloc(sizeof(Time) * *tam);

    	//Ignora a primeira linha
    	fgets(linha, 1000, arq);

    	//Le os times e guarda as informacoes
    	for (i = 0; i < *tam; i++)
    	{
    		fgets(linha, 1000, arq);

    		//Pega o nome
    		sscanf(linha, "%[^;]s", vetor[i].nome);

    		//Guarda o resto numa string auxiliar
			for(k=strlen(vetor[i].nome), l = 0; linha[k] != '\0'; k++, l++)
                tail[l] = linha[k];

            tail[l] = '\0';

            //Retira da auxiliar o restante das informacoes
			sscanf(tail, "; %d %d %d %d %d", &vetor[i].vit, &vetor[i].emp, &vetor[i].der, &vetor[i].gf, &vetor[i].gs);

			//Preenche os pontos e saldo de gols
			vetor[i].pont = vetor[i].vit * 3 + vetor[i].emp;
			vetor[i].sg = vetor[i].gf - vetor[i].gs;
    	}

    	fclose(arq);
    	return(vetor);
    }

}

void imprime_tabela(Time* camp, int tam)
{
	int i;
	ordena_times(camp, tam);
	
	printf("Tabela do campeonato:\n");
	printf("Nome\t\tPontos Jogos Vitorias Empates Derrotas Gols Pro Gols Contra Saldo de Gols\n");
	for (i = tam - 1; i > 0; i--)
	{
		imprime_time(camp[i]);
	}

	printf("\nTimes na zona da Libertadores:\n");
	for (i = tam - 1; i > tam - 7; i--)
	{
		printf("%s\n", camp[i].nome);
	}
	printf("\nTimes rebaixados:\n");
	for (i = 0; i < 4; i++)
	{
		printf("%s\n", camp[i].nome);
	}
}

void imprime_time(Time atual)
{
	int jogos;

	jogos = atual.vit + atual.emp + atual.der;

	printf("%s\t", atual.nome);
	printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", atual.pont, jogos, atual.vit, atual.emp, atual.der, atual.gf, atual.gs, atual.sg);
}

void ordena_times(Time* camp, int tam)
{
	Time sup;
	int i, j;

	//Ordena o vetor
		for (i = tam - 1; i > 0; i--)
		{
			for (j = 0; j < i; j++)
			{
				if (camp[j].pont > camp[j + 1].pont) //Verifica a qtd de pontos
				{
					sup = camp[j];
					camp[j] = camp[j + 1];
					camp[j + 1] = sup;
				}
				else if (camp[j].pont == camp[j + 1].pont)
				{
					if (camp[j].vit > camp[j + 1].vit) //Verifica a qtd de vitorias
					{
						sup = camp[j];
						camp[j] = camp[j + 1];
						camp[j + 1] = sup;
					}
					else if (camp[j].vit == camp[j + 1].vit)
					{
						if (camp[j].sg > camp[j + 1].sg) //Verifica o saldo de gols
						{
							sup = camp[j];
							camp[j] = camp[j + 1];
							camp[j + 1] = sup;
						}
					}
				}
				
			}
		}
}


