#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int i;
	#muitobom
	srand(time(NULL));

	for (i = 0; i < 10; ++i)
	{
		printf("%d\n", rand()%10+1);
	}

	return 0;
}
