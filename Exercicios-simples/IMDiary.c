#include <stdlib.h>
#include <stdio.h>

typedef struct
{
	int hi, hf, mi, mf;
	char descricao[105];
} Tarefa;

int compara_tarefa(cost void* a, const void* b)
{
	Tarefa h1, h2;

	h1 = *((Tarefa*)a);
	h2 = *((Tarefa*)b);

	if(h1.hi == h2.hi)
	{
		return h1.mi - h2.mi;
	}
	else
	{
		return h1.hi - h2.hi;
	}
}

int main()
{
	Tarefa agenda[105];
	int tasks, i, horai, horaf, mini, minf;

	scanf("%d", &tasks);

	for(i = 0; i < tasks; i++)
	{
		scanf("%d:%d %d:%d", &agenda[i].hi, &agenda[i].mi, &agenda[i].hf, &agenda[i].mf);
		scanf(" %[\n]s", agenda[i].descricao);
	}

	qsort(agenda, tasks, sizeof(Tarefa), compara_tarefa);

	printf("Consultas\n");

	while(scanf("%d:%d %d:%d", &horai, &mini, &horaf, &minf) != EOF)
	{
		
	}

	return 0;
}