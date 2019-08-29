#include <stdio.h> 
#include <time.h> 
#include <stdlib.h> 
#include <conio.h> 
#include <math.h>
#include <float.h>
#include <stdbool.h>
#include <windows.h>

int Divisors(int i)
{
	int j, c = 0;
	for (j = 1;j <= i;j++)
	{
		if (i % j == 0)
			c++;
	}
	return c;
}

void Mersenne(unsigned long long int Value)
{
	int i, z, x, f, power;
	for (i = 1;i <= Value;i++)
	{
		z = Divisors(i);
		if (z == 2)
		{
			for (x = 1;x <= i;x++)
			{
				power = (pow(2, x)) - 1;
				f = Divisors(x);
				if (f == 2 && i == power)
					printf("%d, ", i);
			}
		}
	}
}

int Core()
{
	printf("Mersenne Primes: \n");
	unsigned long long int Value = 9999999999;
	Mersenne(Value);
}

int main()
{
	Core();
	return 0;
}