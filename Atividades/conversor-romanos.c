#include<stdio.h>

int main()
{
	int n, c, d, u;

	scanf("%d", &n);
	
	c = n / 100;
	n %= 100;
	d = n / 10;
	u = n % 10;		


	switch(c)
	{
		case 9: printf("CM"); break;
		case 8: printf("DCCC"); break;
		case 7: printf("DCC"); break;
		case 6: printf("DC"); break;
		case 5: printf("D"); break;
		case 4: printf("CD"); break;
		case 3: printf("CCC"); break;
		case 2: printf("CC"); break;
		case 1: printf("C"); break;
	}

	switch(d)
	{
		case 9: printf("XC"); break;
		case 8: printf("LXXX"); break;
		case 7: printf("LXX"); break;
		case 6: printf("LX"); break;
		case 5: printf("L"); break;
		case 4: printf("XL"); break;
		case 3: printf("XXX"); break;
		case 2: printf("XX"); break;
		case 1: printf("X"); break;
	}
	switch(u)
	{
		case 9: printf("IX"); break;
		case 8: printf("VIII"); break;
		case 7: printf("VII"); break;
		case 6: printf("VI"); break;
		case 5: printf("V"); break;
		case 4: printf("IV"); break;
		case 3: printf("III"); break;
		case 2: printf("II"); break;
		case 1: printf("I"); break;
	}

	printf("\n");

	return 0;
}
