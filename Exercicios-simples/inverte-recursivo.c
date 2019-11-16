#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inverte()
{
	char letra;

	scanf("%c", &letra);

	if (letra != '\n')
		inverte();
	printf("%c", letra);
}

int main()
{
	inverte();
	printf("\n");


	return 0;
}