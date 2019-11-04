#include<stdio.h>

int fatorial(int numero)
{
	//Caso base: onde ela para. (Quando o numero for 1)
	if(numero == 1 || numero == 0)
		return 1;
	//Processamento: a logica do programa (a conta do fatorial)
	//Chamada recursiva: como eu uso a funcao para ir do valor que eu estou para o caso base
	else
		return numero*fatorial(numero-1);
}

void binario(int numero)
{
	//Caso base: numero = 1
	if(numero == 1)
		printf("1");
	else
	{
		binario(numero/2);
		printf("%d", numero%2);
	}
	//Processamento: imprimir o digito
	//Chamada recursiva: dividir o numero por 2

	
}

void troco(int valor, int* notas)
{
	int i;
	//Caso base: valor == 0
	if(valor == 0)
	{
		for(i = 6; i > 0; i--)
		{
			if(notas[i] > 0)
			{
				printf("%d notas de ", notas[i]);

				switch(i)
				{
					case 0: printf("1"); break;
					case 1: printf("2"); break;
					case 2: printf("5"); break;
					case 3: printf("10"); break;
					case 4: printf("20"); break;
					case 5: printf("50"); break;
					case 6: printf("100"); break;
				}
				printf("\n");
			}
		}
		printf("\n");
	}	
	else
	{
		//Processamento: verifica se cabe uma nota, adiciona ela no vetor
		//Chamada recursiva: chamar funcao retirando do valor da nota
		if(valor >= 100)
		{
			//Adiciona uma nota do tipo 100
			notas[6]++;
			//Chama a fucao para tentar mostar o restante do troco
			troco(valor-100, notas);
			//Resetar para o valor anterior
			notas[6]--;
		}
		if(valor >= 50)
		{
			//Adiciona uma nota do tipo 50
			notas[5]++;
			//Chama a fucao para tentar mostar o restante do troco
			troco(valor-50, notas);
			//Resetar para o valor anterior
			notas[5]--;
		}
		if(valor >= 20)
		{
			//Adiciona uma nota do tipo 20
			notas[4]++;
			//Chama a fucao para tentar mostar o restante do troco
			troco(valor-20, notas);
			//Resetar para o valor anterior
			notas[4]--;
		}
		if(valor >= 10)
		{
			//Adiciona uma nota do tipo 10
			notas[3]++;
			//Chama a fucao para tentar mostar o restante do troco
			troco(valor-10, notas);
			//Resetar para o valor anterior
			notas[3]--;
		}
		if(valor >= 5)
		{
			//Adiciona uma nota do tipo 5
			notas[2]++;
			//Chama a fucao para tentar mostar o restante do troco
			troco(valor-5, notas);
			//Resetar para o valor anterior
			notas[2]--;
		}
		if(valor >= 2)
		{
			//Adiciona uma nota do tipo 2
			notas[1]++;
			//Chama a fucao para tentar mostar o restante do troco
			troco(valor-2, notas);
			//Resetar para o valor anterior
			notas[1]--;
		}
		if(valor >= 1)
		{
			//Adiciona uma nota do tipo 1
			notas[0]++;
			//Chama a fucao para tentar mostar o restante do troco
			troco(valor-1, notas);
			//Resetar para o valor anterior
			notas[0]--;
		}
	}
	
}

int main()
{
	// int i, fat = 1;
	int num;
	int notas[7] = {0};

	scanf("%d", &num);

	troco(num, notas);

	// binario(num);
	// printf("\n");

	// printf("%d\n", fatorial(num));

	//Iterativo
	// for (i = 1; i < num; i++)
	// 	fat = fat*i;

	// printf("%d\n", fat);


	return 0;
}