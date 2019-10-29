#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, n, qtd; 

	scanf("%d", &n);

	while(n != 0)
	{
		qtd = 0;
		//Cria um vetor com o tamanho do numero de amostras
		int onda[n];

		//Le a amostra
		for (i = 0; i < n; ++i)
			scanf("%d", &onda[i]);


		//Verifica se há um pico
		for (i = 0; i < n; ++i)
		{	

			if(i == 0)
			{
	            if((onda[i] > onda[n-1] && onda[i] > onda[i+1]) || (onda[i] < onda[n-1] && onda[i] < onda[i+1]))
	            {
	                qtd++;
	            }
	        }
	        else
	        {
	            if(i == (n-1))
	            {
	            	if((onda[i] > onda[i-1] && onda[i] > onda[0]) || (onda[i] < onda[i-1] && onda[i] < onda[0]))
	               	{
	                	qtd++;
	               	}
	            }
	            else
	            {
	                if((onda[i] > onda[i-1] && onda[i] > onda[i+1]) || (onda[i] < onda[i-1] && onda[i] < onda[i+1]))
	                {
	                    qtd++;
	                }
	            }
	        }
		}
		printf("%d\n", qtd);
		//Le o proximo numero de amostras
		scanf("%d", &n);
	}
	// printf("%s\n", res);

	return 0;
}

		
