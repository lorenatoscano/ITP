#include <stdio.h>
#include <stdlib.h>

#define LIN 5
#define COL 5

struct Teste
{
	int bixiga;
	float taboca;
	double pipoca;
	char bolota[1000];
};

union Test
{
	int bixiga;
	float taboca;
	double pipoca;
	char bolota[1000];
};

int main()
{
	struct Teste var1 = {4, 2.5, 3.21, "Lerooooooy!"};
	union Test var2 = {4};
	int i;
	int** mat;
	int* mat2;
	int mat3[LIN][COL];

	//Alocando matrizes
	mat = malloc(sizeof(int*) * LIN);

	for (i = 0; i < LIN; i++)
		mat[i] = malloc(sizeof(int) * COL);


	printf("Comparando tamanhos:\n");
	printf("Tamanho do struct: %d\n", (int)sizeof(var1));
	printf("Tamanho do union: %d\n\n", (int)sizeof(var2));

	printf("Imprimindo os valores:\n");
	printf("Struct: %d, %f, %lf, %s\n", var1.bixiga, var1.taboca, var1.pipoca, var1.bolota);
	printf("Union: %d, %f, %lf, %s\n\n", var2.bixiga, var2.taboca, var2.pipoca, var2.bolota);

	return 0;
}