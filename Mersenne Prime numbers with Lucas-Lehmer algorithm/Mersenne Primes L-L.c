#include <stdio.h> 
#include <time.h> 
#include <stdlib.h> 
#include <conio.h> 
#include <math.h>
#include <float.h>
#include <stdbool.h>
#include <windows.h>

int IsPrime(int p) {
	if (p == 2) return 1;
	else if (p <= 1 || p % 2 == 0) return 0;
	else {
		for (int i = 3; i < p; i++)
		{
			if (p % i == 0)
				return 0;
		}
		return 1;
	}
}
int LucasLehmer(int p)
{
	if (p == 2) return 1;
	else if (p <= 1 || p % 2 == 0) return 0;
	unsigned long long int s = 4;
	unsigned long long M = pow(2, p) - 1;
	for (int i = 3; i <=p; i++)
	{
		s = (s * s - 2) % M;
	}
	if (s == 0)
		return 1;
	else
		return 0;
}


int Core()
{
	printf("Mersenne Primes: \n");
	int p = 1;
	while (1)
	{
		if (IsPrime(p))
		{
			if(LucasLehmer(p))
			printf("%d, ", p);
		}
		p++;
	}

}

int main()
{

	Core();
	return 0;
}