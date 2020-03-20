#include <stdio.h>

int main()
{
	int i, j, lin, col, x = 0, y = 0;
	int mapa[1001][1001] = {0};
	
	//Lendo o tamanho da matriz
	scanf("%d %d", &lin, &col);
	
	//Lendo toda a matriz
	for (i = 1; i <= lin; ++i)
	{
		for (j = 1; j <= col; ++j)
		{
			scanf("%d", &mapa[i][j]);
		}
	}
	
	//Analisando os elementos da matriz
	for (i = 2; i < lin; ++i)
	{
		for (j = 2; j < col; ++j)
		{
			if (mapa[i][j] == 42)
			{
				if(7 == mapa[i-1][j-1] && mapa[i-1][j] == 7 && mapa[i-1][j+1] == 7  && mapa[i][j-1] == 7 && mapa[i][j+1] == 7 && mapa[i+1][j-1] == 7 && mapa[i+1][j] == 7 && mapa[i+1][j+1] == 7)
				{
					x = i;
					y = j;
				}
			}
		}
	}

	printf("%d %d\n", x, y);

	return 0;
}
