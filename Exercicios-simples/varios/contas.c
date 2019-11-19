#include <stdio.h>
//Calculadora - implementações
void le_entrada(int* n1, int* n2)
{
	printf("Digite os dois numeros:\n");

	scanf("%d %d", n1, n2);
}

void adicao()
{
	int n1, n2;
	le_entrada(&n1, &n2);

	printf("Resultado: %d\n", n1+n2);
}
void subtracao()
{
	int n1, n2;
	le_entrada(&n1, &n2);

	printf("Resultado: %d\n", n1-n2);
}
void multiplicacao()
{
	int n1, n2;
	le_entrada(&n1, &n2);

	printf("Resultado: %d\n", n1*n2);
}
void divisao()
{
	int n1, n2;
	le_entrada(&n1, &n2);

	if(n2 == 0) printf("Divisão por zero!\n");
	else printf("Resultado: %d\n", n1+n2);
}
