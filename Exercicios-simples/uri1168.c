#include <stdio.h>
#include <math.h>

int firstDigit(int n);
int calculaQtd(unsigned long long int val)
{
	int soma = 0;
	int digits = floor (log10 (val)) + 1;
	unsigned long int pow10 = 10;
	for (int i = 0; i < digits; ++i){
		int current = firstDigit((val % pow10));
		if (current == 6 || current ==  9 || current == 0)
			soma+= 6;
		else if (current == 2 || current == 3 || current == 5)
			soma+= 5;
		else if ( current == 1 || current == 4)
			soma+= current == 1 ? 2 : 4;
		else if (current == 0)
			soma+=6;
		else
			soma+= current == 7 ? 3 : 7;

		pow10*=10;
	}
	return soma;
}

int firstDigit(int n) 
{ 
    while (n >= 10)  
        n /= 10; 
    return n; 
} 


int main()
{
	int n, i, leds;
	unsigned long long int valor;

	scanf("%d", &n);

	for (i = 0; i < n; ++i)
	{
		scanf("%lld", &valor);
		leds = calculaQtd(valor);
		printf("%d leds\n", leds);
	}
	return 0;
}
